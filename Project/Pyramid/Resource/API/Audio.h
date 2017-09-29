/**
* @file		Audio.h
* @brief	AudioAPI
* @author	S.OIKAWA
* @date		2016.08.25
*/

#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "../API/IResourceAPI.h"
#include"../Audio/IAudioFile.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace API
		{
			/// <summary>
			/// �I�[�f�B�I�̃��\�[�X�������A
			/// �����񋟂���
			/// </summary>
			template<class Type>
			class Audio final :
				public IResourceAPI<Type>
			{
			public:
				//-----------------------------------------------------------
				// defaults 
				//-----------------------------------------------------------
				Audio() = default;
				~Audio() = default;

				Audio(const Audio&) = default;
				Audio(Audio&&) = default;

				Audio&operator=(const Audio&) = default;
				Audio&operator=(Audio&&) = default;

				//-----------------------------------------------------------
				// function 
				//-----------------------------------------------------------

				/// <summary>
				/// �Đ�.
				/// </summary>
				/// <param name="loopCount">�Đ���.0�Ń��[�v</param>
				void Play(int loopCount = 1);

				/// <summary>
				/// ��~.
				/// </summary>
				void Stop();

				/// <summary>
				/// �ꎞ��~.
				/// </summary>
				void Pause();

				/// <summary>
				/// �ꎞ��~����.
				/// </summary>
				void Resume();

				__declspec(property(
					get = GetVolume,
					put = SetVolume
					)) float Volume;

				void SetVolume(float _volume);
				float GetVolume();
				//-----------------------------------------------------------
				// operator
				//-----------------------------------------------------------
				void operator=(std::shared_ptr<Type> _sp);

				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				float			m_Volume = 1.0f;

			};
#include"Audio.inl"
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
