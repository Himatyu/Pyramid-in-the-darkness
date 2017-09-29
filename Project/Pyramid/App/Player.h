/**
* @file		Player.h
* @brief	プレイヤー
* @author	S.OIKAWA
* @date		2017.02.13
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../App/Extension/Object/Actor.h"
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
		/// <summary>
		/// プレイヤー
		/// </summary>
		class Player :
			public Extension::Object::Actor
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			Player(Blueprint::Level*);
			~Player() = default;

			Player(const Player&) = default;
			Player(Player&&) = default;

			Player& operator=(const Player&) = default;
			Player& operator=(Player&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// 初期化を行う
			/// </summary>
			void Initialize(Extension::Object::Actor*);
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
			PROPERTY(m_pCamera, pCamera, Extension::Object::Actor*);
#pragma endregion
		private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			Extension::Object::Actor*		m_pCamera;
#pragma endregion
		};

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------