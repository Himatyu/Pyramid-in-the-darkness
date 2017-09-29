/**
* @file		FirearmsControler.cpp
* @brief	プレイヤーとの火器管制を行う
* @author	S.OIKAWA
* @date		2017.02.14
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"FirearmsControler.h"
#include"../App/Weapon/WeaponBase.h"
#include"../App/Weapon/Vulcan.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Component
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				FirearmsControler::FirearmsControler(Object::Actor * _pPlayer):
					PlayerModule(_pPlayer)
				{
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				FirearmsControler::FirearmsControler():
					PlayerModule(nullptr)
				{
				}

				//-----------------------------------------------------------
				// dtor
				//-----------------------------------------------------------
				FirearmsControler::~FirearmsControler()
				{
					for (auto& _ : m_WeaponList)
					{
						SAFE_DELETE(std::get<0>(*_));
						SAFE_DELETE(_);
					}
				}

				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void FirearmsControler::Init()
				{
					PlayerModule::Init();
					auto vulcan = new Weapon::Vulcan(m_pPlayer);
					vulcan->Init();
					m_WeaponList.push_back(new WeaponData{ vulcan,DIK_SPACE,true});

				}

				//-----------------------------------------------------------
				// Updata
				//-----------------------------------------------------------
				void FirearmsControler::Updata()
				{
					auto& key = Common::InputDevice::Key::Instantiate();
					auto& mouse = Common::InputDevice::Mouse::Instantiate();

					for (auto& _ : m_WeaponList)
					{
						if (std::get<2>(*_))
						{
							if (key.IsKeyPush(std::get<1>(*_)))
							{
								std::get<0>(*_)->Fire();
								continue;
							}
						}
						else
						{
							if (mouse.IsDownButton(
								static_cast<Common::InputDevice::Mouse::Id>(
									std::get<1>(*_))))
							{
								std::get<0>(*_)->Fire();
								continue;
							}
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