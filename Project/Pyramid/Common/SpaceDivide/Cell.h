/**
* @file		Cell.h
* @brief	8���؂��\�z������
* @author	S.OIKAWA
* @date		2017.01.09
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

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
			/// 8���؂��\�z������
			/// </summary>
			class Cell
			{
				friend class Octree;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Cell() = default;
				~Cell() = default;

				Cell(const Cell&) = default;
				Cell(Cell&&) = default;

				Cell& operator=(const Cell&) = default;
				Cell& operator=(Cell&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				void Register(OctreeRegistrableObject&, Octree*);

				void UnRegister(OctreeRegistrableObject&, Octree*);

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_R_ONLY(
					m_pHead,
					pHead,
					OctreeRegistrableObject*);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				OctreeRegistrableObject*	m_pHead = nullptr;		
				//list����12B�Ō��E�܂ŃT�C�Y�}����������Object�Ƀ��X�g������
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------