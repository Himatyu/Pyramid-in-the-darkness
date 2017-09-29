/**
* @file		FbxMaterial.h
* @brief	FBXのマテリアルデシリアライズを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

//-----------------------------------------------------------
// icnlude 
//-----------------------------------------------------------
#include"IDeserializable.h"
#include"ColorChannel.h"
#include"../FileDataObjectChild.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/FbxMateria.h"
#include<fstream>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Deserialize
	{
		/// <summary>
		/// FBXのマテリアルデータオブジェクト.
		/// これ単体では扱わず、Fbxのシリアライズの一環として使用すること.
		/// </summary>
		class FbxMaterial final :
			public DTO::DTOAccess<DTO::FbxMaterial>,
			public FileDataObjectChild,
			public IDeserializable
		{
		public:
			FbxMaterial(std::fstream& _parentStream);
			~FbxMaterial();

			/// <summary>
			/// カラーチャンネルの書き出し.
			/// すでに開いたストリームに対して書き込む.
			/// 開いていない場合何もしない.
			/// </summary>
			void Deserialize() override;

		private:
			ColorChannel m_Emissive;
			ColorChannel m_Ambient;
			ColorChannel m_Diffuse;
			ColorChannel m_Specular;
			ColorChannel m_Bump;
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
