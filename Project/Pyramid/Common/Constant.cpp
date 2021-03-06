/**
* @file		Constant.cpp
* @brief	Commonの定数を定義する
* @author	S.OIKAWA
* @date		2016.11.28
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Constant.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		const UINT Constant::TimerServerMTUpdataLineID = 0;

		const std::string Constant::MTUpdataGrupName = "Updata";
		const std::string Constant::MTDrawGrupName = "Draw";

		const unsigned Constant::OctreeMaxLevel = 9;
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------