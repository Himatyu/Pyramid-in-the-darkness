/**
* @file		AABBToSphere.cpp
* @brief	AABB‚ðSphere‚É•ÏŠ·‚·‚é
* @author	S.OIKAWA
* @date		2017.05.01
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"AABBToSphere.h"
#include"../AABB.h"
#include"../Sphere.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{
			namespace Converter
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				AABBToSphere::AABBToSphere()
				{
					TypeApply<AABB, Sphere>();
				}

				//-----------------------------------------------------------
				// ctoor
				//-----------------------------------------------------------
				std::shared_ptr<IDiagram> AABBToSphere::Convert(IDiagram * _pAABB)
				{
					auto pSphere = std::make_shared<Sphere>();
					auto pAabb = _pAABB->CastTo<AABB*>();

					pSphere->Center = pAabb->CalculateOfCenter();
					pSphere->R = (pAabb->Max - pSphere->Center).GetLength();
					return pSphere;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------