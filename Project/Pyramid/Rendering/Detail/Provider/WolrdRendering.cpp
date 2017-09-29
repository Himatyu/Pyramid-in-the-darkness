/**
* @file		WolrdRendering.cpp
* @brief	ワールド空間のレンダリングを提供
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"WolrdRendering.h"
#include"../../Graphics.h"
#include"../../Viewer.h"
#include"../Common/Constant.h"
#include"../Blueprint/Constant.h"
#include"../MT/Order/OrderedJobExcuter.h"
#include"../MT/Worker/MLRCPublisher.h"
#include"../../Target/RenderTarget.h"
#include"../../Target/RenderingTexture.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Provider
			{
				//-----------------------------------------------------------
				// define
				//-----------------------------------------------------------

				using namespace std;
				using namespace Pyramid;
				using namespace Pyramid::MT;
				using namespace Pyramid::Rendering;
				using Pyramid::Common::Constant;

				//-----------------------------------------------------------
				// WaitVSync
				//-----------------------------------------------------------
				void WaitVSync(LPDIRECT3DDEVICE9 _pDevice, bool _IsFpsLimit)
				{
					D3DRASTER_STATUS rs;
					if (_IsFpsLimit)
					{
						do
						{
							_pDevice->GetRasterStatus(0, &rs);
						} while (!rs.InVBlank);
					}
				}

				//-----------------------------------------------------------
				// ClaerRenderTargets
				//-----------------------------------------------------------
				void ClaerRenderTargets(
					Graphics& _graphic,
					std::vector<Viewer*>& _views
				)
				{
					std::vector<Target::RenderTarget*> renderTargetList;
					renderTargetList.push_back(&_graphic.BackScreen);

					for (auto& _ : _views)
					{
						if (!_->pRenderingTexture)
						{
							continue;
						}
						renderTargetList
							.push_back(static_cast<Target::RenderTarget*>(_->pRenderingTexture));
					}

					for (auto& _ : renderTargetList)
					{
						if (!_->IsDiscardWithFream)
						{
							continue;
						}
						_->Clear();
					}
				}
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				WolrdRendering::WolrdRendering() :
					m_CommandFinalizer(&m_CurrentViewer)
				{
					//auto& jobExecuter = Order::OrderedJobExcuter::Instantiate();
					//auto& job = Worker::MLRCPublisher::Instantiate();
					//jobExecuter
					//	.Order(&job, Common::Constant::MTDrawGrupName);
				}

				/// <summary>
				/// レンダリングを行う
				/// </summary>
				void WolrdRendering::Rendering()
				{
					auto& graphic = Graphics::Instantiate();
					auto pDevice = graphic.Device;
					WaitVSync(pDevice, m_IsFpsLimit);

					auto& views = m_RenderingContext.CameraList.Vector;
					ClaerRenderTargets(graphic, views);

					Draw(views, m_CurrentViewer, m_CommandFinalizer);
				}

				/// <summary>
				/// デバイスにライト情報を送る
				/// </summary>
				void WolrdRendering::SetLights(Shaders::Shader* _pShader)
				{
					m_LightingPublisher.SetLights(_pShader);
				}

				//-----------------------------------------------------------
				// Draw
				//-----------------------------------------------------------
				void WolrdRendering::Draw(
					std::vector<Viewer*>& _views,
					Viewer*& _pCurrentViewer,
					Detail::Optimize::CommandFinalizer& _finalizer
				)
				{
					auto& publisher = Worker::MLRCPublisher::Instantiate();

					for (auto& _ : _views)
					{
						_pCurrentViewer = _;
						_pCurrentViewer->CalculateFrustum();
						_pCurrentViewer->SetRenderTarget();

						publisher.Order(_pCurrentViewer->GetObjectOfSameSpace());
						publisher.Execution();

						auto renderableList(
							_finalizer.Run(publisher.SortedRenders));

						for (auto& _ : renderableList)
						{
							_->PrepareToRendering();
							_->Rendering();
						}

						_pCurrentViewer->RiseRenderTarget();
					}
				}

			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------