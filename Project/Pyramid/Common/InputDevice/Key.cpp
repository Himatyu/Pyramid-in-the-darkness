/**
* @file		Key.cpp
* @brief	�L�[�{�[�h�̓��͂�����
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

				// �f�[�^�`����ݒ�
				if (FAILED(pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
				{
					___THROW_EXCEPTION_POINT(Exception, "Key�̃f�[�^�`����ݒ�Ɏ��s");
				}

				// ���[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
				if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
				{
					___THROW_EXCEPTION_POINT(Exception, "Key�̃��[�h�ݒ�Ɏ��s");
				}

				// �������x����ݒ�
				if (FAILED(m_pDevice->SetCooperativeLevel(m_Hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
				{
					___THROW_EXCEPTION_POINT(Exception, "Key�̋������x���̐ݒ�Ɏ��s");
				}

				// �����[�h��ݒ�i���Βl���[�h�ɐݒ�j
				DIPROPDWORD diprop;
				diprop.diph.dwSize = sizeof(diprop);
				diprop.diph.dwHeaderSize = sizeof(diprop.diph);
				diprop.diph.dwObj = 0;
				diprop.diph.dwHow = DIPH_DEVICE;
				diprop.dwData = DIPROPAXISMODE_REL;
				//	diprop.dwData		= DIPROPAXISMODE_ABS;	// ��Βl���[�h�̏ꍇ
				// �o�b�t�@�����O�E�f�[�^���擾���邽�߁A�o�b�t�@�E�T�C�Y��ݒ�
				diprop.dwData = Constant::DeviceBufferSizeForKey;
				if (FAILED(m_pDevice->SetProperty(DIPROP_BUFFERSIZE, &diprop.diph)))
				{
					___THROW_EXCEPTION_POINT(Exception, "Key�̃v���p�e�B�ݒ�Ɏ��s");
				}
				// ���͐���J�n
				if (FAILED(m_pDevice->Acquire()))
				{
					___THROW_EXCEPTION_POINT(Exception, "Key�̓��͊J�n�Ɏ��s");
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
					//�t�H�[�J�X����
					if (GetForegroundWindow() == m_Hwnd)
					{
						//�t�H�[�J�X���A
						if (FAILED(m_pDevice->Acquire()))
						{
							___LOG("Key�̃t�H�[�J�X���A�Ɏ��s");
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