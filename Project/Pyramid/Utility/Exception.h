/**
* @file		Exception.h
* @brief	��O����
* @author�@	S/OIKAWA
* @date		2016/4/22
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<exception>
#include<string>
#include"Macro.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	/// <summary>
	/// �����ӏ����擾����O�𓊂���
	/// </summary>
#define ___THROW_EXCEPTION(EXCEPTION_TYPE, message) \
  throw EXCEPTION_TYPE( __FILE__, __func__, __LINE__,message) 

/// <summary>
/// �����ӏ����擾����O�|�C���^�𓊂���
/// </summary>
#define ___THROW_EXCEPTION_POINT(EXCEPTION_TYPE, message) \
  throw new EXCEPTION_TYPE( __FILE__, __func__, __LINE__,message) 

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

/// <summary>
/// ��O�N���X.
/// ��{�̓}�N�����g��.
/// </summary>
	class Exception :
		public std::exception
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
			/// <summary>
			/// �����ӏ��̓�����s��Ȃ���O
			/// </summary>
			/// <param name="_msg">���b�Z�[�W</param>
		explicit Exception(const std::string& _msg = "Unknown exception");

		/// <summary>
		/// �����ӏ����������O
		/// </summary>
		/// <param name="_file">�����t�@�C��</param>
		/// <param name="_func">�����֐�</param>
		/// <param name="_line">�������C��</param>
		/// <param name="_msg">���b�Z�[�W</param>
		Exception
			(
				const char* _file,
				const char* _func,
				const int _line,
				const std::string& _msg = "Unknown exception"
				);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~Exception() = default;

		//-----------------------------------------------------------
		// default
		//-----------------------------------------------------------

		Exception(const Exception&) = default;
		Exception(Exception&&) = default;

		Exception& operator=(const Exception&) = default;
		Exception& operator=(Exception&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
			/// <summary>
			/// ��O���e�擾
			/// </summary>
			/// <returns>��O���e</returns>
		virtual const char* what() const noexcept override { return m_Msg.c_str(); }

		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_CR_R_ONLY(m_Msg, Msg, std::string);
		PROPERTY_CR_R_ONLY(m_Filename, Filename, std::string);
		PROPERTY_CR_R_ONLY(m_FunctionName, FunctionName, std::string);
		PROPERTY_CR_R_ONLY(m_ExceptionDetailBuffer, Detail, std::string);
		PROPERTY_CR_R_ONLY(m_Line, Line, int);

	private:
		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
			/// <summary>
			/// ��O���e
			/// </summary>
		std::string m_Msg;

		/// <summary>
		/// ���������t�@�C��
		/// </summary>
		std::string m_Filename;

		/// <summary>
		/// ���������֐�
		/// </summary>
		std::string m_FunctionName;

		/// <summary>
		/// ���e�Ɣ����ӏ�
		/// </summary>
		std::string m_ExceptionDetailBuffer;

		/// <summary>
		/// �����s��
		/// </summary>
		int			m_Line;

	};

}
//-----------------------------------------------------------
//�@EOF
//-----------------------------------------------------------




