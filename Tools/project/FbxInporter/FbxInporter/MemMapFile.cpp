// MemMapFile.cpp (2006. 10. 13)

#include "MemMapFile.h"


// �������}�b�v�h�t�@�C��������

CMemMapFile::CMemMapFile()
{
	m_hFile = INVALID_HANDLE_VALUE;
	m_hMap = 0;
	m_pPointer = NULL;
	m_dwFileSize = 0;
}


CMemMapFile::~CMemMapFile()
{
	UnmapViewOfFile( m_pPointer );
	if( m_hMap != 0 )
		CloseHandle( m_hMap );
	if( m_hFile != INVALID_HANDLE_VALUE )
		CloseHandle( m_hFile );
}

// �t�@�C���I�[�v��
bool CMemMapFile::Open( char* filename, DWORD rwflag, DWORD openflag)
{
   // �t�@�C���I�[�v��
   m_hFile = CreateFile( filename, rwflag, 0, 0, openflag, 0, 0 );
   if( m_hFile == INVALID_HANDLE_VALUE )
      return false;

   // �t�@�C���}�b�s���O�I�u�W�F�N�g���쐬
   DWORD mapflag = PAGE_READWRITE;
   if( rwflag == GENERIC_READ )
      mapflag = PAGE_READONLY;   // �ǂݍ��ݐ�p�ɐݒ�
   m_hMap = CreateFileMapping( m_hFile, 0, mapflag, 0, 0, filename );
   if( m_hMap <= 0 ){
      CloseHandle( m_hFile );
	  m_hFile = INVALID_HANDLE_VALUE;
      return false;
   }

   // �|�C���^���擾
   DWORD mapviewflag = FILE_MAP_WRITE;
   if( mapflag == PAGE_READONLY )
      mapviewflag = FILE_MAP_READ;
   m_pPointer = (char*)MapViewOfFile( m_hMap, mapviewflag, 0, 0, 0);
   if( m_pPointer == NULL){
     CloseHandle( m_hMap );
     CloseHandle( m_hFile );
	  m_hMap = 0;
	  m_hFile = INVALID_HANDLE_VALUE;
      return false;
   }

   // �t�@�C���T�C�Y���擾
   DWORD high;
   m_dwFileSize = ::GetFileSize( m_hFile, &high );

   return true;
}

// �t�@�C���|�C���^�擾
bool CMemMapFile::GetPtr( void** ptr, char* subfilename, DWORD *pfilesize )
{
	*ptr = m_pPointer;
	if(pfilesize != NULL)
	*pfilesize = m_dwFileSize;   // �S�t�@�C���T�C�Y��Ԃ�
	return true;
}