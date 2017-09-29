/**
* @file		MCIAudioFile.h
* @brief	WinAPIのMCIに依存したオーディオファイル
* @author	S.OIKAWA
* @date		2016.08.24
*/

#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"IAudioFile.h"
#include<Windows.h>
#include<mmsystem.h>
#include<string>
#include<Digitalv.h>

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
			/// MCIオーディオを扱う
			/// </summary>
			class MCIAudioFile final :
				public IAudioFile
			{
			public:

				//-----------------------------------------------------------
				// defaults 
				//-----------------------------------------------------------
				MCIAudioFile();
				~MCIAudioFile();

				MCIAudioFile(const MCIAudioFile&) = default;
				MCIAudioFile(MCIAudioFile&&) = default;

				MCIAudioFile&operator=(const MCIAudioFile&) = default;
				MCIAudioFile&operator=(MCIAudioFile&&) = default;

				//-----	------------------------------------------------------
				// function 
				//-----------------------------------------------------------

				/// <summary>
				/// ファイル読み込み.
				/// </summary>
				/// <param name="_path">ファイルパス</param>
				/// <returns>読み込み成功是非</returns>
				void Read(std::string _path) override;

				/// <summary>
				/// 情報を破棄する.
				/// </summary>
				void Discard() override;

				/// <summary>
				/// 再生.
				/// </summary>
				/// <param name="_loopCount">再生回数.0でループ</param>
				void Play(int _loopCount) override;

				/// <summary>
				/// 停止.
				/// </summary>
				void Stop() override;

				/// <summary>
				/// 一時停止.
				/// </summary>
				void Pause() override;

				/// <summary>
				/// 一時停止解除.
				/// </summary>
				void Resume() override;

				/// <summary>
				/// 音量変更
				/// </summary>
				void ChangeVolume() override;

				/// <summary>
				/// 再生完了通知.
				/// </summary>
				void NotifySuccessFul();

				//-----------------------------------------------------------
				// PROPERTY 
				//-----------------------------------------------------------
				PROPERTY_REF(m_OpenParams, OpenParams, MCI_OPEN_PARMS);
				PROPERTY_REF(m_PlayParams, PlayParams, MCI_PLAY_PARMS);
				PROPERTY_REF(m_SetAudio_Params, AudioParams, MCI_DGV_SETAUDIO_PARMS);
				PROPERTY_R_ONLY(m_LoopCount, LoopCount, int);
				//-----------------------------------------------------------
				// val 
				//-----------------------------------------------------------
			private:
				MCI_OPEN_PARMS				m_OpenParams{ 0 };
				MCI_PLAY_PARMS				m_PlayParams{ 0 };
				MCI_DGV_SETAUDIO_PARMS		m_SetAudio_Params{ 0 };

				int m_LoopCount = 0;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
