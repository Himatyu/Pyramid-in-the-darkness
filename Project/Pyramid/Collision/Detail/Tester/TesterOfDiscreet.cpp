/**
* @file		TesterOfDiscreet.cpp
* @brief	�g���l�����O�΍���s��Ȃ��Փ˔���
* @author	S.OIKAWA
* @date		2017.04.29
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "TesterOfDiscreet.h"
#include "Nullable.h"
#include "../HitEventPublisher.h"
#include "../CollisionProvider.h"
#include "../Collider/ICollider.h"
#include "../../HitResult.h"
#include "../Defines.h"
#include "../CollisionInformation.h"
#include "../ColliderManager.h"
#include "../ICollidee.h"
#include "../../IVolume.h"
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
			namespace Tester
			{
				//-----------------------------------------------------------
				// Run : �Փ˗���������Η��p���A�Ȃ����colider�̌�������s��
				//-----------------------------------------------------------
				Utility::Nullable<EventPair> TesterOfDiscreet::Run(
					ICollidee *	_pCollideeL, ICollidee * _pCollideeR)
					
				{
					auto& selfBVList = _pCollideeL->BVList;
					auto& partnerBVList = _pCollideeR->BVList;

					//�Փ˂��Ă����ꍇ���݂ɓo�^����̂ŕЕ��݂̂̃`�F�b�N�ŗǂ�
					auto& partners = _pCollideeL->Partners;
					auto oppInfo = partners.find(_pCollideeR);
					auto IsHitPrevFream = (oppInfo != partners.end());

					if (IsHitPrevFream)
					{
						return TestOfRegistedCollidee(
							(*oppInfo).second.FindedLogList);
					}
					else
					{
						return TestOfUnRegistedCollidee(
							selfBVList,
							partnerBVList);
					}

				}

				//-----------------------------------------------------------
				// TestOfRegistedCollidee : �������g�p���Ĕ���݂̂��s��
				//-----------------------------------------------------------
				Utility::Nullable<EventPair> 
					TesterOfDiscreet::TestOfRegistedCollidee(
					std::list<FindResult::ForLog>& _log)
				{
					bool pred = true;
					Utility::Nullable<ResultPair> collisionResult;
					auto findResult = Utility::Nullable<FindResult::ForLog>();

					for (auto& _ : _log)
					{
						auto volume1 = get<1>(_).lock();
						auto volume2 = get<2>(_).lock();
						if (!(volume1 && volume2))
						{
							return {};
						}
						findResult = _;
						collisionResult = get<0>(_)->
							IsCollision(volume1.get(), volume2.get());

						pred &= collisionResult.IsHasValue;

						if (!pred)
						{
							return{};
						}
					}

					auto& eventPublisher = HitEventPublisher::Instantiate();

					auto volume1 = std::get<1>(*findResult).lock();
					auto volume2 = std::get<2>(*findResult).lock();

					auto events = eventPublisher.PublishEventStay(
						volume1->pCollidee, collisionResult.Value.first,
						volume2->pCollidee, collisionResult.Value.second);

					return Utility::Nullable<EventPair>(events);

				}

				//-----------------------------------------------------------
				// TestOfUnRegistedCollidee : Collider�̌������s���A�Փ˂��Ă���Η������c��
				//-----------------------------------------------------------
				Utility::Nullable<EventPair> 
					TesterOfDiscreet::TestOfUnRegistedCollidee(
					std::vector<Common::Sp<IVolume>>& _selfBVList,
					std::vector<Common::Sp<IVolume>>& _partnerBVList)
				{
					bool pred = true;
					Utility::Nullable<ResultPair>	collisionResult;
					Utility::Nullable<FindResult>	findResult;
					std::list<FindResult::ForLog>	logs;

					auto selfBVIt = _selfBVList.begin();
					auto selfBVEnd = _selfBVList.end();

					auto partnerBVIt = _partnerBVList.begin();
					auto partnerBVEnd = _partnerBVList.end();
					while (true)
					{
						findResult =
							m_ColliderManager.Find(
								*selfBVIt,
								*partnerBVIt);

						if (!findResult)
						{
							___D_LOG(
								"���o�^�̏Փ˗v�� : " +
								std::string((*selfBVIt)->AccessOfIndex(0)->name()) +
								" * " +
								std::string((*partnerBVIt)->AccessOfIndex(0)->name()));
							continue;
						}


						collisionResult =
							(*findResult).pCollider->IsCollision(
							(*findResult).spVolumeL.get(),
								(*findResult).spVolumeR.get());

						pred &= collisionResult.IsHasValue;

						//���Volume�œ������Ă��Ȃ���Ή��܂ō~��Ȃ�
						if (!collisionResult.IsHasValue)
						{
							break;
						}

						logs.push_back(
							(*findResult).ConvertItForRegistration());

						selfBVIt++;
						partnerBVIt++;

						//�o����Volume�𒲂ׂ�����
						if (selfBVIt == selfBVEnd && partnerBVIt == partnerBVEnd)
						{
							break;
						}

						//�ŉ��w��Volume�ɖ߂�
						if (selfBVIt == selfBVEnd)
						{
							selfBVIt--;
						}

						if (partnerBVIt == partnerBVEnd)
						{
							partnerBVIt--;
						}
					}

					if (!pred)
					{
						return {};
					}

					auto& eventPublisher = HitEventPublisher::Instantiate();
					auto volume1 = (*findResult).spVolumeL.get();
					auto volume2 = (*findResult).spVolumeR.get();

					auto events=  eventPublisher.
						PublishEventEnter(
							volume1->pCollidee, collisionResult.Value.first,
							volume2->pCollidee, collisionResult.Value.second,
							logs);

					return Utility::Nullable<EventPair>(events);

				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------