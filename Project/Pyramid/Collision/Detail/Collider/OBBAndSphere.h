/**
* @file		OBBAndSphere.h
* @brief	OBBëŒSphereÇÃè’ìÀîªíË
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IDiagramCollider.h"
#include"../Common/Diagram/Sphere.h"
#include"../Common/Diagram/OBB.h"
#include"../Defines.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			class ICollidee;
		}
	}
}
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
				/// OBBëŒSphereÇÃè’ìÀîªíË
				/// </summary>
				class OBBAndSphere :
					public IDiagramCollider<Common::Diagram::OBB, Common::Diagram::Sphere>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					OBBAndSphere() = default;
					~OBBAndSphere() = default;

					OBBAndSphere(const OBBAndSphere&) = default;
					OBBAndSphere(OBBAndSphere&&) = default;

					OBBAndSphere& operator=(const OBBAndSphere&) = default;
					OBBAndSphere& operator=(OBBAndSphere&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					/// <summary>
					/// è’ìÀ
					/// </summary>
					Utility::Nullable<ResultPair> 
						IsCollision(IVolume * _pOBB, IVolume * _pSphere) override;
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