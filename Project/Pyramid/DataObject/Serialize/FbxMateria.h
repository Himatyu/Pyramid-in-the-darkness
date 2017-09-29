/**
* @file		FbxMaterial.h
* @brief	FBXのマテリアルシリアライズを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

//-----------------------------------------------------------
// icnlude 
//-----------------------------------------------------------
#include"ISerializable.h"
#include"ColorChannel.h"
#include"../FileDataObjectChild.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/FbxMateria.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Serialize
	{
		/// <summary>
		/// FBXのマテリアルデータオブジェクト.
		/// これ単体では扱わず、Fbxのシリアライズの一環として使用すること.
		/// </summary>
		class FbxMaterial final :
			public DTO::DTOAccess<DTO::FbxMaterial>,
			public FileDataObjectChild,
			public ISerializable
		{
		public:
			FbxMaterial(std::fstream& _parentStream);
			~FbxMaterial();

			/// <summary>
			/// カラーチャンネルの書き出し.
			/// すでに開いたストリームに対して書き込む.
			/// 開いていない場合何もしない.
			/// </summary>
			void Serialize() override;

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
