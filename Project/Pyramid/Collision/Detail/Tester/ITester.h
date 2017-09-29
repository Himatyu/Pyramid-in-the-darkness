/**
* @file		ITester.h
* @brief	抽象テスター
* @author	S.OIKAWA
* @date		2017.04.29
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include"Nullable.h"
#include"../DelayEvent.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			class ICollidee;
			class ColliderManager;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			namespace Tester
			{
				/// <summary>
				///	抽象テスタ
				/// </summary>
				class ITester
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					ITester(ColliderManager&);
					virtual ~ITester() = default;

					ITester(const ITester&) = default;
					ITester(ITester&&) = default;

					ITester& operator=(const ITester&) = default;
					ITester& operator=(ITester&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					virtual Utility::Nullable<EventPair> Run(ICollidee*, ICollidee*) = 0;
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
				protected:
					ColliderManager&		m_ColliderManager;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------