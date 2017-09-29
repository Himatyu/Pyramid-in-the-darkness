/**
* @file		SphereAndAABB.h
* @brief	Sphere��AABB�̏Փ˔���
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IDiagramCollider.h"
#include"../Common/Diagram/AABB.h"
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
				/// Sphere��AABB�̏Փ˔���
				/// </summary>
				class SphereAndAABB :
					public IDiagramCollider<Common::Diagram::Sphere, Common::Diagram::AABB>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					SphereAndAABB() = default;
					~SphereAndAABB() = default;

					SphereAndAABB(const SphereAndAABB&) = default;
					SphereAndAABB(SphereAndAABB&&) = default;

					SphereAndAABB& operator=(const SphereAndAABB&) = default;
					SphereAndAABB& operator=(SphereAndAABB&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// �Փ�
					/// </summary>
					Utility::Nullable<ResultPair> 
						IsCollision(IVolume * _pSphere, IVolume * _pAABB) override;
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