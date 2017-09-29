/**
* @file		AABBAndOBB.h
* @brief	AABBëŒOBBÇÃè’ìÀîªíË
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
				/// AABBëŒOBBÇÃè’ìÀîªíË
				/// </summary>
				class AABBAndOBB :
					public IDiagramCollider<Common::Diagram::AABB, Common::Diagram::OBB>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					AABBAndOBB() = default;
					~AABBAndOBB() = default;

					AABBAndOBB(const AABBAndOBB&) = default;
					AABBAndOBB(AABBAndOBB&&) = default;

					AABBAndOBB& operator=(const AABBAndOBB&) = default;
					AABBAndOBB& operator=(AABBAndOBB&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// è’ìÀ
					/// </summary>
					Utility::Nullable<ResultPair> 
						IsCollision(IVolume * _pAABB, IVolume * _pObb) override;
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