/**
* @file		TestLevel.h
* @brief
* @author
* @date
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Blueprint/Level.h"
#include"../App/Player.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion
namespace Pyramid
{
	class TestLevel :
		public Blueprint::Level
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		TestLevel();
		~TestLevel() = default;

		TestLevel(const TestLevel&) = default;
		TestLevel(TestLevel&&) = default;

		TestLevel& operator=(const TestLevel&) = default;
		TestLevel& operator=(TestLevel&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		/// <summary>
		/// çXêV.
		/// </summary>
		virtual void Updata();

		/// <summary>
		/// ï`âÊ.
		/// </summary>
		virtual void Draw();
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
		App::Player*			m_pPlayer;
		GameObject::Object*					m_pObject;

#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------