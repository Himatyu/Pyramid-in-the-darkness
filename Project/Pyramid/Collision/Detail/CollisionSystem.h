/**
* @file		CollisionSystem.h
* @brief	衝突判定と遅延した応答を提供
* @author	S.OIKAWA
* @date		2017.05.08
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include<vector>
#include<utility>
#include"singleton.h"
#include"DelayEvent.h"
#include"CollisionProvider.h"
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
			/// 衝突判定と遅延した応答を提供
			/// 衝突判定を要求する
			/// 衝突応答を遅延して行う
			/// </summary>
			class CollisionSystem :
				public Utility::Singleton<CollisionSystem>
			{
				using CollideePair =
					std::pair<Detail::ICollidee*, Detail::ICollidee*>;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				CollisionSystem() = default;
				~CollisionSystem() = default;

				CollisionSystem(const CollisionSystem&) = default;
				CollisionSystem(CollisionSystem&&) = default;

				CollisionSystem& operator=(const CollisionSystem&) = default;
				CollisionSystem& operator=(CollisionSystem&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 衝突判定を要求する
				/// </summary>
				void RequestOfCollision(
					Detail::ICollidee*,
					std::list<Detail::ICollidee*>&);

				/// <summary>
				/// 要求を取り下げる
				/// </summary>
				void WithdrawOfRequest(Detail::ICollidee*);

				/// <summary>
				/// 判定のみを行う
				/// </summary>
				void ExecuteCollision();

				/// <summary>
				/// 衝突応答を遅延して行う
				/// </summary>
				void ExecuteReply();

			private:
				void PreparationOfCollision();
				void PublishEventOfExit();
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
			public:
				PROPERTY_REF(m_CollisionProvider, Provider, CollisionProvider);
#pragma endregion
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				std::list<CollideePair>				m_RequestOfCollision;
				std::vector<DelayEvent>				m_DelayEventsOfCollision;
				CollisionProvider					m_CollisionProvider;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------