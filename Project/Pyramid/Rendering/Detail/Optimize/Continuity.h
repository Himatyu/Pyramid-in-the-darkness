/**
* @file		Continuity.h
* @brief	連続性を定義
* @author	S.OIKAWA
* @date		2017.03.28
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
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				/// <summary>
				/// 連続性を定義
				/// </summary>
				enum Continuity : int
				{
					Head,
					Middle,
					Tail,
					None
				};
			}
		}
	}
}
#pragma endregion
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------