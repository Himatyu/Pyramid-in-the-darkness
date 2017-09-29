/**
* @file		Screen.h
* @brief	�o�b�N�o�b�t�@��ێ�����
* @author	S.OIKAWA
* @date		2016.12.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"RenderTarget.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		class Graphics;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Target
		{
			/// <summary>
			/// �o�b�N�o�b�t�@��ێ�����
			/// </summary>
			class Screen :
				public RenderTarget
			{
				friend class Pyramid::Rendering::Graphics;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Screen() = default;
				~Screen();

				Screen(const Screen&) = default;
				Screen(Screen&&) = default;

				Screen& operator=(const Screen&) = default;
				Screen& operator=(Screen&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �����_�����O�^�[�Q�b�g��؂�ւ���
				/// </summary>
				virtual void SetTarget() override;

				/// <summary>
				/// �^�[�Q�b�g������������
				/// </summary>
				virtual void Clear() override;

			private:
				/// <summary>
				/// �o�b�N�o�b�t�@���擾����.
				/// �O���t�B�b�N�̏��������Ɉ�x�����Ă΂��
				/// </summary>
				void GetBackBuffer();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				LPDIRECT3DSURFACE9 m_pBackBuffer = nullptr;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------