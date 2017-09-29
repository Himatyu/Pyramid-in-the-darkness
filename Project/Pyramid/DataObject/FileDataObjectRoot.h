/**
* @file		FileDataObjectRoot.h
* @brief	�t�@�C���f�[�^�̐e���
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
	/// �t�@�C���f�[�^�I�u�W�F�N�g�̃��[�g.
	/// �X�g���[�����Ǘ�����̂Ńt���A�N�Z�X���\
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