/**
* @file		OctreeRegistrableObject.cpp
* @brief	八分木に登録されるオブジェクト
* @author	S.OIKAWA
* @date		2017.01.09
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OctreeRegistrableObject.h"
#include"Cell.h"
#include"Octree.h"
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		namespace SpaceDivide
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			OctreeRegistrableObject::
				OctreeRegistrableObject(Common::WorldVolume & _vol)
				:m_ObjectVolume(_vol)
			{
				TypeApply<OctreeRegistrableObject>();
			}

			//-----------------------------------------------------------
			// ExcludesOtherTypeObjectInSameSpace
			//-----------------------------------------------------------
			void OctreeRegistrableObject::ExcludesOtherTypeObjectInSameSpace()
			{
				m_SameSpaceList
					.remove_if(
						[&](OctreeRegistrableObject* _pObj)
				{
					return (*_pObj != *this);
				});

			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------