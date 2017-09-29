/**
	  * @file	FbxAndBMInterconverter.h
	  * @brief	FbxとBMを相互変換する機能を提供
	  * @author	S.OIKAWA
	  * @date	2016.10.15
	  */

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxLoader.h"
#include"FbxModelFile.h"
#include"DateObject\DOFbxFile.h"
#include"singleton.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

/// <summary>
/// FbxとBMを相互変換する.
/// 変換元ファイルから変換後ファイルを生成する
/// </summary>
class FbxAndBMInterconverter : 
	public Singleton<FbxAndBMInterconverter>
{
public:
	FbxAndBMInterconverter() {}
	~FbxAndBMInterconverter() {}

	/// <summary>
	/// FbxModelFileを元にDOを作る.
	/// FbxModelFileは解放される
	/// </summary>
	DataObject::POCO::Serialize::FbxFile *
		ToSerializeFile(FbxModelFile* _serializeFile);

	/// <summary>
	/// DOを元にFbxModelFileを作成する
	/// DOは解放される
	/// </summary>
	FbxModelFile* ToFbxModelFile(DataObject::POCO::Deserialize::FbxFile* _deserializedFile);
};

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------