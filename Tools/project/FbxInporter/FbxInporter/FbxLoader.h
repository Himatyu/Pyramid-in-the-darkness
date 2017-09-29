/**
	  * @file		FbxLoader.h
	  * @brief		FBX�ǂݍ��݋@�\���
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
/// Fbx��ǂݍ���
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