/**
* @file		DirectXDelete.h
* @brief	DirectXバッファのリソース開放
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once

//-----------------------------------------------------------
// inlcude 
//-----------------------------------------------------------
#include"../Rendering/Graphics.h"
#include<d3dx9.h>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Common
	{
		namespace Policy
		{
			/// <summary>
			/// DirectXで扱うバッファを開放するポリシー
			/// </summary>
			template<class>
			struct DirectXBufferDaleta
			{
				template<class Ty>
				void Delete(Ty _p)
				{
					SAFE_RELEASE(_p);
				}
			};
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------