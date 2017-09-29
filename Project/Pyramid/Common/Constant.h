/**
* @file		Constant.h
* @brief	Commonの定数を定義する
* @author	S.OIKAWA
* @date		2016.11.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<windef.h>
#include<string>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Common
	{		
		class Constant final
		{
		public:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
			/// <summary>
			/// タイムサーバ用の更新ID
			/// </summary>
			const static UINT TimerServerMTUpdataLineID;

			/// <summary>
			///	Updataタスクのグループ名
			/// </summary>
			static const std::string MTUpdataGrupName;

			/// <summary>
			/// Drawタスクのグループ名
			/// </summary>
			static const std::string MTDrawGrupName;

			/// <summary>
			///	八分木の最大分解レベル。
			/// 型的に9
			/// </summary>
			static const unsigned OctreeMaxLevel;

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------