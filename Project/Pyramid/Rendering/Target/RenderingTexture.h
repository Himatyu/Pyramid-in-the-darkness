/**
* @file		RenderingTexture.h
* @brief	�����_�����O�^�[�Q�b�g�Ƃ��Ẵe�N�X�`��
* @author	S.OIKAWA
* @date		2016.12.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"RenderTarget.h"
#include"singleton.h"

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
			/// �����_�����O�^�[�Q�b�g�Ƃ��Ẵe�N�X�`��
			/// ���x�����ׂ����g�p���l���Ă��Ȃ��̂ŁA
			/// ���\�[�X�Ƃ��ĊǗ��͂��Ȃ�
			/// </summary>
			class RenderingTexture :
				public RenderTarget
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				RenderingTexture() = default;
				~RenderingTexture() = default;

				RenderingTexture(const RenderingTexture&) = default;
				RenderingTexture(RenderingTexture&&) = default;

				RenderingTexture& operator=(const RenderingTexture&) = default;
				RenderingTexture& operator=(RenderingTexture&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ��������
				/// </summary>
				void Create(
					UINT                    _width,
					UINT                    _height,
					D3DFORMAT				_format = D3DFMT_A8R8G8B8,
					D3DPOOL					_pool = D3DPOOL_DEFAULT,
					D3DFORMAT				_bufferFormat = D3DFMT_D16,
					D3DMULTISAMPLE_TYPE		_bufferMultiSample = D3DMULTISAMPLE_NONE
					);

				/// <summary>
				/// �����_�����O�^�[�Q�b�g��؂�ւ���
				/// </summary>
				virtual void SetTarget() override;

				/// <summary>
				/// �^�[�Q�b�g������������
				/// </summary>
				virtual void Clear() override;

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_pTexture, pTexture, LPDIRECT3DTEXTURE9);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				LPDIRECT3DTEXTURE9	m_pTexture = nullptr;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------