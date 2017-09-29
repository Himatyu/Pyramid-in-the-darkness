/**
* @file		CollisionEventListener.h
* @brief	�Փ˃C�x���g���󂯎��R���|�[�l���g��o�^����
* @author	S.OIKAWA
* @date		2017.03.05
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include"Manager.h"
#include"../IHitEvent.h"
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
			/// <summary>
			/// �Փ˃C�x���g���󂯎��R���|�[�l���g��o�^����
			/// </summary>
			class CollisionEventListener :
				public Utility::Manager<std::list<IHitEvent*>>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				CollisionEventListener() = default;
				virtual ~CollisionEventListener() = default;

				CollisionEventListener(const CollisionEventListener&) = default;
				CollisionEventListener(CollisionEventListener&&) = default;

				CollisionEventListener& operator=(const CollisionEventListener&) = default;
				CollisionEventListener& operator=(CollisionEventListener&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

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
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------