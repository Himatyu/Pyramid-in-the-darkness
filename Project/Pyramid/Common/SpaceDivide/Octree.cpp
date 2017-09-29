/**
* @file		Octree.cpp
* @brief	八分木
* @author	S.OIKAWA
* @date		2017.01.09
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Octree.h"
#include"Cell.h"
#include"OctreeRegistrableObject.h"
#include"Vector3.h"
#include"Estd.h"
#include"../Constant.h"
#include<cmath>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid;
namespace
{
	DWORD BitSpaceInsert(BYTE _data)
	{
		DWORD	result = _data;
		result = (result | result << 8) & 0x0000f00f;
		result = (result | result << 4) & 0x000c30c3;
		result = (result | result << 2) & 0x00249249;
		return result;
	}

}

namespace Pyramid
{
	namespace Common
	{
		namespace SpaceDivide
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Octree::Octree()
			{
				auto pArray =
					new int[m_VirtualBitSignatures.size()];
				int it = 0;
				for (auto& _ : m_VirtualBitSignatures)
				{
					_ = pArray+it++;
				}
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			Octree::~Octree()
			{
				SAFE_DELETE_ARRAY(*m_pCells.data());
				SAFE_DELETE_ARRAY(*m_VirtualBitSignatures.data());
			}

			//-----------------------------------------------------------
			// Initialize
			//-----------------------------------------------------------
			void Octree::Initialize(
				const unsigned _level,
				const Common::Diagram::AABB & _volume)
			{
				if (Constant::OctreeMaxLevel <= _level)
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "八分木に規定レベル以上の分割要求");
				}

				m_Level = _level;
				m_Volume = _volume;
				m_VolumeSize = _volume.Max - _volume.Min;
				m_CellSize = 
					m_VolumeSize / (static_cast<float>(_level * 2));

				m_CellCountOfLevel.reserve(_level + 1);
				m_CellCountOfLevel.resize(_level + 1);

				m_CellCountOfLevel[0] = 1;
				auto it = m_CellCountOfLevel.begin() + 1;
				for (; m_CellCountOfLevel.end() != it; it++)
				{
					*it = *(it - 1) * 8;
				}

				m_CellNum =
					Utility::Estd::accumulate(m_CellCountOfLevel, 0);
				auto pCells = new Cell[m_CellNum];
				m_pCells.reserve(m_CellNum);
				m_pCells.resize(m_CellNum);

				int i = 0;
				for (auto& _ : m_pCells)
				{
					_ = &pCells[i++];
				}
			}

			//-----------------------------------------------------------
			// Register
			//-----------------------------------------------------------
			void Octree::Register(
				OctreeRegistrableObject & _Object)
			{
				_Object.Morton = ConvertAABBToMortonNumber(
					_Object.ObjectVolume.CalculatWorldVolume());

				if (_Object.Morton > m_CellNum)
				{
					return;
				}

				m_pCells[_Object.Morton]->Register(_Object, this);
				SetVirtualBitSignatureInHigher(_Object.Morton, true);
			}

			//-----------------------------------------------------------
			// UnRegister
			//-----------------------------------------------------------
			void Octree::UnRegister(OctreeRegistrableObject & _Object)
			{
				if (_Object.Morton > m_CellNum)
				{
					return;
				}
				m_pCells[_Object.Morton]->UnRegister(_Object, this);
				SetVirtualBitSignatureInHigher(_Object.Morton, false);
				_Object.pCell = nullptr;

			}

			//-----------------------------------------------------------
			// ReRegister
			//-----------------------------------------------------------
			void Octree::ReRegister(OctreeRegistrableObject & _Object)
			{
				m_pCells[_Object.Morton]->UnRegister(_Object, this);
				SetVirtualBitSignatureInHigher(_Object.Morton, false);
				_Object.pCell = nullptr;

				_Object.Morton = ConvertAABBToMortonNumber(
					_Object.ObjectVolume.CalculatWorldVolume());

				if (_Object.Morton > m_CellNum)
				{
					return;
				}

				m_pCells[_Object.Morton]->Register(_Object, this);
				SetVirtualBitSignatureInHigher(_Object.Morton, true);
			}

			//-----------------------------------------------------------
			// UpdataRelationsBetweenRegisteredObjects
			//-----------------------------------------------------------
			void Octree::UpdataRelationsBetweenRegisteredObjects()
			{
				//上位空間に所属しているオブジェクトをスタックに詰む
				std::list<OctreeRegistrableObject*> Stack;
				//ルート空間から更新を始める
				RecurrenceUpdataRelations(0, Stack);
			}

			//-----------------------------------------------------------
			// RecurrenceUpdataRelations
			//-----------------------------------------------------------
			void Octree::RecurrenceUpdataRelations(
				DWORD _index, std::list<OctreeRegistrableObject*>& _hiLevelStack)
			{
				//現セルをリスト化 毎回FOR回すのが無駄くさい
				std::list<OctreeRegistrableObject*> CellObjectStack;
				std::list<OctreeRegistrableObject*> StackOfRootToindex(_hiLevelStack);

				auto pIt = m_pCells[_index]->pHead;
				if (IsEffectiveAddress(pIt))
				{
					do
					{
						CellObjectStack.push_back(pIt);
						pIt = pIt->pNext;
					}
					while (IsEffectiveAddress(pIt));

					//順序を維持したいからmerge使わない
					for (auto& _ : CellObjectStack)
					{
						StackOfRootToindex.push_back(_);
					}

					//現セルを処理
					pIt = m_pCells[_index]->pHead;
					while (IsEffectiveAddress(pIt))
					{
						pIt->SameSpaceList = StackOfRootToindex;
						pIt->SameSpaceList.remove(pIt);

						for (auto& _ : _hiLevelStack)
						{
							_->SameSpaceList.push_back(pIt);
						}

						pIt = pIt->pNext;
					}
				}

				auto bitData =
					FetchBitSignatureIndex(m_pCells[_index]->pHead);

				if (bitData)
				{
					DWORD NextIndex;
					for (int i = 0; i < 8; i++)
					{
						if (!(bitData & 0b1 << (7 - i)))
						{
							continue;
						}
						NextIndex = _index * 8 + 1 + i;
						if (m_CellNum > NextIndex)
						{
							RecurrenceUpdataRelations(NextIndex, StackOfRootToindex);
						}
					}
				}
				//兄弟に移動する時に自身のCell情報を削除
				auto stackSize = CellObjectStack.size();
				for (unsigned i = 0; i < stackSize; i++)
				{
					StackOfRootToindex.pop_back();
				}
			}

			//-----------------------------------------------------------
			// ConvertAABBToMortonNumber
			//-----------------------------------------------------------
			DWORD Octree::ConvertAABBToMortonNumber(
				Common::Diagram::AABB & _aabb)
			{
				auto minMorton =
					ConvertPositionToMortonNumber(_aabb.Min);
				auto maxMorton =
					ConvertPositionToMortonNumber(_aabb.Max);

				auto exor = minMorton ^ maxMorton;
				unsigned hiLevel = 1;	//レベルは1から始まる
				for (unsigned i = 0; i < m_Level; i++)
				{
					if ((exor >> (i * 3)) & 0b111)
					{
						hiLevel = i + 1;
					}
				}

				//minにした理由はない
				DWORD morton = minMorton >> (hiLevel * 3);

				//0ルートからデータまでのオフセット
				DWORD headOffset =
					(m_CellCountOfLevel[m_Level - hiLevel] - 1) / 7;

				morton += headOffset;
				if (headOffset > m_CellNum)
				{
					return 0xffffffff;
				}
				return morton;
			}

			//-----------------------------------------------------------
			// ConvertPositionToOctreeIndex
			//-----------------------------------------------------------
			DWORD Octree::ConvertPositionToMortonNumber(
				const Utility::Vector3 & _pos)
			{
				auto treeX = (BYTE)((_pos.X - m_Volume.Min.X) / m_CellSize.X);
				auto treeY = (BYTE)((_pos.Y - m_Volume.Min.Y) / m_CellSize.Y);
				auto treeZ = (BYTE)((_pos.Z - m_Volume.Min.Z) / m_CellSize.Z);

				auto result =
					BitSpaceInsert(treeX) |
					BitSpaceInsert(treeY) << 1 |
					BitSpaceInsert(treeZ) << 2;
				return result;
			}

			//-----------------------------------------------------------
			// ConvertIndexToVirtualBitSignature
			//-----------------------------------------------------------
			int * Octree::ConvertIndexToVirtualBitSignature(unsigned char _data)
			{
				return m_VirtualBitSignatures[_data];
			}

			//-----------------------------------------------------------
			// IsEffectiveAddress : 有効なアドレスか確認する
			//-----------------------------------------------------------
			bool Octree::IsEffectiveAddress(OctreeRegistrableObject * _pObj)
			{
				auto pInt = reinterpret_cast<int*>(_pObj);
				if (
					!_pObj ||
					(m_VirtualBitSignatures[255] >= pInt &&
						m_VirtualBitSignatures[0] <= pInt)
					)
				{
					return false;
				}

				return true;
			}

			//-----------------------------------------------------------
			// FetchBitSignatureIndex : OctreeRegistrableObject*から仮想配列の添字を取得
			//-----------------------------------------------------------
			unsigned char Octree::FetchBitSignatureIndex(OctreeRegistrableObject * _pObj)
			{
				if (!_pObj)
				{
					return 0;
				}

				auto pSignatur =
					IsEffectiveAddress(_pObj) ?
					_pObj->pLast->pNext : _pObj;

				auto pInt = pSignatur ?				//pNextがnullの場合がある
					reinterpret_cast<int*>(pSignatur) : 0;

				return pInt ?
					pInt - m_VirtualBitSignatures[0] :
					0;
			}

			//-----------------------------------------------------------
			// SetVirtualBitSignatureHigher : 上位レベル仮想アドレスのフラグを操作する
			//-----------------------------------------------------------
			void Octree::SetVirtualBitSignatureInHigher(DWORD _baseMorton, bool _isOn)
			{
				while (true)
				{
					auto index = (_baseMorton - 1) & 0b111;
					_baseMorton = (_baseMorton - 1) >> 3;
					if (_baseMorton >= m_CellNum)
					{
						break;
					}

					auto& pLast =
						IsEffectiveAddress(m_pCells[_baseMorton]->m_pHead) ?
						m_pCells[_baseMorton]->m_pHead->m_pNext :
						m_pCells[_baseMorton]->m_pHead;


					auto Signature = 0b1 << (7 - index);
					auto bitData = FetchBitSignatureIndex(m_pCells[_baseMorton]->m_pHead);
					bitData = _isOn ?
						bitData | Signature :
						bitData & ~Signature;
					auto virtualSignature = ConvertIndexToVirtualBitSignature(bitData);
					pLast = reinterpret_cast<decltype(pLast)>(virtualSignature);
				}
			}

		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------