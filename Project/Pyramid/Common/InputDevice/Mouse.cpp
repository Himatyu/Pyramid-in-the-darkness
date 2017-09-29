/**
* @file		Mouse.cpp
* @brief	�}�E�X
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

				// �f�[�^�`����ݒ�
				if (FAILED(pInput->CreateDevice(GUID_SysMouse, &m_pDevice, NULL)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "�}�E�X�f�o�C�X�̍쐬�Ɏ��s");
				}

				// ���[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
				if (FAILED(m_pDevice->SetDataFormat(&c_dfDIMouse2)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "�}�E�X���[�h��ݒ�Ɏ��s");
				}

				// �������x����ݒ�
				if (FAILED(m_pDevice->SetCooperativeLevel(m_Hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "�}�E�X���[�h��ݒ�Ɏ��s");
				}

				// �����[�h��ݒ�i���Βl���[�h�ɐݒ�j
				DIPROPDWORD diprop;
				diprop.diph.dwSize = sizeof(diprop);
				diprop.diph.dwHeaderSize = sizeof(diprop.diph);
				diprop.diph.dwObj = 0;
				diprop.diph.dwHow = DIPH_DEVICE;
				diprop.dwData = DIPROPAXISMODE_REL;
				//	diprop.dwData		= DIPROPAXISMODE_ABS;	// ��Βl���[�h�̏ꍇ

				if (FAILED(m_pDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "�}�E�X���v���p�e�B�ݒ�Ɏ��s");
				}
				// �o�b�t�@�����O�E�f�[�^���擾���邽�߁A�o�b�t�@�E�T�C�Y��ݒ�
				diprop.dwData = Constant::DeviceBufferSizeForMouse;
				if (FAILED(m_pDevice->SetProperty(DIPROP_BUFFERSIZE, &diprop.diph)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "�}�E�X���v���p�e�B�ݒ�Ɏ��s");
				}

				// ���͐���J�n
				if (FAILED(m_pDevice->Acquire()))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "�}�E�X���͐���J�n�Ɏ��s");
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
					//�t�H�[�J�X����
					if (GetForegroundWindow() == m_Hwnd)
					{
						//�t�H�[�J�X���A
						if (FAILED(m_pDevice->Acquire()))
						{
							___LOG("�}�E�X�t�H�[�J�X����");
						}
					}
				}

				RECT				winRect;
				POINT				wolrdPosition;
				GetWindowRect(m_Hwnd, &winRect);
				GetCursorPos(&wolrdPosition);

				//HACK �덷�ǂ��ɂ��Ȃ�񂩂�
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