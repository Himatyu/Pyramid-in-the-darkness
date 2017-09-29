/**
* @file		Defines.h
* @brief	Common‚Ì’è‹`
* @author	S.OIKAWA
* @date		2017..02.23
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TextureAnimFream.h"
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		using DiagonalUV = std::array<float, 4>;

		template<class Ty>
		using Sp = std::shared_ptr<Ty>;

		template<class Ty>
		using NullableSp = Utility::Nullable<std::shared_ptr<Ty>>;

		template<class Ty>
		using Wp = std::weak_ptr<Ty>;
	}
}
#pragma endregion

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------