/**
* @file		Screen.h
* @brief	バックバッファを保持する
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
			/// バックバッファを保持する
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
				/// レンダリングターゲットを切り替える
				/// </summary>
				virtual void SetTarget() override;

				/// <summary>
				/// ターゲットを初期化する
				/// </summary>
				virtual void Clear() override;

			private:
				/// <summary>
				/// バックバッファを取得する.
				/// グラフィックの初期化時に一度だけ呼ばれる
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