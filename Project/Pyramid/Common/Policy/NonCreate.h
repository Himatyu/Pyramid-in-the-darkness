/**
* @file		NonCreate.h
* @brief	生成しないポリシー
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
			/// 生成しないポリシー
			/// </summary>
			template<class>
			struct NonCreate
			{
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------