/**
* @file		SphereAndAABB.cpp
* @brief	SphereëŒAABBÇÃè’ìÀîªíË
* @author	S.OIKAWA
* @date		2017.03.04
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SphereAndAABB.h"
#include"../Common/Diagram/Sphere.h"
#include"../Common/Diagram/AABB.h"
#include"../Collision/Detail/HitEventPublisher.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			namespace Collider
			{
				//-----------------------------------------------------------
				// Collision
				//-----------------------------------------------------------
				Utility::Nullable<ResultPair> 
					SphereAndAABB::IsCollision(IVolume * _pSphere, IVolume * _pAABB)
				{
					auto diagrams = CastToVolume(_pSphere, _pAABB);

					auto sphere = diagrams.first->ScaledBV;
					auto AABB = diagrams.second->ScaledBV;

					auto distance = 
						AABB.IsInside(sphere.Center);

					if (!distance || distance.Value < sphere.R)
					{
						return CreateHitResultFromCastedPair(diagrams);
					}
					return Utility::NullType();

				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------