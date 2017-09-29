/**
	  * @file		FileDateObject.h
	  * @brief		ファイルデータオブジェクトを提供
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<string>
#include<fstream>
#include<vector>
#include<string>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	/// <summary>
	/// ファイルデータオブジェクトのルート.
	/// ストリームを管理するのでフルアクセスが可能
	/// </summary>
	class FileDateObjectRoot
	{
	public:
		FileDateObjectRoot(std::string filePath);
		virtual ~FileDateObjectRoot();

	protected:
		std::fstream		fileStream;
		std::string			fileName;
	};

	/// <summary>
	/// ファイルデータオブジェクトの子.
	/// ルートが管理するストリームの参照を持つので機能は制限する
	/// </summary>
	class FileDateObjectChild
	{
	public:
		FileDateObjectChild(std::fstream& _rootStream);
		virtual ~FileDateObjectChild();

	protected:
		template<class Ty>
		void Read(Ty _pData,size_t _Size);

		template<class Ty>
		void Write(Ty _pData, size_t _Size);

	protected:
		std::fstream& rootStream;
	};
#include"FileDateObject.inl"
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
