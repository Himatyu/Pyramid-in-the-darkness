/**
* @file		CollisionSystem.cpp
* @brief	衝突判定と遅延した応答を提供
* @author	S.OIKAWA
* @date		2017.05.08
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"CollisionSystem.h"
#include"CollisionProvider.h"
#include"HitEventPublisher.h"
#include"Estd.h"
#include"ICollidee.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// RequestOfCollision
			//-----------------------------------------------------------
			void CollisionSystem::RequestOfCollision(
				ICollidee * _pCollidee,
				std::list<ICollidee*>& _collidees)
			{
				//uniqueを保持する 挿入前比較のほうがコスト低いはず・・・
				for (auto _ : _collidees)
				{
					CollideePair pair(_pCollidee, _);
					auto result =
						Utility::Estd::find_if(m_RequestOfCollision,
							[&](const CollideePair& _)
					{
						return
							(pair.first == _.first && pair.second == _.second) ||
							(pair.first == _.second && pair.second == _.first);
					});

					if (result != m_RequestOfCollision.end())
					{
						continue;
					}

					m_RequestOfCollision.push_back(pair);
				}
			}

			//-----------------------------------------------------------
			// WithdrawOfRequest
			//-----------------------------------------------------------
			void CollisionSystem::WithdrawOfRequest(
				ICollidee * _pCollidee)
			{
				Utility::Estd::remove_if(
					m_RequestOfCollision,
					[&](const CollideePair& _)
				{
					return (
						(_.first == _pCollidee) ||
						(_.second == _pCollidee));
				});
			}

			//-----------------------------------------------------------
			// ExecuteCollision
			//-----------------------------------------------------------
			void CollisionSystem::ExecuteCollision()
			{
				PreparationOfCollision();
				for (auto& _ : m_RequestOfCollision)//MT対応はこのリストを分割する
				{
					auto result = m_CollisionProvider.Collision(_.first, _.second);
					if (result)
					{
						m_DelayEventsOfCollision.push_back(result.Value.first);
						m_DelayEventsOfCollision.push_back(result.Value.second);
					}
				}

				PublishEventOfExit();
			}

			//-----------------------------------------------------------
			// ExecuteReply
			//-----------------------------------------------------------
			void CollisionSystem::ExecuteReply()
			{
				for (auto& _ : m_DelayEventsOfCollision)
				{
					_.CallEvent();
				}
			}

			//-----------------------------------------------------------
			// ExecuteReply
			//-----------------------------------------------------------
			void CollisionSystem::PreparationOfCollision()
			{
				m_DelayEventsOfCollision.clear();
				auto& publisher = HitEventPublisher::Instantiate();
				for (auto& _ : m_RequestOfCollision)
				{
					if (!_.first->IsPreparatdForEventPublish)
					{
						publisher.PreparationOfPublish(_.first);
					}

					if (!_.second->IsPreparatdForEventPublish)
					{
						publisher.PreparationOfPublish(_.second);
					}
				}
			}

			//-----------------------------------------------------------
			// ExecuteReply
			//-----------------------------------------------------------
			void CollisionSystem::PublishEventOfExit()
			{
				auto& publisher = HitEventPublisher::Instantiate();

				for (auto& _ : m_RequestOfCollision)
				{
					if (!_.first->IsPublishedEventOfExit)
					{
						Utility::Estd::copy(m_DelayEventsOfCollision,
							publisher.PublishEventOfExit(_.first));
					}

					if (!_.second->IsPublishedEventOfExit)
					{
						Utility::Estd::copy(m_DelayEventsOfCollision,
							publisher.PublishEventOfExit(_.second));
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------