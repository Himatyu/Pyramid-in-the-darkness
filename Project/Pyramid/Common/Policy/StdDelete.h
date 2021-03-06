/**
* @file		StdDelete.h
* @brief	deleteで破棄する
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
			struct StdDelete
			{
				void Delete(Ty* _p) { delete _p; }
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------