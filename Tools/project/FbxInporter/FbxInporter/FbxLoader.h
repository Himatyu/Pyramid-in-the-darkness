/**
	  * @file		FbxLoader.h
	  * @brief		FBXì«Ç›çûÇ›ã@î\ÇíÒãü
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
/// FbxÇì«Ç›çûÇﬁ
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