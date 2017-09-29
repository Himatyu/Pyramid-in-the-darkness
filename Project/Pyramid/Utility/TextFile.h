/**
* @file		TextFile.h
* @brief	�e�L�X�g�t�@�C���N���X
* @author	S.OIKAWA
* @date		2016/4/22
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"File.h"
#include"Macro.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	/// �e�L�X�g�t�@�C�����o�̓N���X
	/// </summary>
	class TextFile :
		public File
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
		TextFile() = default;

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="_Filename">�t�@�C����</param>
		explicit TextFile(std::string _Filename);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~TextFile() = default;

		//-----------------------------------------------------------
		// default
		//-----------------------------------------------------------
		TextFile(const TextFile&) = default;
		TextFile(TextFile&&) = default;

		TextFile& operator=(const TextFile&) = default;
		TextFile& operator=(TextFile&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

			/// <summary>
			/// text�t�@�C���ǂݍ���
			/// </summary>
		void Read(std::string) override;

		/// <summary>
		/// text�t�@�C����������
		/// </summary>
		void Write(std::string) override;

		//-----------------------------------------------------------
		//�@property
		//-----------------------------------------------------------
		PROPERTY_REF(m_Buffer, Buffer, std::string);


		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
			/// <summary>
			/// �o�b�t�@
			/// </summary>
		std::string m_Buffer;
	};
}
//-----------------------------------------------------------
//�@EOF
//-----------------------------------------------------------