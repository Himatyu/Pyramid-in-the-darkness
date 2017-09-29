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
			/// オーディオのリソースを持ち、
			/// 操作を提供する
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
				/// 再生.
				/// </summary>
				/// <param name="loopCount">再生回数.0でループ</param>
				void Play(int loopCount = 1);

				/// <summary>
				/// 停止.
				/// </summary>
				void Stop();

				/// <summary>
				/// 一時停止.
				/// </summary>
				void Pause();

				/// <summary>
				/// 一時停止解除.
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
