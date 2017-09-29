/**
* @file		ILight.h
* @brief	���C�g�C���^�[�t�F�[�X
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
			/// ���C�g�ɕK�v�ȋ@�\���`����
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