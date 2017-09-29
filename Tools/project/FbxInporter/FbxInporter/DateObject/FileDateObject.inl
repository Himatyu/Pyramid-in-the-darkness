/**
* @file		FileDateObject.inl
* @brief	ファイルデータオブジェクトを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FileDateObject.h"

//-----------------------------------------------------------
// Read 
//-----------------------------------------------------------
template<class Ty>
inline void FileDateObjectChild::Read(Ty _pData, size_t _Size)
{
	rootStream.read((char*)_pData, _Size);
}

//-----------------------------------------------------------
// Write
//-----------------------------------------------------------
template<class Ty>
inline void DataObject::FileDateObjectChild::Write(Ty _pData, size_t _Size)
{
	rootStream.write((char*)_pData, _Size);
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
