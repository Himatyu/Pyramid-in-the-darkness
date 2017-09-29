/**
* @file		FileDataObjectChild.inl
* @brief	ファイルデータの子
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FileDataObjectChild.h"

//-----------------------------------------------------------
// Read 
//-----------------------------------------------------------
template<class Ty>
inline void FileDataObjectChild::Read(Ty _pData, size_t _Size)
{
	m_RootStream.read((char*)_pData, _Size);
}

//-----------------------------------------------------------
// Write
//-----------------------------------------------------------
template<class Ty>
inline void FileDataObjectChild::Write(Ty _pData, size_t _Size)
{
	m_RootStream.write((char*)_pData, _Size);
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
