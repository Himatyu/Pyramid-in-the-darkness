/**
* @file		FirearmsControler.h
* @brief	プレイヤーとの火器管制を行う
* @author	S.OIKAWA
* @date		2017.02.14
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Includer.h"
#include"../App/Player.h"
#include"../App/Extension/Component/PlayerModule.h"
#include<vector>
#include<utility>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace App
	{
		namespace Weapon
		{
			class WeaponBase;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Component
			{
				/// <summary>
				/// プレイヤーとの火器管制を行う
				/// </summary>
				class FirearmsControler:
					public PlayerModule
				{
					using WeaponData =
						std::tuple<Weapon::WeaponBase*, int,bool/*Key入力かどうか*/>;
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					FirearmsControler(Object::Actor*);
					FirearmsControler();
					~FirearmsControler();

					FirearmsControler(const FirearmsControler&) = default;
					FirearmsControler(FirearmsControler&&) = default;

					FirearmsControler& operator=(const FirearmsControler&) = default;
					FirearmsControler& operator=(FirearmsControler&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					void Init()			override;
					void Updata()		override;
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
					std::vector<WeaponData*>			m_WeaponList;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------