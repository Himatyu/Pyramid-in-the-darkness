/**
* @file		IResource.h
* @brief	���ۃ��\�[�X
* @author	S.OIKAWA
* @date		2016.08.14
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "File.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		/// <summary>
		/// ���ۃ��\�[�X
		/// </summary>
		class IResource :
			public Utility::File
		{
		public:

			//-----------------------------------------------------------
			// default
			//-----------------------------------------------------------
			IResource() = default;
			virtual ~IResource() = default;

			IResource(const IResource&) = default;
			IResource(IResource&&) = default;

			IResource&operator=(const IResource&) = default;
			IResource&operator=(IResource&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			/// <summary>
			/// �t�@�C���ǂݍ���.
			/// </summary>
			/// <param name="_path">�t�@�C���p�X</param>
			virtual void Read(std::string _path) override {};

			/// <summary>
			/// ��������.
			/// </summary>
			/// <param name="_path">�t�@�C���p�X</param>
			virtual void Write(std::string _path = "") override {};

			/// <summary>
			/// ����j������.
			/// </summary>
			virtual void Discard() {};
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------