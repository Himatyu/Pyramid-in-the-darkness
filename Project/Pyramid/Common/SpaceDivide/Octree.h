/**
* @file		Octree.h
* @brief	八分木
* @author	S.OIKAWA
* @date		2017.01.09
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Diagram/AABB.h"
#include"Vector3.h"
#include"singleton.h"
#include<list>
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		namespace SpaceDivide
		{
			class Cell;
			class OctreeRegistrableObject;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Common
	{
		namespace SpaceDivide
		{
			/// <summary>
			/// 八分木.
			/// 静的に用意する.
			/// 登録されたオブジェクトに対して衝突の可能性リストを更新する
			/// </summary>
			class Octree
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Octree();
				~Octree();

				Octree(const Octree&) = default;
				Octree(Octree&&) = default;

				Octree& operator=(const Octree&) = default;
				Octree& operator=(Octree&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				
				/// /// <summary>
				/// 八分木の構築を行う
				/// </summary>
				void Initialize(const unsigned _Level,const Common::Diagram::AABB& _Volume);

				/// <summary>
				/// オブジェクトを登録する
				/// </summary>
				void Register(OctreeRegistrableObject& _Object);

				/// <summary>
				/// オブジェクトの登録を解除する
				/// </summary>
				void UnRegister(OctreeRegistrableObject& _Object);

				/// <summary>
				/// 空間への再登録を行う
				/// </summary>
				void ReRegister(OctreeRegistrableObject& _Object);

				/// <summary>
				/// 登録されたオブジェクトの関係を更新する
				/// </summary>
				void UpdataRelationsBetweenRegisteredObjects();

				/// <summary>
				/// 仮想アドレスとnull以外に真を返す
				/// </summary>
				bool IsEffectiveAddress(OctreeRegistrableObject*);
					
			private:
				void RecurrenceUpdataRelations(
					DWORD _index,std::list<OctreeRegistrableObject*>& _hiLevelStack);
				DWORD ConvertAABBToMortonNumber(Common::Diagram::AABB&);
				DWORD ConvertPositionToMortonNumber(const Utility::Vector3&);
				int*  ConvertIndexToVirtualBitSignature(unsigned char);
				unsigned char FetchBitSignatureIndex(OctreeRegistrableObject*);
				void SetVirtualBitSignatureInHigher(DWORD _baseMorton, bool _isOn);

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion
			private:

#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				Common::Diagram::AABB			m_Volume;
				Utility::Vector3		m_VolumeSize;
				Utility::Vector3		m_CellSize;
				unsigned				m_Level;
				unsigned long			m_CellNum;
				std::vector<unsigned>	m_CellCountOfLevel;
				std::vector<Cell*>		m_pCells;
				std::array<int*,256>	m_VirtualBitSignatures;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------