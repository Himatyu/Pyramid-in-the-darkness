/**
	  * @file		FileDateObjectRoot.cpp
	  * @brief		ファイルデータオブジェクト実装
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "FileDateObject.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	//-----------------------------------------------------------
	// ctor 
	//-----------------------------------------------------------
	FileDateObjectRoot::FileDateObjectRoot(std::string filePath):
		fileName(filePath)
	{
	}

	//-----------------------------------------------------------
	// dtor
	//-----------------------------------------------------------
	FileDateObjectRoot::~FileDateObjectRoot()
	{
	}

	FileDateObjectChild::FileDateObjectChild(std::fstream & _rootStream):
		rootStream(_rootStream)
	{
	}
	FileDateObjectChild::~FileDateObjectChild()
	{
	}
	  }
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------