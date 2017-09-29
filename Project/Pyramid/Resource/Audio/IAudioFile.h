/**
* @file		IAudioFile.h
* @brief	�I�[�f�B�I�t�@�C���ɕK�v�ȃC���^�[�t�F�[�X���`
* @author	S.OIKAWA
* @date		2016.08.14
*/

#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "../IResource.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Audio
		{
			/// <summary>
			/// �T�E���h�t�@�C��.
			/// ���̂Ƃ���Ή���MP3,Wav�̂�.
			/// </summary>
			class IAudioFile :
				public IResource
			{
			public:

				//-----------------------------------------------------------
				// defaults 
				//-----------------------------------------------------------
				IAudioFile() = default;
				virtual ~IAudioFile() = default;

				IAudioFile(const IAudioFile&) = default;
				IAudioFile(IAudioFile&&) = default;

				IAudioFile&operator=(const IAudioFile&) = default;
				IAudioFile&operator=(IAudioFile&&) = default;


				//-----------------------------------------------------------
				// function 
				//-----------------------------------------------------------

					/// <summary>
					/// �Đ�.
					/// </summary>
					/// <param name="_loopCount">�Đ���.0�Ń��[�v</param>
				virtual void Play(int _loopCount) = 0;

				/// <summary>
				/// ��~.
				/// </summary>
				virtual void Stop() = 0;

				/// <summary>
				/// �ꎞ��~.
				/// </summary>
				virtual void Pause() = 0;

				/// <summary>
				/// �ꎞ��~����.
				/// </summary>
				virtual void Resume() = 0;

				/// <summary>
				/// ���ʕύX.
				/// </summary>
				virtual void ChangeVolume() = 0;


				//-----------------------------------------------------------
				// property 
				//-----------------------------------------------------------
				PROPERTY(m_Volume, Volume, float);

				//-----------------------------------------------------------
				// val 
				//-----------------------------------------------------------
			private:
				float m_Volume = 1.0f;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------