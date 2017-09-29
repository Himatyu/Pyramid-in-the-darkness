/**
* @file		CollisionProvider.h
* @brief	衝突発生を提供する
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"
#include"ColliderManager.h"
#include"FindResult.h"
#include"Nullable.h"
#include"Defines.h"
#include"CollisionProvider.h"
#include<vector>
#include<array>
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
			namespace Collider
			{
				class ICollider;
			}
			namespace Tester
			{
				class ITester;
			}

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
			/// 衝突発生を提供する
			/// Enterが発生したClliderはそのColliderの過程をLogして以降の判定に使用
			/// Enterに至るまでの過程のキャッシュは破棄タイミングが不明なため行わない
			/// </summary>
			class CollisionProvider final
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				CollisionProvider() ;
				~CollisionProvider();

				CollisionProvider(const CollisionProvider&) = default;
				CollisionProvider(CollisionProvider&&) = default;

				CollisionProvider& operator=(const CollisionProvider&) = default;
				CollisionProvider& operator=(CollisionProvider&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 一対一の衝突
				/// </summary>
				Utility::Nullable<EventPair> Collision(ICollidee*, ICollidee*);

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_ColliderManager, Manager, ColliderManager);
#pragma endregion

#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				ColliderManager					m_ColliderManager;
				std::array<
					Tester::ITester*,
					static_cast<size_t>(Detection::Count)> m_TesterArray;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------