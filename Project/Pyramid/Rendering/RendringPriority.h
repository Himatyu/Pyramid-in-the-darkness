/**
* @file		RendringPriority.h
* @brief	レンダリング時のプライオリティ
* @author	S.OIKAWA
* @date		2016.12.13
*/

#pragma once
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		/// <summary>
		/// レンダリング時のプライオリティ
		/// </summary>
		enum RendringPriority : UINT
		{
			Background = 1000,		//スカイボックスとか
			Geometry = 2000,		//不透明オブジェクト
			Transparent = 4000,	//半透明オブジェクト
			Overlay = 6000			//uiなど
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------