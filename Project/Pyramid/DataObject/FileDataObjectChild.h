/**
* @file		FileDataObjectChild.h
* @brief	�t�@�C���f�[�^�̎q���
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
	/// �t�@�C���f�[�^�I�u�W�F�N�g�̎q.
	/// ���[�g���Ǘ�����X�g���[���̎Q�Ƃ����̂ŋ@�\�͐�������
	/// </summary>
	class FileDataObjectChild
	{
	public:
		FileDataObjectChild(std::fstream& _rootStream);
		virtual ~FileDataObjectChild();

	protected:
		/// <summary>
		/// �e���v���[�g�^�̓ǂݍ���
		/// </summary>
		template<class Ty>
		void Read(Ty _pData, size_t _Size);

		/// <summary>
		/// �e���v���[�g�^�̏�������
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