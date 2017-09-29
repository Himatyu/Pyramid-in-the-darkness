/**
* @file		LightingPublisher.h
* @brief	���C�g�����f�o�C�X�Ƀv�b�V������
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
			/// ���C�g�����f�o�C�X�Ƀv�b�V������
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
				/// �R���e�L�X�g�̃��C�g�����f�o�C�X�Ƀv�b�V������.
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