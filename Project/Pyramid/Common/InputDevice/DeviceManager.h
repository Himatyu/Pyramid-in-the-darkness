/**
* @file		DeviceManager.h
* @brief	入力デバイスを管理
* @author	S.OIKAWA
* @date		2017.02.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SafetyIterate.h"
#include"singleton.h"
#include<dinput.h>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		namespace InputDevice
		{
			class Device;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Common
	{
		namespace InputDevice
		{
			/// <summary>
			/// 入力デバイスを管理
			/// Dxデバイスの生成と更新を行う
			/// RAIIに乗っ取りコンストラクタでデバイスを作成する
			/// </summary>
			class DeviceManager :
				public Utility::Singleton<DeviceManager>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				DeviceManager();
				~DeviceManager();

				DeviceManager(const DeviceManager&) = default;
				DeviceManager(DeviceManager&&) = default;

				DeviceManager& operator=(const DeviceManager&) = default;
				DeviceManager& operator=(DeviceManager&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// デバイスの登録
				/// </summary>
				void RegisterDevice(Device*);

				/// <summary>
				/// デバイスの登録削除
				/// </summary>
				void UnRegisterDevice(Device*);

				/// <summary>
				/// デバイスを更新する
				/// </summary>
				void UpdataRegistedDevices();
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_CR_R_ONLY(m_pInput, pInput, LPDIRECTINPUT8);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				Utility::SafetyIterate<Device*>		m_DeviceList;
				LPDIRECTINPUT8							m_pInput;
#pragma endregion
			};

		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------