/**
* @file		LightingPublisher.h
* @brief	ライト情報をデバイスにプッシュする
* @author	S.OIKAWA
* @date		2016.11.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
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
		namespace Shaders
		{
			class Shader;
		}
		namespace Detail
		{
			/// <summary>
			/// ライト情報をデバイスにプッシュする
			/// </summary>
			class LightingPublisher final
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				LightingPublisher() = default;
				~LightingPublisher() = default;

				LightingPublisher(const LightingPublisher&) = default;
				LightingPublisher(LightingPublisher&&) = default;

				LightingPublisher& operator=(const LightingPublisher&) = default;
				LightingPublisher& operator=(LightingPublisher&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// コンテキストのライト情報をデバイスにプッシュする.
				/// </summary>
				void SetLights(Shaders::Shader*);
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
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------