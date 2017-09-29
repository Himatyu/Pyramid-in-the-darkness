/**
* @file		IDataObjectFile.h
* @brief	�Œ�l�f�[�^�����\�[�X�Ƃ��Ĉ���
* @author	S.OIKAWA
* @date		2017.05.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Resource/IResource.h"
#include<typeindex>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Resources
	{
		namespace DataObject
		{
			/// <summary>
			/// �Œ�l�f�[�^�����\�[�X�Ƃ��Ĉ���
			/// </summary>
			class IDataObjectFile : 
				public IResource
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				IDataObjectFile(size_t, void*);
				virtual ~IDataObjectFile() = default;

				IDataObjectFile(const IDataObjectFile&) = default;
				IDataObjectFile(IDataObjectFile&&) = default;

				IDataObjectFile& operator=(const IDataObjectFile&) = default;
				IDataObjectFile& operator=(IDataObjectFile&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �ǂݍ��݂��s��
				/// </summary>
				void Read(std::string _path) override ;

			private:
				bool IsMatchOfFileSizeAndTheTypeFile(std::fstream&);
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			private:
				size_t				m_Size;
				void*				m_pDataHead;
#pragma endregion
			};
		}

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------