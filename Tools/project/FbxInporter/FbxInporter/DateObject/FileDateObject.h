/**
	  * @file		FileDateObject.h
	  * @brief		�t�@�C���f�[�^�I�u�W�F�N�g���
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<string>
#include<fstream>
#include<vector>
#include<string>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	/// <summary>
	/// �t�@�C���f�[�^�I�u�W�F�N�g�̃��[�g.
	/// �X�g���[�����Ǘ�����̂Ńt���A�N�Z�X���\
	/// </summary>
	class FileDateObjectRoot
	{
	public:
		FileDateObjectRoot(std::string filePath);
		virtual ~FileDateObjectRoot();

	protected:
		std::fstream		fileStream;
		std::string			fileName;
	};

	/// <summary>
	/// �t�@�C���f�[�^�I�u�W�F�N�g�̎q.
	/// ���[�g���Ǘ�����X�g���[���̎Q�Ƃ����̂ŋ@�\�͐�������
	/// </summary>
	class FileDateObjectChild
	{
	public:
		FileDateObjectChild(std::fstream& _rootStream);
		virtual ~FileDateObjectChild();

	protected:
		template<class Ty>
		void Read(Ty _pData,size_t _Size);

		template<class Ty>
		void Write(Ty _pData, size_t _Size);

	protected:
		std::fstream& rootStream;
	};
#include"FileDateObject.inl"
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
