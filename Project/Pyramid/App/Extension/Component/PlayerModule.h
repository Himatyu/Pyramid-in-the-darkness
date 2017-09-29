/**
* @file		PlayerModule.h
* @brief	プレイヤーに追加されるコンポーネント
* @author	S.OIKAWA
* @date		2017.02.15
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Includer.h"
#include"../Object/Actor.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

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
				/// プレイヤーに追加されるコンポーネント
				/// InitでpOwnerからキャストしたpPlayerをキャッシュする
				/// </summary>
				class PlayerModule : 
					public Components::Component
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					PlayerModule(Object::Actor*);
					~PlayerModule() = default;

					PlayerModule(const PlayerModule&) = default;
					PlayerModule(PlayerModule&&) = default;

					PlayerModule& operator=(const PlayerModule&) = default;
					PlayerModule& operator=(PlayerModule&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					void Init() override;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
					PROPERTY(m_pPlayer, pPlayer, Object::Actor*);
#pragma endregion
				protected:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
					Object::Actor*			m_pPlayer;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------