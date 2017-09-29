/**
* @file		MCIAudioFile.h
* @brief	WinAPI��MCI�Ɉˑ������I�[�f�B�I�t�@�C��
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
			/// MCI�I�[�f�B�I������
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
				/// �t�@�C���ǂݍ���.
				/// </summary>
				/// <param name="_path">�t�@�C���p�X</param>
				/// <returns>�ǂݍ��ݐ�������</returns>
				void Read(std::string _path) override;

				/// <summary>
				/// ����j������.
				/// </summary>
				void Discard() override;

				/// <summary>
				/// �Đ�.
				/// </summary>
				/// <param name="_loopCount">�Đ���.0�Ń��[�v</param>
				void Play(int _loopCount) override;

				/// <summary>
				/// ��~.
				/// </summary>
				void Stop() override;

				/// <summary>
				/// �ꎞ��~.
				/// </summary>
				void Pause() override;

				/// <summary>
				/// �ꎞ��~����.
				/// </summary>
				void Resume() override;

				/// <summary>
				/// ���ʕύX
				/// </summary>
				void ChangeVolume() override;

				/// <summary>
				/// �Đ������ʒm.
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
