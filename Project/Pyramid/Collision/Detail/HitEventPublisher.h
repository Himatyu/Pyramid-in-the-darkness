/**
* @file		HitEventPublisher.h
* @brief	衝突時のイベントを発行する
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"FindResult.h"
#include"../HitResult.h"
#include"singleton.h"
#include"Defines.h"
#include"DelayEvent.h"
#include<vector>
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
			/// 衝突時のイベントを発行する
			/// </summary>
			class HitEventPublisher : 
				public Utility::Singleton<HitEventPublisher>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				HitEventPublisher() = default;
				~HitEventPublisher() = default;

				HitEventPublisher(const HitEventPublisher&) = default;
				HitEventPublisher(HitEventPublisher&&) = default;

				HitEventPublisher& operator=(const HitEventPublisher&) = default;
				HitEventPublisher& operator=(HitEventPublisher&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 衝突パラメータの初期化
				/// </summary>
				void PreparationOfPublish(ICollidee*);
				
				/// <summary>
				/// Enterを発行する
				/// 内部でCollisionInformationを生成するためにLogを要求
				/// </summary>
				EventPair PublishEventEnter(
					ICollidee*, HitResult&,
					ICollidee*, HitResult&,
					std::list<FindResult::ForLog>&);

				/// <summary>
				/// Enterを発行する
				/// SVT用
				/// </summary>
				EventPair PublishEventEnter(
					ICollidee*, HitResult&,
					ICollidee*, HitResult&);

				/// <summary>
				/// Stayを発行する
				/// 図形のLogが完全なためLogはいらない
				/// </summary>
				EventPair PublishEventStay(
					ICollidee*, HitResult&,
					ICollidee*, HitResult&);
				
				/// <summary>
				/// 衝突終了イベントを発行
				/// </summary>
				std::vector<DelayEvent> PublishEventOfExit(ICollidee*);

			private:
				DelayEvent PublishOfStay(ICollidee*, ICollidee*, HitResult);
				DelayEvent PublishOfEnter(ICollidee*, ICollidee*,
					HitResult, std::list<FindResult::ForLog>&);
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