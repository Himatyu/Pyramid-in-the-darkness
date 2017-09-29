/**
* @file		Base.h
* @brief	パブリッシャーのベース
* @author	S.OIKAWA
* @date		2017.06.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TypeHolder.h"
#include"Abstract.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			namespace Publisher
			{
				/// <summary>
				///パブリッシャーのベース
				/// </summary>
				template<class EventListener>
				class Base : 
					public ::Utility::TypeHolder<EventListener>,
					public Abstract
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Base() = default;
					~Base() = default;

					Base(const Base&) = default;
					Base(Base&&) = default;

					Base& operator=(const Base&) = default;
					Base& operator=(Base&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

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
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------