/**
* @file		ColorChannel.h
* @brief	カラーチャンネルシリアライズ提供
* @author	S.OIKAWA
* @date		2016.10.15
*/

#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"ISerializable.h"
#include"../FileDataObjectChild.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/ColorChannel.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Serialize
	{
		/// <summary>
		/// 書き出し用のカラーチャンネルデータオブジェクト.
		/// これ単体では扱わず、Fbxのシリアライズの一環として使用すること.
		/// </summary>
		class ColorChannel final :
			public DTO::DTOAccess<DTO::ColorChannel>,
			public FileDataObjectChild,
			public ISerializable
		{
		public:
			ColorChannel(std::fstream& _parentStream);
			~ColorChannel();

			/// <summary>
			/// カラーチャンネルの書き出し.
			/// すでに開いたストリームに対して書き込む.
			/// 開いていない場合何もしない.
			/// </summary>
			void Serialize() override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------