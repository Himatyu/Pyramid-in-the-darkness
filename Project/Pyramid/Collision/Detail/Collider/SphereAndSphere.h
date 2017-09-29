/**
* @file		SphereAndSphere.h
* @brief	SphereëŒSphereÇÃè’ìÀîªíË
* @author	S.OIKAWA
* @date		2017.03.05
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IDiagramCollider.h"
#include"../Common/Diagram/Sphere.h"
#include"../Defines.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			namespace Collider
			{
				/// <summary>
				/// SphereëŒSphereÇÃè’ìÀîªíË
				/// </summary>
				class SphereAndSphere :
					public IDiagramCollider<Common::Diagram::Sphere, Common::Diagram::Sphere>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					SphereAndSphere() = default;
					~SphereAndSphere() = default;

					SphereAndSphere(const SphereAndSphere&) = default;
					SphereAndSphere(SphereAndSphere&&) = default;

					SphereAndSphere& operator=(const SphereAndSphere&) = default;
					SphereAndSphere& operator=(SphereAndSphere&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// è’ìÀ
					/// </summary>
					Utility::Nullable<ResultPair> 
						IsCollision(IVolume * _pSphere1, IVolume * _pSphere2) override;
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------