/**
* @file		StdCreate.h
* @brief	newで作成するポリシー
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once

namespace Pyramid
{
	namespace Common
	{
		namespace Policy
		{
			/// <summary>
			/// newで作成するポリシー
			/// </summary>
			template<class Ty>
			struct StdCreate
			{
				Ty* Create() { return new Ty; }
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------