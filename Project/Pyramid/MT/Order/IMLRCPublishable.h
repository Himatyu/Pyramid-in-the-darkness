/**
* @file		IMLRCPublishable.h
* @brief	MLRCを発行するインターフェース
* @author	S.OIKAWA
* @date		2016.11.25
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
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				class MLRC;
			}
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace MT
	{
		namespace Order
		{
			__interface IMLRCPublishable
			{
				Rendering::Detail::Optimize::MLRC* PublishMLRC();
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------