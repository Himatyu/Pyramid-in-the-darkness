/**
* @file		File.��
* @brief	�t�@�C���N���X
* @author	S.OIKAWA
* @date		2016/4/22
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	/// <summary>
	/// �t�@�C���x�[�X�N���X.
	/// </summary>
	class File
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
		File() = default;

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="_Filename">�t�@�C����</param>
		explicit File(std::string& _filePath);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~File() = default;

		//-----------------------------------------------------------
		// define
		//----------------------------------------------------------
		File(const File&) = default;
		File(File&&) = default;

		File&operator=(const File&) = default;
		File&operator=(File&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
			/// <summary>
			/// �t�@�C���ǂݍ���.
			/// </summary>
			/// <param name="_path">�t�@�C���p�X</param>
			/// <returns>�ǂݍ��ݐ�������</returns>
		virtual void Read(std::string _path) = 0 {}


		/// <summary>
		/// ��������.
		/// </summary>
		/// <param name="_path">�t�@�C���p�X</param>
		/// <returns>�������ݐ�������</returns>
		virtual void Write(std::string _path = "") = 0 {}

	protected:
		/// <summary>
		/// �t�@�C�����ƃp�X���Z�b�g.
		/// </summary>
		/// <param name="_path">�t�@�C���p�X</param>
		void SetFilePathInfo(std::string _path);

	public:
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_CR_R_ONLY(m_FileName, FileName, std::string);
		PROPERTY_CR_R_ONLY(m_FilePath, FilePath, std::string);
		PROPERTY_CR_R_ONLY(m_FileDirectory, FileDirectory, std::string);

	protected:
		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
		std::string m_FileName;
		std::string m_FilePath;
		std::string m_FileDirectory;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
