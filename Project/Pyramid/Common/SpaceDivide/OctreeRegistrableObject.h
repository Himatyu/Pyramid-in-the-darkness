/**
* @file		OctreeRegistrableObject.h
* @brief	八分木に登録されるオブジェクト
* @author	S.OIKAWA
* @date		2017.01.09
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Common/WorldVolume.h"
#include"TypeComparable.h"
#include"ICastable.h"
#include<list>
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
			class Octree;
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
			/// 八分木に登録されるオブジェクト
			/// TODO:DOD的に確保したほうがキャッシュに乗るから絶対早い
			/// </summary>
			class OctreeRegistrableObject:
				public Utility::TypeComparable,
				public Utility::ICastable
			{
				friend class SpaceDivide::Octree;
				friend class SpaceDivide::Cell;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				OctreeRegistrableObject(Common::WorldVolume&);
				virtual ~OctreeRegistrableObject() = default;

				OctreeRegistrableObject(const OctreeRegistrableObject&) = default;
				OctreeRegistrableObject(OctreeRegistrableObject&&) = default;

				OctreeRegistrableObject& operator=(const OctreeRegistrableObject&) = default;
				OctreeRegistrableObject& operator=(OctreeRegistrableObject&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 自身と異なる型のオブジェクトをリストから除外する
				/// </summary>
				void ExcludesOtherTypeObjectInSameSpace();

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

			private:
				PROPERTY(m_Morton, Morton, DWORD);
				PROPERTY(m_pCell, pCell, Cell*);
				PROPERTY(m_pNext, pNext, OctreeRegistrableObject*);
				PROPERTY(m_pPrev, pPrev, OctreeRegistrableObject*);
				PROPERTY(m_pLast, pLast, OctreeRegistrableObject*);

			public:
				PROPERTY(m_ObjectVolume, ObjectVolume, Common::WorldVolume&);
				PROPERTY_REF(m_SameSpaceList,
					SameSpaceList, std::list<OctreeRegistrableObject*>);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				Common::WorldVolume&						m_ObjectVolume;
				std::list<OctreeRegistrableObject*>			m_SameSpaceList;
				DWORD										m_Morton;
				Cell*										m_pCell = nullptr;
				OctreeRegistrableObject*					m_pNext = nullptr;
				OctreeRegistrableObject*					m_pPrev = nullptr;
				OctreeRegistrableObject*					m_pLast = nullptr;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------