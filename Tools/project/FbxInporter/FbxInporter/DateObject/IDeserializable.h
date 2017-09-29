/**
	  * @file		IDeserializable.h
	  * @brief		書き込みのインターフェースを提供
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */

#pragma once

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace POCO
	{
		/// <summary>
		/// 書き込みインターフェース
		/// </summary>
		__interface IDeserializable
		{
			void Deserialize();
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------