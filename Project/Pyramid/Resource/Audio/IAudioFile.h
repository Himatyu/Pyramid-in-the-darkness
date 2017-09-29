/**
* @file		IAudioFile.h
* @brief	オーディオファイルに必要なインターフェースを定義
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
			/// サウンドファイル.
			/// 今のところ対応はMP3,Wavのみ.
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
					/// 再生.
					/// </summary>
					/// <param name="_loopCount">再生回数.0でループ</param>
				virtual void Play(int _loopCount) = 0;

				/// <summary>
				/// 停止.
				/// </summary>
				virtual void Stop() = 0;

				/// <summary>
				/// 一時停止.
				/// </summary>
				virtual void Pause() = 0;

				/// <summary>
				/// 一時停止解除.
				/// </summary>
				virtual void Resume() = 0;

				/// <summary>
				/// 音量変更.
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