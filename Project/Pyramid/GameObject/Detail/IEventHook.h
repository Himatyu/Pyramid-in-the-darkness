/**
* @file		IEventHook.h
* @brief	オブジェクト・コンポーネントのイベント提供
* @author	S.OIKAWA
* @date		2016.09.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICommonBehavior.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion
namespace Pyramid
{
	namespace GameObject
	{
		/// <summary>
		/// オブジェクト・コンポーネントの追加イベント.
		/// </summary>
		class IEventHook :
			public ICommonBehavior
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			IEventHook() = default;
			~IEventHook() = default;

			IEventHook(const IEventHook&) = default;
			IEventHook(IEventHook&&) = default;

			IEventHook& operator=(const IEventHook&) = default;
			IEventHook& operator=(IEventHook&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// アップデートの前にコールされる.
			/// </summary>
			virtual void FastUpdata() = 0;

			/// <summary>
			/// アップデートの後にコールされる.
			/// </summary>
			virtual void LateUpdata() = 0;

#pragma endregion
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------