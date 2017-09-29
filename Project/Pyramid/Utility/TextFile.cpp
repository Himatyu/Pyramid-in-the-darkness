/**
* @file	TextFile.cpp
* @brief	TextFile����
* @author	S.OIKAWA
* @date	2016/4/22
*/

//-----------------------------------------------------------
// �C���N���[�h
//-----------------------------------------------------------
#include<fstream>
#include "TextFile.h"

//-----------------------------------------------------------
// �錾
//-----------------------------------------------------------
namespace Utility
{
	using namespace std;

	//-----------------------------------------------------------
	// �R���X�g���N�^
	//-----------------------------------------------------------

	TextFile::TextFile(std::string _Path) :
		File(_Path) {	}


	//-----------------------------------------------------------
	//	�ǂݍ���
	//-----------------------------------------------------------
	void TextFile::Read(std::string _path)
	{
		SetFilePathInfo(_path);
		ifstream ifs(m_FilePath);

		if (ifs.fail())
		{//���s
			___THROW_EXCEPTION_POINT(Exception, "�t�@�C���X�g���[���̐����Ɏ��s : " + m_FileName);
		}

		//�t�@�C���̊J�n����I���܂ł��o�b�t�@�ɃZ�b�g
		istreambuf_iterator<char> it(ifs);
		istreambuf_iterator<char> last;
		m_Buffer = string(it, last);
	}

	//-----------------------------------------------------------
	// ��������
	//-----------------------------------------------------------
	void TextFile::Write(std::string _path)
	{
		SetFilePathInfo(_path);
		//��C�ɏ����o��
		if (m_Buffer.empty())
		{
			return;
		}
		ofstream ofs(m_FilePath);
		ofs << m_Buffer << endl;
	}
}
//-----------------------------------------------------------
//�@EOF
//-----------------------------------------------------------
