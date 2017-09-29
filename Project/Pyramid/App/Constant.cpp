/**
* @file		Constant.cpp
* @brief	App‚Ì’è”‚ğ’è‹`‚·‚é
* @author	S.OIKAWA
* @date		2016.02.24
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
	namespace App
	{
		const std::string Constant::PathOfPlayerModel = "Assets/Model/x-wing.bm";
		const std::string Constant::PathOfJetTexture = "Assets/Texture/circle2.png";
		const std::string Constant::PathOfHitoheizuTexture = "Assets/Texture/Hitoheizu.bmp";

		const float Constant::PlayerRotateLimmit = 60;
		const float Constant::PlayerSpeedMax = 10.0f;
		const float Constant::PlayerSpeedMin = 0.0001f;
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------