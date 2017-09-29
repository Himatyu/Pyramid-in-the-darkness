/**
* @file		Key.h
* @brief	キーボードの入力を扱う
* @author	S.OIKAWA
* @date		2017.02.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Device.h"
#include"singleton.h"
#include"TypeList.h"
#include"NullType.h"
#include<Windows.h>
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Common
	{
		namespace InputDevice
		{
			/// <summary>
			/// キーボードの入力を扱う
			/// </summary>
			class Key :
				public Utility::Singleton<Key>,
				public Device
			{

			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Key();
				~Key();

				Key(const Key&) = default;
				Key(Key&&) = default;

				Key& operator=(const Key&) = default;
				Key& operator=(Key&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// キーが押されていれば真を返す
				/// </summary>
				bool IsKeyPush(int _Dik);

				/// <summary>
				/// キーの押されたフレームのみ真を返す
				/// </summary>
				bool IsKeyDown(int _Dik);

				/// <summary>
				/// キーの離されたフレームのみ真を返す
				/// </summary>
				bool IsKeyUp(int _Dik);

				/// <summary>
				/// 複数のキーが同時に押されていれば真を返す
				/// </summary>
				template<class First, class ...Param>
				bool IsKeyPushs(First, Param...);

				/// <summary>
				/// 複数のキーが同時に押されたフレームのみ真を返す
				/// </summary>
				template<class First, class ...Param>
				bool IsKeyDowns(First, Param...);

				/// <summary>
				/// 複数のキーが同時に離されたフレームのみ真を返す
				/// </summary>
				template<class First, class ...Param>
				bool IsKeyUps(First, Param...);

			private:
				void SetUp() override;
				void Updata() override;

				bool IsKeyPushs();
				bool IsKeyDowns();
				bool IsKeyUps();
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::array<BYTE, 256>	m_KeyState;
				std::array<BYTE, 256>	m_KeyStatePrevFream;
				HWND					m_Hwnd;
#pragma endregion
			};
#include"Key.inl"
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------