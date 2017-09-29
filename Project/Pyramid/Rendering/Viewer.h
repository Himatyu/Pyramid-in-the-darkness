/**
* @file		Viewer.h
* @brief	�����_�����O�ɕK�v�ȃJ�������̏����܂Ƃ߂�
* @author	S.OIKAWA
* @date		2016.11.13
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3dx9.h>
#include<array>
#include"../Utility/Layer.h"
#include"CameraLayer.h"
#include"Detail/Frustum.h"

#include"Constant.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Target
		{
			class RenderingTexture;
		}
		namespace Detail
		{
			class MLRCPublisher;
		}
	}
	namespace Components
	{
		class Camera;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		/// <summary>
		/// �����_�����O�ɕK�v�ȏ�������
		/// </summary>
		class Viewer 
		{
			friend class Rendering::Detail::Frustum;
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			Viewer();
			virtual ~Viewer();

			Viewer(const Viewer&) = default;
			Viewer(Viewer&&) = default;

			Viewer& operator=(const Viewer&) = default;
			Viewer& operator=(Viewer&&) = default;
#pragma endregion

			/// <summary>
			/// �����_�����O�^�[�Q�b�g��ύX����
			/// RenderTarget���Z�b�g����Ă��Ȃ���Ή������Ȃ�
			/// </summary>
			void SetRenderTarget();

			/// <summary>
			/// �����_�����O�^�[�Q�b�g���o�b�N�o�b�t�@�ɖ߂�
			/// </summary>
			void RiseRenderTarget();

			/// <summary>
			/// �����̂��X�V����
			/// </summary>
			void CalculateFrustum();

			/// <summary>
			/// ������ɋߎ������͈͂̃��X�g���擾
			/// </summary>
			std::list<Rendering::Detail::Optimize::MLRCPublisher*>
				GetObjectOfSameSpace();

#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_REF(m_View, View, D3DXMATRIX);
			PROPERTY_REF(m_Proj, Proj, D3DXMATRIX);
			PROPERTY_REF(m_EyePt, EyePos, Utility::Vector3);
			PROPERTY_REF(m_LookatPt, LookatPt, Utility::Vector3);
			PROPERTY_REF(m_ViewFrustum, ViewFrustum, Detail::Frustum);
			PROPERTY(m_pRenderingTexture, pRenderingTexture, Target::RenderingTexture*);
			PROPERTY(m_Fov, Fov, float);
			PROPERTY(m_Aspect, Aspect, float);		//�A�X�䂪0�Ȃ玩���v�Z
			PROPERTY(m_Near, Near, float);
			PROPERTY(m_Far, Far, float);
#pragma endregion
		protected:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			D3DXMATRIX									m_View;
			D3DXMATRIX									m_Proj;
			Detail::Frustum								m_ViewFrustum;			

			Utility::Vector3	m_EyePt ;
			Utility::Vector3	m_LookatPt;
			Utility::Vector3	m_UpVec ;

			float				m_Fov = 90;				
			float				m_Aspect = 0;			
			float				m_Near = 0.1f;			
			float				m_Far = 1000.0f;		

			Target::RenderingTexture*	m_pRenderingTexture = nullptr;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------