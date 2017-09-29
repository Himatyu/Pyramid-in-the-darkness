/**
* @file		Constant.h
* @brief	App‚Ì’è”‚ğ’è‹`‚·‚é
* @author	S.OIKAWA
* @date		2016.02.24
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

#pragma endregion
namespace Pyramid
{
	namespace App
	{
		/// <summary>
		/// App‚Ì’è”‚ğ’è‹`‚·‚é
		/// </summary>
		class Constant final
		{
		public:
#pragma region value

			//-----------------------------------------------------------
			// 
			//-----------------------------------------------------------
			static const std::string PathOfPlayerModel;
			static const std::string PathOfJetTexture;
			static const std::string PathOfHitoheizuTexture;
			static const float PlayerRotateLimmit;
			static const float PlayerSpeedMax;
			static const float PlayerSpeedMin;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------