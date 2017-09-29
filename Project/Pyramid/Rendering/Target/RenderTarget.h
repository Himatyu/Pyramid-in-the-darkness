/**
* @file		RenderTarget.h
* @brief	�����_�����O�^�[�Q�b�g�Ƃ��Ẵe�N�X�`��
* @author	S.OIKAWA
* @date		2016.12.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3dx9.h>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Target
		{
			/// <summary>
			/// ���x�����ׂ����g�p���l���Ă��Ȃ��̂ŁA
			/// ���\�[�X�Ƃ��ĊǗ��͂��Ȃ�
			/// </summary>
			class RenderTarget
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				RenderTarget() = default;
				~RenderTarget() = default;

				RenderTarget(const RenderTarget&) = default;
				RenderTarget(RenderTarget&&) = default;

				RenderTarget& operator=(const RenderTarget&) = default;
				RenderTarget& operator=(RenderTarget&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �����_�����O�^�[�Q�b�g��؂�ւ���
				/// </summary>
				virtual void SetTarget() = 0;

				/// <summary>
				/// �^�[�Q�b�g������������
				/// </summary>
				virtual void Clear() = 0;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_pDepthStencil, pDepthStencil, LPDIRECT3DSURFACE9);
				PROPERTY(m_IsDiscardWithFream, IsDiscardWithFream, bool);
#pragma endregion
			protected:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------

				LPDIRECT3DSURFACE9	m_pDepthStencil = nullptr;
				bool				m_IsDiscardWithFream = true;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------