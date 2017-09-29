/**
* @file		Key.cpp
* @brief	キーボードの入力を扱う
* @author	S.OIKAWA
* @date		2017.02.12
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Constant.h"
#include"Key.h"
#include"Exception.h"
#include"../Blueprint/Application.h"
#include"../InputDevice/DeviceManager.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

inline bool IsOnState(BYTE _data)
{
	return (_data & 0x80);
}

using namespace Utility;
namespace Pyramid
{
	namespace Common
	{
		namespace InputDevice
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Key::Key()
			{
				SetUp();
				m_KeyState = { 0 };
				m_KeyStatePrevFream = { 0 };

			}
			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			Key::~Key()
			{
				DeviceManager::Instantiate().UnRegisterDevice(this);
			}

			//-----------------------------------------------------------
			// IsKeyPush
			//-----------------------------------------------------------
			bool Key::IsKeyPush(int _Dik)
			{
				return IsOnState(m_KeyState[_Dik]);
			}

			//-----------------------------------------------------------
			// IsKeyDown
			//-----------------------------------------------------------
			bool Key::IsKeyDown(int _Dik)
			{
				return
					IsOnState(m_KeyState[_Dik]) &&
					!IsOnState(m_KeyStatePrevFream[_Dik]);
			}

			//-----------------------------------------------------------
			// IsKeyUp
			//-----------------------------------------------------------
			bool Key::IsKeyUp(int _Dik)
			{
				return
					!IsOnState(m_KeyState[_Dik]) &&
					IsOnState(m_KeyStatePrevFream[_Dik]);
			}
			//-----------------------------------------------------------
			// SetUp
			//-----------------------------------------------------------
			void Key::SetUp()
			{
				m_Hwnd = Blueprint::Application::GetMainWindow()->GetHwnd();
				auto pInput = DeviceManager::Instantiate().pInput;

				// データ形式を設定
				if (FAILED(pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
				{
					___THROW_EXCEPTION_POINT(Exception, "Keyのデータ形式を設定に失敗");
				}

				// モードを設定（フォアグラウンド＆非排他モード）
				if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
				{
					___THROW_EXCEPTION_POINT(Exception, "Keyのモード設定に失敗");
				}

				// 強調レベルを設定
				if (FAILED(m_pDevice->SetCooperativeLevel(m_Hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
				{
					___THROW_EXCEPTION_POINT(Exception, "Keyの強調レベルの設定に失敗");
				}

				// 軸モードを設定（相対値モードに設定）
				DIPROPDWORD diprop;
				diprop.diph.dwSize = sizeof(diprop);
				diprop.diph.dwHeaderSize = sizeof(diprop.diph);
				diprop.diph.dwObj = 0;
				diprop.diph.dwHow = DIPH_DEVICE;
				diprop.dwData = DIPROPAXISMODE_REL;
				//	diprop.dwData		= DIPROPAXISMODE_ABS;	// 絶対値モードの場合
				// バッファリング・データを取得するため、バッファ・サイズを設定
				diprop.dwData = Constant::DeviceBufferSizeForKey;
				if (FAILED(m_pDevice->SetProperty(DIPROP_BUFFERSIZE, &diprop.diph)))
				{
					___THROW_EXCEPTION_POINT(Exception, "Keyのプロパティ設定に失敗");
				}
				// 入力制御開始
				if (FAILED(m_pDevice->Acquire()))
				{
					___THROW_EXCEPTION_POINT(Exception, "Keyの入力開始に失敗");
				}

				DeviceManager::Instantiate().RegisterDevice(this);
			}

			//-----------------------------------------------------------
			// Updata
			//-----------------------------------------------------------
			void Key::Updata()
			{
				m_KeyStatePrevFream = m_KeyState;
				if (FAILED(m_pDevice->GetDeviceState(256, m_KeyState.data())))
				{
					//フォーカス消失
					if (GetForegroundWindow() == m_Hwnd)
					{
						//フォーカス復帰
						if (FAILED(m_pDevice->Acquire()))
						{
							___LOG("Keyのフォーカス復帰に失敗");
						}
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------