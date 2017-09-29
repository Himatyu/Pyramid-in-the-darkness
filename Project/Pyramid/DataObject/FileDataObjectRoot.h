/**
* @file		FileDataObjectRoot.h
* @brief	ファイルデータの親を提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<string>
#include<fstream>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	/// <summary>
	/// ファイルデータオブジェクトのルート.
	/// ストリームを管理するのでフルアクセスが可能
	/// </summary>
	class FileDataObjectRoot 
	{
	public:
		FileDataObjectRoot(std::string filePath);
		virtual ~FileDataObjectRoot();

	protected:
		std::fstream		m_FileStream;
		std::string			m_FilePath;
	};
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------