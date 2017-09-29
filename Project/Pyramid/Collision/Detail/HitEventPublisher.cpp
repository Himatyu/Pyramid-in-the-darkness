/**
* @file		HitEventPublisher.cpp
* @brief	衝突時のイベントを発行する
* @author	S.OIKAWA
* @date		2017.03.04
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HitEventPublisher.h"
#include"ICollidee.h"
#include"CollisionInformation.h"
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace std;
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// PreparationOfPublish
			//-----------------------------------------------------------
			void HitEventPublisher::PreparationOfPublish(ICollidee * _pCollidee)
			{
				auto& map = _pCollidee->m_DataOfTheCollisionPartners;
				for (auto& _ : map)
				{
					_.second.IsHitInFream = false;
				}
				_pCollidee->IsPreparatdForEventPublish = true;
				_pCollidee->IsPublishedEventOfExit = false;

			}

			//-----------------------------------------------------------
			// PublishEventEnter
			//-----------------------------------------------------------
			EventPair HitEventPublisher::PublishEventEnter(
				ICollidee* _pLCollidee, HitResult & _LHitResult,
				ICollidee* _pRCollidee, HitResult & _RHitResult,
				std::list<FindResult::ForLog>& _Log)
			{
				return EventPair
				(
					PublishOfEnter(_pLCollidee, _pRCollidee, _LHitResult, _Log),
					PublishOfEnter(_pRCollidee, _pLCollidee, _RHitResult, _Log)
				);
			}


			//-----------------------------------------------------------
			// PublishEventEnter
			//-----------------------------------------------------------
			EventPair HitEventPublisher::PublishEventEnter(
				ICollidee* _pLCollidee, HitResult & _LHitResult,
				ICollidee* _pRCollidee, HitResult & _RHitResult)
			{
				std::list<FindResult::ForLog> _Log; //必要ないのでから
				return EventPair
				(
					PublishOfEnter(_pLCollidee, _pRCollidee, _LHitResult, _Log),
					PublishOfEnter(_pRCollidee, _pLCollidee, _RHitResult, _Log)
				);
			}

			//-----------------------------------------------------------
			// PublishEventStay
			//-----------------------------------------------------------
			EventPair HitEventPublisher::PublishEventStay(
				ICollidee * _pLCollidee, HitResult& _LHitResult,
				ICollidee * _pRCollidee, HitResult& _RHitResult)
			{
				return EventPair
					(
					PublishOfStay(_pLCollidee, _pRCollidee, _LHitResult),
					PublishOfStay(_pRCollidee, _pLCollidee, _RHitResult)
					);
			}

			//-----------------------------------------------------------
			// PublishEventOfExit
			//-----------------------------------------------------------
			std::vector<DelayEvent>
				HitEventPublisher::PublishEventOfExit(ICollidee * _pCollidee)
			{
				std::vector<DelayEvent> exitList;
				auto& map = _pCollidee->m_DataOfTheCollisionPartners;

				for (auto it = map.begin(); it != map.end();)
				{
					if (!it->second.IsHitInFream)
					{
						exitList.push_back(
							DelayEvent( _pCollidee ,
								it->second.Result ,
								DelayEventType::Exit));
						map.erase(it++);
						continue;
					}
					++it;
				}
				_pCollidee->IsPublishedEventOfExit = true;
				_pCollidee->IsPreparatdForEventPublish = false;

				return exitList;
			}

			//-----------------------------------------------------------
			// PublishOfEnter
			//-----------------------------------------------------------
			DelayEvent HitEventPublisher::PublishOfEnter(
				ICollidee* _pReceive,
				ICollidee* _pHitCollidee,
				HitResult _hitResult,
				std::list<FindResult::ForLog>& _log)
			{

				auto& map = _pReceive->m_DataOfTheCollisionPartners;
				map.insert(
					std::make_pair(
						_pHitCollidee,
						CollisionInformation(true, _hitResult, _log)));

				return DelayEvent(_pReceive, _hitResult, DelayEventType::Enter);
			}

			//-----------------------------------------------------------
			// Publish
			//-----------------------------------------------------------
			DelayEvent HitEventPublisher::PublishOfStay(
				ICollidee* _pReceive, 
				ICollidee* _pHitCollidee,
				HitResult _hitResult)
			{
				auto& map = _pReceive->m_DataOfTheCollisionPartners;
				auto result = map.find(_pHitCollidee);//Stayなので必ず存在する
				result->second.IsHitInFream = true;

				return DelayEvent(_pReceive, _hitResult, DelayEventType::Stay);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------