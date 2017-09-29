// MemMapFile.h (2006. 10. 13)

// メモリマップドファイルクラス宣言部
#pragma once

#include <windows.h>

///////////////////////////////////
// メモリマップドファイルクラス
///////////
class CMemMapFile
{
protected:
   HANDLE m_hFile;
   HANDLE m_hMap;
   void* m_pPointer;
   DWORD m_dwFileSize;

public:
   CMemMapFile();
   virtual ~CMemMapFile();

   // ファイルオープン
   virtual bool Open( char* filename, DWORD rwflag=GENERIC_READ | GENERIC_WRITE, DWORD openflag=OPEN_EXISTING);

   // ファイルポインタ取得
   virtual bool GetPtr( void** ptr , char* subfilename=NULL, DWORD *pfilesize=NULL );
};
