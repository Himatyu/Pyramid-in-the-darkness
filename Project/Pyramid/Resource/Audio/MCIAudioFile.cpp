/**
* @file			MCIAudioFile.cpp
* @brief		WinAPIのMCIに依存したオーディオファイル
* @author		S.OIKAWA
* @date			2016.08.24
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "MCIAudioFile.h"
#include"../Blueprint/Application.h"
#include"../Blueprint/window.h"
#include"../Resource/Audio/MCIMessageDispatcher.h"
#include"../Constant.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Audio
		{
			using namespace Blueprint;
			using namespace std;
			const int g_MCIMaxVolume = 1000;
			bool isLoop = false;
			//-----------------------------------------------------------
			// ctor 
			//-----------------------------------------------------------
			MCIAudioFile::MCIAudioFile()
			{
				auto& ins = MCIMessageDispatcher::Instantiate();
				ins.Register(this);
			}
			//-----------------------------------------------------------
			// dtor 
			//-----------------------------------------------------------
			MCIAudioFile::~MCIAudioFile()
			{
				auto& ins = MCIMessageDispatcher::Instantiate();
				ins.UnRegister(this);
				Discard();
			}

			//-----------------------------------------------------------
			// Read 
			//-----------------------------------------------------------
			void MCIAudioFile::Read(string _path)
			{
				SetFilePathInfo(_path);
				m_OpenParams.lpstrElementName = _path.c_str();

				int result;
				if (_path.find(Constant::ExtensionMP3) != string::npos)
				{
					m_OpenParams.lpstrDeviceType
						= Constant::OpenParamsDeviceTypeMPEG.c_str();
					result = mciSendCommand
					(
						0,
						MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,
						reinterpret_cast<DWORD_PTR>(&m_OpenParams)
					);

				}
				else if (_path.find(Constant::ExtensionWAV) == string::npos)
				{
					m_OpenParams.lpstrDeviceType =
						reinterpret_cast<LPSTR>(MCI_DEVTYPE_WAVEFORM_AUDIO);
					result = mciSendCommand
					(
						0,
						MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT,
						reinterpret_cast<DWORD_PTR>(&m_OpenParams)
					);

				}
				else
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, "無効なファイル拡張子 : " + FileName);
				}

				if (result)
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, "オーディオファイルを開けなかった" + FileName);
				}


				auto window = Application::GetMainWindow();
				m_PlayParams.dwCallback =
					reinterpret_cast <DWORD>(window->GetHwnd());

				m_SetAudio_Params.dwItem = MCI_DGV_SETAUDIO_VOLUME;
				m_SetAudio_Params.dwValue =
					static_cast<DWORD>(g_MCIMaxVolume * Volume);
				result = mciSendCommand
				(m_OpenParams.wDeviceID,
					MCI_SETAUDIO,
					MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM,
					reinterpret_cast<DWORD_PTR>(&m_SetAudio_Params));

				if (result)
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, "AudioValueのひも付けに失敗" + FileName);
				}
			}

			//-----------------------------------------------------------
			// Discard
			//-----------------------------------------------------------
			void MCIAudioFile::Discard()
			{
				mciSendCommand(m_OpenParams.wDeviceID, MCI_CLOSE, 0, 0);
			}

			//-----------------------------------------------------------
			// Play
			//-----------------------------------------------------------
			void MCIAudioFile::Play(int _loopCount)
			{
				m_LoopCount = _loopCount;
				isLoop = _loopCount == 0;
				mciSendCommand(
					m_OpenParams.wDeviceID,
					MCI_PLAY,
					MCI_NOTIFY,
					reinterpret_cast<DWORD_PTR>(&m_PlayParams));
			}

			//-----------------------------------------------------------
			// Pause 
			//-----------------------------------------------------------
			void MCIAudioFile::Pause()
			{
				mciSendCommand(
					m_OpenParams.wDeviceID,
					MCI_PAUSE,
					MCI_NOTIFY,
					reinterpret_cast<DWORD_PTR>(&m_PlayParams));
			}

			//-----------------------------------------------------------
			// Resume
			//-----------------------------------------------------------
			void MCIAudioFile::Resume()
			{
				mciSendCommand(
					m_OpenParams.wDeviceID,
					MCI_RESUME,
					MCI_NOTIFY,
					reinterpret_cast<DWORD_PTR>(&m_PlayParams));
			}

			//-----------------------------------------------------------
			// Stop 
			//-----------------------------------------------------------
			void MCIAudioFile::Stop()
			{
				mciSendCommand(
					m_OpenParams.wDeviceID,
					MCI_STOP,
					MCI_NOTIFY,
					reinterpret_cast<DWORD_PTR>(&m_PlayParams));
			}

			//-----------------------------------------------------------
			// NotifySuccessFul 
			//-----------------------------------------------------------
			void MCIAudioFile::NotifySuccessFul()
			{
				if (isLoop)
				{
					mciSendCommand(
						m_OpenParams.wDeviceID,
						MCI_SEEK,
						MCI_SEEK_TO_START,
						0);

					mciSendCommand(
						m_OpenParams.wDeviceID,
						MCI_PLAY,
						MCI_NOTIFY,
						reinterpret_cast<DWORD_PTR>(&m_PlayParams));
					return;
				}

				m_LoopCount--;
				if (m_LoopCount > 0)
				{
					mciSendCommand(
						m_OpenParams.wDeviceID,
						MCI_SEEK,
						MCI_SEEK_TO_START,
						0);

					mciSendCommand(
						m_OpenParams.wDeviceID,
						MCI_PLAY,
						MCI_NOTIFY,
						reinterpret_cast<DWORD_PTR>(&m_PlayParams));
				}
			}

			//-----------------------------------------------------------
			// ChangeVolume 
			//-----------------------------------------------------------
			void MCIAudioFile::ChangeVolume()
			{
				m_SetAudio_Params.dwValue =
					static_cast<DWORD>(g_MCIMaxVolume * Volume);
				int result = mciSendCommand
				(m_OpenParams.wDeviceID,
					MCI_SETAUDIO,
					MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM,
					reinterpret_cast<DWORD_PTR>(&m_SetAudio_Params));

				if (result)
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, "AudioValueのひも付けに失敗" + FileName);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
