/**
* @file		Transform.cpp
* @brief	トランスフォーム
* @author	S.OIKAWA
* @date		2016.05.09
*/
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Transform.h"
#include"../GameObject/Object.h"
#include"../Rendering/Graphics.h"
#include"Constant.h"
#include"../Components/Constant.h"
#include"../Common/Constant.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Utility;
namespace Pyramid
{
	namespace Components
	{
		using namespace Blueprint;
		using namespace GameObject;
		using namespace Components;
		using namespace ::Utility;

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Transform::Transform() :
			m_Position(),
			m_Rotation(),
			m_Scale(Vector3::once)
		{
			D3DXMatrixIdentity(&m_matWorld);
			D3DXMatrixIdentity(&m_matRotate);
			Order(&Transform::AsyncUpdata,
				Common::Constant::MTUpdataGrupName,
				Components::Constant::TransformMTUpdataLineID);
		}

		//-----------------------------------------------------------
		// Init 
		//-----------------------------------------------------------
		void Transform::Init()
		{
		}

		//-----------------------------------------------------------
		// PositionUpdate
		//-----------------------------------------------------------
		void Transform::PositionUpdate(D3DXMATRIX& _mat)
		{
			Vector3 pos(m_Position + m_InheritedPosition);

			m_Velocity = pos - m_BeforePosition;
			m_BeforePosition = pos;
			
			D3DXMatrixTranslation(&_mat, pos.X, pos.Y, pos.Z);

		}
		
		//-----------------------------------------------------------
		// RotateUpdate
		//-----------------------------------------------------------
		void Transform::RotateUpdate(D3DXMATRIX& _mat)
		{
			Vector3 rote(m_Rotation + m_InheritedRotation);

			D3DXMatrixRotationYawPitchRoll(&_mat,
				D3DXToRadian(rote.Y),
				D3DXToRadian(rote.X),
				D3DXToRadian(rote.Z));
		}

		//-----------------------------------------------------------
		// ScaleUpdate
		//-----------------------------------------------------------
		void Transform::ScaleUpdate(D3DXMATRIX& _mat)
		{
			Vector3 scale(m_Scale);
			D3DXMatrixScaling(&_mat, scale.X, scale.Y, scale.Z);
		}

		//-----------------------------------------------------------
		// 非同期更新
		//-----------------------------------------------------------
		void Transform::AsyncUpdata()
		{

			D3DXMATRIX		matTrans;
			D3DXMATRIX		matScale;

			D3DXMatrixIdentity(&matTrans);
			D3DXMatrixIdentity(&matScale);
			D3DXMatrixIdentity(&m_matWorld);
			D3DXMatrixIdentity(&m_matRotate);

			if (!m_IsFixingPosition)
			{
				PositionUpdate(matTrans);
			}

			if (!m_IsFixingRotate)
			{
				RotateUpdate(m_matRotate);
			}				

			if (!m_IsFixingScale)
			{
				ScaleUpdate(matScale);
			}

			m_matWorld = m_matRotate * matScale * matTrans;

			m_Right.Set(m_matWorld._11, m_matWorld._12, m_matWorld._13);
			m_Up.Set(m_matWorld._21, m_matWorld._22, m_matWorld._33);
			m_Forward.Set(m_matWorld._31, m_matWorld._32, m_matWorld._33);

		}

		//-----------------------------------------------------------
		// Updata 
		//-----------------------------------------------------------
		void Transform::Updata()
		{
			//if (nullptr != m_pParent)
			//{
			//	auto& parentTrans = m_pParent->GetComponent<Transform>();
			//	
			//	m_InheritedPosition = 
			//		m_IsPositionInherited ?
			//		parentTrans->Position :
			//		Utility::Vector3::zero;


			//	m_InheritedRotation = 
			//		m_IsRotationInherited ?
			//		parentTrans->Rotation :
			//		Utility::Vector3::zero;
			//	
			//}
		}

	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------