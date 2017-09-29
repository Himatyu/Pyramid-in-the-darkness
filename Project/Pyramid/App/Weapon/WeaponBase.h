/**
* @file		WeaponBase.h
* @brief	武器の基本機能
* @author	S.OIKAWA
* @date		2017.02.15
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Object
			{
				class Actor;
			}
		}
	}
}
#pragma endregion
namespace Pyramid
{
	namespace App
	{
		namespace Weapon
		{
			/// <summary>
			/// 武器の基本機能
			/// </summary>
			class WeaponBase
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				WeaponBase(Extension::Object::Actor*);
				virtual ~WeaponBase() = default;

				WeaponBase(const WeaponBase&) = default;
				WeaponBase(WeaponBase&&) = default;

				WeaponBase& operator=(const WeaponBase&) = default;
				WeaponBase& operator=(WeaponBase&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void Fire() = 0;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion
			protected:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				Extension::Object::Actor*	m_pPlayer;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------