/**
* @file		Abstract.h
* @brief	抽象イベント発行者
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IUnknown.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace UI
	{
		class IUI;
	}
}
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
				/// 抽象イベント発行者
				/// </summary>
				class Abstract
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Abstract() = default;
					virtual ~Abstract() = default;

					Abstract(const Abstract&) = default;
					Abstract(Abstract&&) = default;

					Abstract& operator=(const Abstract&) = default;
					Abstract& operator=(Abstract&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					virtual void InspectAndPublish() = 0;
					virtual void AddListener(IUI*,::Utility::IUnknown*) = 0;
					virtual void RemoveListener(IUI*,::Utility::IUnknown*) = 0;
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