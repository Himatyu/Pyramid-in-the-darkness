/**
* @file		ISerializable.h
* @brief	シリアライズするインターフェースを提供する
* @author	S.OIKAWA
* @date		2016.10.15
*/

#pragma once

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace DataObject
{
	namespace Serialize
	{
		/// <summary>
		/// 書き込みのインターフェース.
		/// </summary>
		__interface ISerializable
		{
			void Serialize();
		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------