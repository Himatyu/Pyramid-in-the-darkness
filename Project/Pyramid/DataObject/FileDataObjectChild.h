/**
* @file		FileDataObjectChild.h
* @brief	ファイルデータの子を提供
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
	/// ファイルデータオブジェクトの子.
	/// ルートが管理するストリームの参照を持つので機能は制限する
	/// </summary>
	class FileDataObjectChild
	{
	public:
		FileDataObjectChild(std::fstream& _rootStream);
		virtual ~FileDataObjectChild();

	protected:
		/// <summary>
		/// テンプレート型の読み込み
		/// </summary>
		template<class Ty>
		void Read(Ty _pData, size_t _Size);

		/// <summary>
		/// テンプレート型の書き込み
		/// </summary>
		template<class Ty>
		void Write(Ty _pData, size_t _Size);

		std::fstream& m_RootStream;
	};
#include"FileDataObjectChild.inl"
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------