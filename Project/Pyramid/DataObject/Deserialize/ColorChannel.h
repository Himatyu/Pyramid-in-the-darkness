/**
* @file		ColorChannel.h
* @brief		カラーチャンネルのデシリアライズ
* @author		S.OIKAWA
* @date		2016.10.15
*/

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"IDeserializable.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/ColorChannel.h"
#include"../FileDataObjectChild.h"

#include<vector>
#include<fstream>
#include<string>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Deserialize
	{
		/// <summary>
		/// 書き出し用のカラーチャンネルデータオブジェクト.
		/// これ単体では扱わず、Fbxのシリアライズの一環として使用すること.
		/// </summary>
		class ColorChannel final :
			public DTO::DTOAccess<DTO::ColorChannel>,
			public FileDataObjectChild,
			public IDeserializable
		{
		public:
			ColorChannel(std::fstream& _parentStream);
			~ColorChannel();

			/// <summary>
			/// カラーチャンネルの書き出し.
			/// すでに開いたストリームに対して書き込む.
			/// 開いていない場合何もしない.
			/// </summary>
			void Deserialize() override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------