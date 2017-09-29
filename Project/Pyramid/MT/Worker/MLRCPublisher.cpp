/**
* @file		MLRCPublisher.cpp
* @brief	PublishMLRCをコールする
* @author	S.OIKAWA
* @date		2016.11.25
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"MLRCPublisher.h"
#include"../MT/Jobs/PublishMLRC.h"
#include"../Rendering/Detail/Optimize/MLRC.h"
#include"../Rendering/Detail/Optimize/MLRCPublisher.h"
#include"../Rendering/Detail/OptimizationRender.h"
#include"../Rendering/RendringPriority.h"
#include"../Rendering/RenderProvider.h"
#include"../Rendering/Viewer.h"
#include"Range.h"
#include"Estd.h"
#include"Vector3.h"
#include"Priority.hpp"
#include<vector>
#include<algorithm>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Rendering;
using namespace Pyramid::Rendering::Detail;
using namespace Pyramid::Rendering::Detail::Optimize;
using namespace std;
using namespace Utility;

namespace Pyramid
{
	namespace MT
	{
		namespace Worker
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			MLRCPublisher::MLRCPublisher()
			{
				auto& mtSystem = ThreadSystem::Instantiate();
				m_Jobs.resize(mtSystem.TheradCount());

				for (auto& _ : m_Jobs)
				{
					_ = new Jobs::PublishMLRC;
				}
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			MLRCPublisher::~MLRCPublisher()
			{
				Utility::Estd::for_each(
					m_Jobs,
					[&](auto& _) {SAFE_DELETE(_); });
			}

			//-----------------------------------------------------------
			// MergeCmd
			//-----------------------------------------------------------
			void MLRCPublisher::MergeCmd()
			{
				for (auto& job : m_Jobs)
				{
					if (!m_PublishedCommand.size())
					{
						m_PublishedCommand = move(job->MLRCList);
						continue;
					}

					m_PublishedCommand
						.merge(
							move(job->MLRCList),
							[&](MLRC* _lhv, MLRC* _rhv)
					{
						return (*_lhv < *_rhv);
					});
				}
			}

			//-----------------------------------------------------------
			//  SortCmd
			//-----------------------------------------------------------
			void MLRCPublisher::SortCmd()
			{
				m_PublishedCommand
					.sort([&](MLRC* _lhv, MLRC* _rhv)
				{
					return (*_lhv < *_rhv);
				});

				//TODO スカイボックス・UI処理

				Range<Priority<UINT>> rangeTransparent
					(
						Priority<UINT>((int)Rendering::RendringPriority::Transparent),
						Priority<UINT>((int)Rendering::RendringPriority::Overlay)
						);

				//ピクセルシェーダの負荷を減らすため手前から描画
				//オキュレーションカリング実装後に残す必要があるかわからない
				Range<Priority<UINT>> rangeOpacity
					(
						Priority<UINT>((int)Rendering::RendringPriority::Background),
						Priority<UINT>((int)Rendering::RendringPriority::Geometry)
						);

				m_PublishedCommand.sort
					(
						[&](MLRC* _lhv, MLRC* _rhv)
				{
					if (
						rangeTransparent.IsContains(_lhv->ConstPriority) &&
						rangeTransparent.IsContains(_rhv->ConstPriority)
						)
					{
						return (_lhv->Depth > _rhv->Depth);
					}
					if (
						rangeOpacity.IsContains(_lhv->ConstPriority) &&
						rangeOpacity.IsContains(_rhv->ConstPriority)
						)
					{
						return (_lhv->Depth < _rhv->Depth);
					}

					return false;
				}
				);

			}

			//-----------------------------------------------------------
			// TransmitRanderbleList
			//-----------------------------------------------------------
			void MLRCPublisher::TransmitRanderbleList()
			{
				list<OptimizationRender*> cmds(m_PublishedCommand.size());
				Utility::Estd::transform(
					m_PublishedCommand,
					cmds.begin(),
					[](const MLRC* _pCmd) {return _pCmd->pTarget; });

				m_SortedRenders = move(cmds);

				for (auto& job : m_Jobs)
				{
					job->MLRCList.clear();
					job->pJobs.clear();
				}
				m_PublishedCommand.clear();
			}

			//-----------------------------------------------------------
			// CulcDepth
			//-----------------------------------------------------------
			void MLRCPublisher::CalculationDepth(Rendering::RenderProvider& _render)
			{
				
				auto pView = _render.Wolrd.pCurrentViewer;
				auto CameraRay =
					(pView->LookatPt -pView->EyePos)
					.Normalize()
					*pView->Far;

				for (auto _ : m_PublishedCommand)
				{
					_->Depth =
						Vector3::OrthogonalProjection(
							CameraRay,
							*_->pWorldPosition- pView->EyePos)
						.GetLength();
				}
			}

			//-----------------------------------------------------------
			// Execution
			//-----------------------------------------------------------
			void MLRCPublisher::Execution()
			{
				auto& mtSystem = ThreadSystem::Instantiate();
				size_t mtJobsCount = m_Jobs.size();
				size_t threadCount = mtSystem.CommonThreadCount();

				if (!m_pOrders.size())
				{
					return;
				}

				if (!mtSystem.isUseMultiThread() ||
					!mtJobsCount ||
					!threadCount)
				{
					ExecuteThisThread();
					m_pOrders.clear();
					return;
				}

				JobDispatch(m_Jobs, m_pOrders);
				mtSystem.JobExecute<decltype(m_Jobs)>(m_Jobs);
				mtSystem.Join();

				//TODO もっとMTで効率化したい
				MergeCmd();
				CalculationDepth(Rendering::RenderProvider::Instantiate());
				SortCmd();
				TransmitRanderbleList();
				m_pOrders.clear();
			}
			//-----------------------------------------------------------
			// Order
			//-----------------------------------------------------------
			void MLRCPublisher::Order(
				Rendering::Detail::Optimize::MLRCPublisher*_pOrder)
			{
				m_pOrders.push_back(_pOrder);
			}

			//-----------------------------------------------------------
			// Order
			//-----------------------------------------------------------
			void MLRCPublisher::Order(
				list<Rendering::Detail::Optimize::MLRCPublisher*>& _list)
			{
				Utility::Estd::combineList(m_pOrders, _list);
			}
			//-----------------------------------------------------------
			// UnOrder
			//-----------------------------------------------------------
			void MLRCPublisher::UnOrder(
				Rendering::Detail::Optimize::MLRCPublisher * _pOrder)
			{
				m_pOrders.remove(_pOrder);
			}

			//-----------------------------------------------------------
			// ExecuteThisThread
			//-----------------------------------------------------------
			void MLRCPublisher::ExecuteThisThread()
			{
				auto& render = RenderProvider::Instantiate();
				auto& frustum = render.Wolrd.pCurrentViewer->ViewFrustum;

				for (auto& _ : m_pOrders)
				{
					if (!_->IsPublish(frustum))
					{
						continue;
					}
					m_PublishedCommand.push_back(_->PublishMLRC());
				}
				
				CalculationDepth(render);
				SortCmd();
				TransmitRanderbleList();
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------