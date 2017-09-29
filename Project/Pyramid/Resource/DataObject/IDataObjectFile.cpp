/**
* @file		IDataObjectFile.cpp
* @brief	固定値データをリソースとして扱う
* @author	S.OIKAWA
* @date		2017.05.12
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IDataObjectFile.h"
#include<iostream>
#include<fstream>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace std;
namespace Pyramid
{
	namespace Resources
	{
		namespace DataObject
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			IDataObjectFile::IDataObjectFile(
				size_t _size, void * _pHead):
				m_Size(_size),
				m_pDataHead(_pHead)
			{
			}

			//-----------------------------------------------------------
			// Read
			//-----------------------------------------------------------
			void IDataObjectFile::Read(std::string _path)
			{
				SetFilePathInfo(_path);
				std::fstream fst;
				fst.open(_path.c_str(), ios::in | ios::binary);
				
				if (!fst)
				{
					___D_LOG(_path+" : の読み込みに失敗");
					return;
				}

				if (!IsMatchOfFileSizeAndTheTypeFile(fst))
				{
					___D_LOG(_path + " : ファイルサイズと指定された型サイズの不一致");
					return;
				}

				fst.read(reinterpret_cast<char*>(m_pDataHead),m_Size);

				fst.close();
			}

			//-----------------------------------------------------------
			// IsFileSizeEqual
			//-----------------------------------------------------------
			bool IDataObjectFile::IsMatchOfFileSizeAndTheTypeFile(std::fstream& fst)
			{
				fst.seekg(0, std::ios::end);
				auto enf = fst.tellg();
				fst.clear();
				fst.seekg(0, std::ios::beg);
				auto head = fst.tellg();
				auto size = enf - head;
				fst.clear();

				return (m_Size == size);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------