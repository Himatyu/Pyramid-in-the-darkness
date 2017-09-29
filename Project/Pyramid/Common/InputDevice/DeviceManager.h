/**
* @file		DeviceManager.h
* @brief	���̓f�o�C�X���Ǘ�
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
			/// ���̓f�o�C�X���Ǘ�
			/// Dx�f�o�C�X�̐����ƍX�V���s��
			/// RAII�ɏ�����R���X�g���N�^�Ńf�o�C�X���쐬����
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
				/// �f�o�C�X�̓o�^
				/// </summary>
				void RegisterDevice(Device*);

				/// <summary>
				/// �f�o�C�X�̓o�^�폜
				/// </summary>
				void UnRegisterDevice(Device*);

				/// <summary>
				/// �f�o�C�X���X�V����
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