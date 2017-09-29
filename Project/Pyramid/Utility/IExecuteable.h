/**
* @file		IMTExecuteable.h
* @brief	マルチスレッドでジョブに実行されるタスクインターフェース.
* @author	S.OIKAWA
* @date		2016.09.21
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
#pragma endregion

namespace Utility
{
	/// <summary>
	/// マルチスレッドでジョブに実行されるタスクインターフェース
	/// </summary>
	class IExecuteable
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		IExecuteable() = default;
		virtual ~IExecuteable() = default;

		IExecuteable(const IExecuteable&) = default;
		IExecuteable(IExecuteable&&) = default;

		IExecuteable& operator=(const IExecuteable&) = default;
		IExecuteable& operator=(IExecuteable&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		virtual void Execution() = 0;
#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
	};
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------