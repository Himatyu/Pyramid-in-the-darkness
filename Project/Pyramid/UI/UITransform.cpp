/**
* @file		UITransform.cpp
* @brief	UIの座標・サイズ・回転と親子関係を持つ
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UITransform.h"
#include"IUI.h"
#include"Constant.h"
#include"Mathf.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace UI
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		UITransform::UITransform(IUI& _ui):
			m_Size(Constant::DefaultUISize),//見えないと困るので初期値
			m_Owner(_ui),
			m_Scale(::Utility::Vector2::once),
			m_ParentsScale(::Utility::Vector2::once)
		{
			
		}

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		void UITransform::AddChild(IUI & _ui)
		{
			Add(&_ui);
			_ui.Transform.m_pParent = &m_Owner;
		}

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		void UITransform::RemoveChild(IUI & _ui)
		{
			Remove(&_ui);
			_ui.Transform.m_pParent = nullptr;
		}

		//-----------------------------------------------------------
		// UpdataDepthAndParentOffset
		//-----------------------------------------------------------
		void UITransform::UpdataDepthAndParentOffset()
		{
			m_Position.Z = ::Utility::Mathf::Clamp01(m_Position.Z);			
		}

		//-----------------------------------------------------------
		// CalculatWorldMatrix
		//-----------------------------------------------------------
		D3DXMATRIX UITransform::CalculatWorldMatrix()
		{
			D3DXMATRIX rotate, scale, move, offset;

			m_ParentsPosition = ::Utility::Vector3::zero;
			m_ParentsScale = ::Utility::Vector2::once;
			m_ParentsRotateZ = 0;

			auto it = m_pParent;
			while (it)
			{
				m_ParentsPosition += it->Transform.m_Position;
				m_ParentsRotateZ += it->Transform.RotateZ;
				m_ParentsScale *= it->Transform.Scale;
				it = it->Transform.m_pParent;
			}

			::Utility::Vector3  aMove(m_Position + m_ParentsPosition);
			::Utility::Vector2  aScale(m_Scale * m_ParentsScale);
			float aRotate = m_RotateZ + m_ParentsRotateZ;

			D3DXMatrixIdentity(&scale);
			D3DXMatrixScaling(&scale, m_Size.X * aScale.X, m_Size.Y * aScale.Y, 1.0f);

			D3DXMatrixIdentity(&move);
			D3DXMatrixTranslation(&move,
				aMove.X,
				aMove.Y,
				0);

			D3DXMatrixIdentity(&offset);
			D3DXMatrixTranslation(&offset, -m_Size.X*0.5, -m_Size.Y*0.5, 0.0);

			D3DXMatrixIdentity(&rotate);
			D3DXMatrixRotationZ(&rotate, D3DXToRadian(aRotate));

			return (scale*offset*rotate)*move;
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------