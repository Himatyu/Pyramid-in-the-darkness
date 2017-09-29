/**
* @file		Octree.h
* @brief	������
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
			/// ������.
			/// �ÓI�ɗp�ӂ���.
			/// �o�^���ꂽ�I�u�W�F�N�g�ɑ΂��ďՓ˂̉\�����X�g���X�V����
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
				/// �����؂̍\�z���s��
				/// </summary>
				void Initialize(const unsigned _Level,const Common::Diagram::AABB& _Volume);

				/// <summary>
				/// �I�u�W�F�N�g��o�^����
				/// </summary>
				void Register(OctreeRegistrableObject& _Object);

				/// <summary>
				/// �I�u�W�F�N�g�̓o�^����������
				/// </summary>
				void UnRegister(OctreeRegistrableObject& _Object);

				/// <summary>
				/// ��Ԃւ̍ēo�^���s��
				/// </summary>
				void ReRegister(OctreeRegistrableObject& _Object);

				/// <summary>
				/// �o�^���ꂽ�I�u�W�F�N�g�̊֌W���X�V����
				/// </summary>
				void UpdataRelationsBetweenRegisteredObjects();

				/// <summary>
				/// ���z�A�h���X��null�ȊO�ɐ^��Ԃ�
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