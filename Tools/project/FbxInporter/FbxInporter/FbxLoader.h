/**
	  * @file		FbxLoader.h
	  * @brief		FBX読み込み機能を提供
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"singleton.h"
#include"FbxModelFile.h"
#include<memory>
#include<string>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

/// <summary>
/// Fbxを読み込む
/// </summary>
class FbxLoader : 
	public Singleton<FbxLoader>
{
public:
	FbxLoader();
	~FbxLoader();

	FbxModelFile* Load(std::string _fileName);

};

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------