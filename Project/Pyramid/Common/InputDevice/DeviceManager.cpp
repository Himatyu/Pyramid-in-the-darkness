/**
* @file		DeviceManager.cpp
* @brief	入力デバイスを管理
* @author	S.OIKAWA
* @date		2017.02.12
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"DeviceManager.h"
#include"Exception.h"
#include"Device.h"
#include"Estd.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

namespace Pyramid
{
	namespace Common
	{
		namespace InputDevice
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			DeviceManager::DeviceManager()
			{
				if (FAILED(
					DirectInput8Create(
						GetModuleHandle(NULL),
						DIRECTINPUT_VERSION,
						IID_IDirectInput8, (void**)&m_pInput, NULL)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "DirectInput8Createに失敗");
				}

			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			DeviceManager::~DeviceManager()
			{
				SAFE_RELEASE(m_pInput);
			}

			//-----------------------------------------------------------
			// RegisterDevice
			//-----------------------------------------------------------
			void DeviceManager::RegisterDevice(Device* _pDevice)
			{
				m_DeviceList.AddRequest(_pDevice);
			}

			//-----------------------------------------------------------
			// UnRegisterDevice
			//-----------------------------------------------------------
			void DeviceManager::UnRegisterDevice(Device* _pDevice)
			{
				m_DeviceList.RemoveRequest(_pDevice);
			}

			//-----------------------------------------------------------
			// UpdataRegistedDevices
			//-----------------------------------------------------------
			void DeviceManager::UpdataRegistedDevices()
			{
				m_DeviceList.Apply();
				Utility::Estd::for_each(m_DeviceList.Vector,
					[&](Device* _pDevice) {_pDevice->Updata(); });
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------