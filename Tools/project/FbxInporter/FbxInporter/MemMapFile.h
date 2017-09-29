// MemMapFile.h (2006. 10. 13)

// �������}�b�v�h�t�@�C���N���X�錾��
#pragma once

#include <windows.h>

///////////////////////////////////
// �������}�b�v�h�t�@�C���N���X
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

   // �t�@�C���I�[�v��
   virtual bool Open( char* filename, DWORD rwflag=GENERIC_READ | GENERIC_WRITE, DWORD openflag=OPEN_EXISTING);

   // �t�@�C���|�C���^�擾
   virtual bool GetPtr( void** ptr , char* subfilename=NULL, DWORD *pfilesize=NULL );
};
