/**
* @file		AABBAndAABB.h
* @brief	AABB��AABB�̏Փ˔���
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
				/// AABB��AABB�̏Փ˔���
				/// </summary>
				class AABBAndAABB :
					public IDiagramCollider<Common::Diagram::AABB, Common::Diagram::AABB>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					AABBAndAABB() = default;
					~AABBAndAABB() = default;

					AABBAndAABB(const AABBAndAABB&) = default;
					AABBAndAABB(AABBAndAABB&&) = default;

					AABBAndAABB& operator=(const AABBAndAABB&) = default;
					AABBAndAABB& operator=(AABBAndAABB&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// �Փ�
					/// </summary>
					Utility::Nullable<ResultPair>
						IsCollision(IVolume * _pAABB1, IVolume * _pAABB2) override;
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