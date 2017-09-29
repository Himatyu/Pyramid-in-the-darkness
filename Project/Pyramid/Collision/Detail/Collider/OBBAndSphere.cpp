/**
* @file		OBBAndSphere.cpp
* @brief	OBBëŒSphereÇÃè’ìÀîªíË
* @author	S.OIKAWA
* @date		2017.03.04
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OBBAndSphere.h"
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
					OBBAndSphere::IsCollision(IVolume * _pOBB, IVolume * _pSphere)
				{
					auto diagrams = CastToVolume(_pOBB, _pSphere);

					auto OBB = diagrams.first->ScaledBV;
					auto Sphere = diagrams.second->ScaledBV;

					auto distance =
						OBB.IsInside(Sphere.Center);

					if (!distance || distance.Value < Sphere.R)
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