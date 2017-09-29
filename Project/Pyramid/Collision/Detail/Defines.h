/**
* @file		Defines.h
* @brief	�Փ˔���ɔ�������J��`
* @author	S.OIKAWA
* @date		2017.04.11
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"DelayEvent.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		class HitResult;
		class IVolume;
		namespace Detail
		{
			class ICollidee;

			using ResultPair = std::pair<HitResult, HitResult>;
			using EventPair = std::pair<DelayEvent, DelayEvent>;
		}
	}
}
#pragma endregion



//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------