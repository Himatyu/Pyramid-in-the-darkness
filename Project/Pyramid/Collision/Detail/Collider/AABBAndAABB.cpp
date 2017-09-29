/**
* @file		AABBAndAABB.cpp
* @brief	AABBëŒAABBÇÃè’ìÀîªíË
* @author	S.OIKAWA
* @date		2017.03.04
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"AABBAndAABB.h"
#include"../Components/Collidee.h"
#include"../Components/Transform.h"
#include"../GameObject/Object.h"
#include"../Common/Diagram/AABB.h"
#include"../HitEventPublisher.h"
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
					AABBAndAABB::IsCollision(IVolume * _pAABB1, IVolume * _pAABB2)
				{
					auto diagrams = CastToVolume(_pAABB1, _pAABB2);

					auto& aabb1Min = diagrams.first->ScaledBV.Min;
					auto& aabb1Max = diagrams.first->ScaledBV.Max;

					auto& aabb2Min = diagrams.second->ScaledBV.Min;
					auto& aabb2Max = diagrams.second->ScaledBV.Max;

					if (aabb1Max.X < aabb2Min.X || aabb1Min.X > aabb2Max.X)
					{
						return Utility::NullType();
					}

					if (aabb1Max.Y < aabb2Min.Y || aabb1Min.Y > aabb2Max.Y)
					{
						return Utility::NullType();
					}

					if (aabb1Max.Z < aabb2Min.Z || aabb1Min.Z > aabb2Max.Z)
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