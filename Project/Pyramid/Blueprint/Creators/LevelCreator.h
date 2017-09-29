/**
* @file		LevelCreator.h
* @brief	ƒŒƒxƒ‹¶¬ŠÖ”‚ğ’ñ‹Ÿ‚·‚é
* @author	S.OIKAWA
* @date		2016.10.10
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Creator.h"
#include"../Level.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Blueprint
	{
		namespace Creators
		{
			/// <summary>
			/// ƒŒƒxƒ‹¶¬ŠÖ”‚ğ’ñ‹Ÿ.
			/// </summary>
			template<class Child, class Parent = Level*>
			class LevelCreator final :
				public Utility::Creator<Parent>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				LevelCreator() = default;
				~LevelCreator() = default;

				LevelCreator(const LevelCreator&) = default;
				LevelCreator(LevelCreator&&) = default;

				LevelCreator& operator=(const LevelCreator&) = default;
				LevelCreator& operator=(LevelCreator&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				Parent Create() override;
#pragma endregion

			};
#include"LevelCreator.inl"

		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


