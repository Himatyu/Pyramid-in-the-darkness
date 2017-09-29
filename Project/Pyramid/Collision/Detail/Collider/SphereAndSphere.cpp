/**
* @file		SphereAndSphere.cpp
* @brief	SphereëŒSphereÇÃè’ìÀîªíË
* @author	S.OIKAWA
* @date		2017.03.05
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SphereAndSphere.h"
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
					SphereAndSphere::IsCollision(IVolume * _pSphere1, IVolume * _pSphere2)
				{
					auto diagrams = CastToVolume(_pSphere1, _pSphere2);

					auto& sphere1 = diagrams.first->ScaledBV;
					auto& sphere2 = diagrams.second->ScaledBV;

					auto distance = sphere1.Center - sphere2.Center;

					if (distance.GetLengthSquared() >
						((sphere1.R + sphere2.R)*(sphere1.R + sphere2.R)))
					{
						return Utility::NullType();
					}

					return CreateHitResultFromCastedPair(diagrams);
 				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------