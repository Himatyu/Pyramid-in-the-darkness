/**
* @file		ILight.h
* @brief	ライトインターフェース
* @author	S.OIKAWA
* @date		2016.11.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Shaders
		{
			class Shader;
		}
	}
}
#pragma endregion
namespace Pyramid
{
	namespace Components
	{
		namespace Detail
		{
			/// <summary>
			/// ライトに必要な機能を定義する
			/// </summary>
			__interface ILight
			{
				void SetLight(Rendering::Shaders::Shader*,int);
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------