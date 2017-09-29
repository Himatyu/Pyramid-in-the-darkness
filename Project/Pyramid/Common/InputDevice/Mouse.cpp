/**
* @file		Mouse.cpp
* @brief	マウス
* @author	S.OIKAWA
* @date		2017.02.12
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Mouse.h"
#include"Exception.h"
#include"Constant.h"
#include"DeviceManager.h"
#include"../Blueprint/Application.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

inline bool IsOnState(BYTE _data)
{
	return (_data & 0x80);
}
namespace Pyramid
{
	namespace Common
	{
		namespace InputDevice
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Mouse::Mouse()
			{
				SetUp();
				m_MouseState = { 0 };
				m_MouseStatePrevFream = { 0 };
			}
			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			Mouse::~Mouse()
			{
				DeviceManager::Instantiate().UnRegisterDevice(this);
			}

			//-----------------------------------------------------------
			// IsPushButton
			//-----------------------------------------------------------
			bool Mouse::IsPushButton(Id _id)
			{
				return IsOnState(m_MouseState.rgbButtons[_id]);
			}

			//-----------------------------------------------------------
			// IsDownButton
			//-----------------------------------------------------------
			bool Mouse::IsDownButton(Id _id)
			{
				return
					IsOnState(m_MouseState.rgbButtons[_id]) &&
					!IsOnState(m_MouseStatePrevFream.rgbButtons[_id]);
			}

			//-----------------------------------------------------------
			// IsUpButton
			//-----------------------------------------------------------
			bool Mouse::IsUpButton(Id _id)
			{
				return
					!IsOnState(m_MouseState.rgbButtons[_id]) &&
					IsOnState(m_MouseStatePrevFream.rgbButtons[_id]);
			}

			//-----------------------------------------------------------
			// SetUp
			//-----------------------------------------------------------
			void Mouse::SetUp()
			{
				m_Hwnd = Blueprint::Application::GetMainWindow()->GetHwnd();
				auto pInput = DeviceManager::Instantiate().pInput;

				// データ形式を設定
				if (FAILED(pInput->CreateDevice(GUID_SysMouse, &m_pDevice, NULL)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "マウスデバイスの作成に失敗");
				}

				// モードを設定（フォアグラウンド＆非排他モード）
				if (FAILED(m_pDevice->SetDataFormat(&c_dfDIMouse2)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "マウスモードを設定に失敗");
				}

				// 強調レベルを設定
				if (FAILED(m_pDevice->SetCooperativeLevel(m_Hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "マウスモードを設定に失敗");
				}

				// 軸モードを設定（相対値モードに設定）
				DIPROPDWORD diprop;
				diprop.diph.dwSize = sizeof(diprop);
				diprop.diph.dwHeaderSize = sizeof(diprop.diph);
				diprop.diph.dwObj = 0;
				diprop.diph.dwHow = DIPH_DEVICE;
				diprop.dwData = DIPROPAXISMODE_REL;
				//	diprop.dwData		= DIPROPAXISMODE_ABS;	// 絶対値モードの場合

				if (FAILED(m_pDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "マウスモプロパティ設定に失敗");
				}
				// バッファリング・データを取得するため、バッファ・サイズを設定
				diprop.dwData = Constant::DeviceBufferSizeForMouse;
				if (FAILED(m_pDevice->SetProperty(DIPROP_BUFFERSIZE, &diprop.diph)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "マウスモプロパティ設定に失敗");
				}

				// 入力制御開始
				if (FAILED(m_pDevice->Acquire()))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "マウス入力制御開始に失敗");
				}

				DeviceManager::Instantiate().RegisterDevice(this);

			}

			//-----------------------------------------------------------
			// Updata
			//-----------------------------------------------------------
			void Mouse::Updata()
			{
				m_MouseStatePrevFream = m_MouseState;
				if (FAILED(m_pDevice->GetDeviceState(sizeof(DIMOUSESTATE2), &m_MouseState)))
				{
					//フォーカス消失
					if (GetForegroundWindow() == m_Hwnd)
					{
						//フォーカス復帰
						if (FAILED(m_pDevice->Acquire()))
						{
							___LOG("マウスフォーカス消失");
						}
					}
				}

				RECT				winRect;
				POINT				wolrdPosition;
				GetWindowRect(m_Hwnd, &winRect);
				GetCursorPos(&wolrdPosition);

				//HACK 誤差どうにかならんかな
				m_MousePosition.X =
					static_cast<float>(wolrdPosition.x - winRect.left - GetSystemMetrics(SM_CXFIXEDFRAME) + 3);
				m_MousePosition.Y =
					static_cast<float>(wolrdPosition.y - winRect.top - GetSystemMetrics(SM_CYCAPTION) + 10);

			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------