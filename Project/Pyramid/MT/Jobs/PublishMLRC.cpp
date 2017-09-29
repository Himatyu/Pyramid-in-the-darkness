/**
* @file		PublishMLRC.cpp
* @brief	非同期でMLRC発行をコールして、集計する
* @author	S.OIKAWA
* @date		2016.10.08
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"PublishMLRC.h"
#include"../Order/MLRCPublisher.h"
#include"../Rendering/Detail/Optimize/MLRC.h"
#include"../Rendering/RenderProvider.h"
#include<functional>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Rendering::Detail::Optimize;
namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			//-----------------------------------------------------------
			// Job
			//-----------------------------------------------------------
			void PublishMLRC::Job()
			{
				auto& render = Rendering::RenderProvider::Instantiate().Wolrd;
				auto& frustum = render.pCurrentViewer->ViewFrustum;

				for (auto& _ : m_pOrders)
				{
					if (!_->IsPublish(frustum))
					{
						continue;
					}
					m_MLRCList.push_back(_->PublishMLRC());
				}

				m_MLRCList.sort(
					[](const MLRC* lhv, const MLRC* rhv) 
						{return lhv->ConstPriority < rhv->ConstPriority; });
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------