/**
* @file		Camera.cpp
* @brief	カメラ実装
* @author	S.OIKAWA
* @date		2016.05.09
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "Camera.h"
#include "Transform.h"
#include"../Rendering/Graphics.h"
#include"../Rendering/RenderProvider.h"
#include"../Rendering/Detail/Provider/WolrdRendering.h"
#include"../GameObject/Object.h"
#include"../MT/Order/TaskOrder.h"
#include"../Components/Constant.h"
#include"../Common/Constant.h"
#include"Estd.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		using namespace Blueprint;
		using namespace GameObject;

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Camera::Camera()
		{
			auto& ins = Rendering::RenderProvider::Instantiate().Wolrd;

			ins.Context.CameraList.AddRequest(this);
			ins.Context.CameraList.Apply();

			Order(&Camera::AsyncUpdata,
				Common::Constant::MTUpdataGrupName,
				Components::Constant::CameraMTUpdataLineID);
		}

		//-----------------------------------------------------------
		// dtor 
		//-----------------------------------------------------------
		Camera::~Camera()
		{
			OrderCancel(OrderList[0]);
			auto& ins = Rendering::RenderProvider::Instantiate().Wolrd;
			ins.Context.CameraList.RemoveRequest(this);
			ins.Context.CameraList.Apply();
		}

		//-----------------------------------------------------------
		// AsyncUpdata
		//-----------------------------------------------------------
		void Camera::AsyncUpdata()
		{
			if (!m_spObjectTransform)
			{
				return;
			}

			m_EyePt = m_spObjectTransform->Position;
			m_LookatPt = Utility::Vector3::forward;
			m_UpVec = Utility::Vector3::up;

			auto& rot = m_spObjectTransform->MatRotate;
			
			m_UpVec = Utility::Vector3::Rotate(m_UpVec, rot);
			m_LookatPt = Utility::Vector3::Rotate(m_LookatPt, rot);

			m_LookatPt += m_EyePt;

			D3DXMatrixPerspectiveFovLH
			(&m_Proj,
				m_Fov,
				m_Aspect,
				m_Near,
				m_Far
			);
			if (m_LockTarget)
			{
				m_LookatPt = m_LockTarget->Position;
			}

			//ビュー作成
			D3DXMatrixLookAtLH(&m_View,
				&m_EyePt.ToDirectX(),
				&m_LookatPt.ToDirectX(),
				&m_UpVec.ToDirectX());

		}

		//-----------------------------------------------------------
		// Updata :他のクラスを参照しているのでここで処理
		//-----------------------------------------------------------
		void Camera::Updata()
		{
			auto pDev = Rendering::Graphics::Instantiate().Device;
			pDev->SetTransform(D3DTS_VIEW, &m_View);
			pDev->SetTransform(D3DTS_PROJECTION, &m_Proj);

			//キャッシュ
			m_spObjectTransform = m_pOwner->GetComponent<Transform>().Value;

		}
		//-----------------------------------------------------------
		// Init 
		//-----------------------------------------------------------
		void Camera::Init()
		{
			auto& Grap = Rendering::Graphics::Instantiate();
			m_Aspect = Grap.Width / (FLOAT)Grap.Height;
			
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------