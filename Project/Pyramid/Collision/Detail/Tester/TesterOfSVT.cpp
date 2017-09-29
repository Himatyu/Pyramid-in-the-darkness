/**
* @file		TesterOfCSV.cpp
* @brief	CSVテストを含む衝突判定を行う
* @author	S.OIKAWA
* @date		2017.04.29
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TesterOfSVT.h"
#include "../Common/Diagram/OBB.h"
#include "../ICollidee.h"
#include "../HitEventPublisher.h"
#include "../../IVolume.h"
#include "../ColliderManager.h"
#include "../Collider/OBBAndOBB.h"
#include "../../Volume.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Common::Diagram;
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			namespace Tester
			{
				//-----------------------------------------------------------
				// Run : 毎回OBB型のSVを生成、判定する。精度確保のためOBBを使用
				//-----------------------------------------------------------
				Utility::Nullable<EventPair> TesterOfSVT::Run(
					ICollidee * _pCollideeL, ICollidee * _pCollideeR)
				{
					auto LSvs = CreateSVs(_pCollideeL);
					auto RSvs = CreateSVs(_pCollideeR);

					return TestOfCollision(LSvs, RSvs, _pCollideeL, _pCollideeR);
				}

				//-----------------------------------------------------------
				// CreateSV
				//-----------------------------------------------------------
				std::vector<Common::Diagram::OBB> 
					TesterOfSVT::CreateSVs(ICollidee * _pCollidee)
				{
					auto cacheThis = _pCollidee->m_CacheOfThisFream;
					auto cachePrev = _pCollidee->m_CacheOfPrevFream;
					auto thisMovement =
						cacheThis.Position - cachePrev.Position;

					std::vector<OBB> SVs;
					if (thisMovement == Utility::Vector3::zero)
					{
						for (auto & _ : _pCollidee->BVList)
						{
							SVs.push_back(_->ToSV());
						}
						return SVs;
					}

					for (auto & _ : _pCollidee->BVList)
					{
						auto SVb = _->ToSV();
						auto SVa = SVb;

						//Offsetは変化しない事が多いのでキャッシュせず
						//前フレームのOffsetとの差分は誤差とする
						SVa.Center = cachePrev.Position + _->Offset.Position;
						auto detection = _pCollidee->m_CollisionDetection;

						if (!detection.IsIgnoreScaleThenSVT)
						{
							auto diff = 
								(cachePrev.Scale / cacheThis.Scale) * _->Offset.Scale;
							SVa.ScaleTo(diff);
						}

						if (!detection.IsIgnoreRotateThenSVT)
						{
							SVa.RotateTo(cachePrev.Rotation + _->Offset.Rotation);
						}

						auto normalZ = thisMovement.GetNormalize();
						auto rCross = Utility::Vector3::RCross(normalZ);

						OBB SV;
						SV.LocalAxisX = rCross.first;
						SV.LocalAxisY = rCross.second;
						SV.LocalAxisZ = normalZ;

						SV.Half.X = max(
							SVb.CalculateHalfProjectLengthOnSeparatAxis(SV.LocalAxisX),
							SVa.CalculateHalfProjectLengthOnSeparatAxis(SV.LocalAxisX));

						SV.Half.Y = max(
							SVb.CalculateHalfProjectLengthOnSeparatAxis(SV.LocalAxisY),
							SVa.CalculateHalfProjectLengthOnSeparatAxis(SV.LocalAxisY));

						auto length = thisMovement.GetLength();
						auto projB = SVb.CalculateHalfProjectLengthOnSeparatAxis(SV.LocalAxisZ);
						auto projA = SVa.CalculateHalfProjectLengthOnSeparatAxis(SV.LocalAxisZ);
						SV.Half.Z = (length + projB + projA) / 2;
						
						auto diff = SVb.Center - SVa.Center;
						SV.Center = SVa.Center + diff*0.5f;

						SVs.push_back(SV);
					}

					return SVs;
				}
				
				//-----------------------------------------------------------
				// TestOfCollision
				//-----------------------------------------------------------
				Utility::Nullable<EventPair>
					TesterOfSVT::TestOfCollision(
					std::vector<Common::Diagram::OBB>& _thisList,
					std::vector<Common::Diagram::OBB>& _oppList,
					ICollidee* _pThis, ICollidee* _pOpp)
				{
					if (!_thisList.size() || !_oppList.size())
					{
						return{};
					}

					auto thisIt = _thisList.begin();
					auto thisEnd = _thisList.end();

					auto oppIt = _oppList.begin();
					auto oppEnd = _oppList.end();

					auto collider = 
						m_ColliderManager.Find<Collider::OBBAndOBB>().Value;
					Utility::Nullable<ResultPair> result;
					bool pred = false;
					while (true)
					{
						Volume<OBB> thiVolume(_pThis), oppVolume(_pOpp);
						thiVolume.ScaledBV = *thisIt;
						oppVolume.ScaledBV = *oppIt;
						thiVolume.spTransform = _pThis->spTransform;
						oppVolume.spTransform = _pOpp->spTransform;

						result = collider->IsCollision(&thiVolume, &oppVolume);

						if (!result)
						{
							return {};
						}

						thisIt++;
						oppIt++;

						if (thisIt == thisEnd && oppIt == oppEnd)
						{
							break;
						}

						if (thisIt == thisEnd)
						{
							thisIt--;
						}

						if (oppIt == oppEnd)
						{
							oppIt--;
						}
					}

					auto& eventPublisher = HitEventPublisher::Instantiate();

					//衝突していた場合相互に登録するので片方のみのチェックで良い
					auto log = _pThis->Partners;
					auto IsHitPrevFream = (log.find(_pOpp) != log.end());

					if (IsHitPrevFream)
					{
						return eventPublisher.
							PublishEventStay(
								_pThis, result.Value.first,
								_pOpp, result.Value.second);
						
					}
					std::list<FindResult::ForLog> empty;
					return eventPublisher.
						PublishEventEnter(
							_pThis, result.Value.first,
							_pOpp, result.Value.second,
							empty); //DiscreetではDectionで判断する
				}

			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------