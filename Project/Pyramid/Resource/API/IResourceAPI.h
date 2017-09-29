/**
* @file		IResourceAPI.h
* @brief	���ۃ��\�[�XAPI
* @author	S.OIKAWA
* @date		2016.08.11
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<memory>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace API
		{
			/// <summary>
			///	���ۃ��\�[�XAPI
			/// ���\�[�X������
			/// �ǂݍ��݂ƊJ���@�\������
			/// </summary>
			template<class ResourceFileType>
			class IResourceAPI
			{
			public:
				//-----------------------------------------------------------
				//  default
				//-----------------------------------------------------------
				IResourceAPI() = default;
				virtual ~IResourceAPI() = default;

				IResourceAPI(const IResourceAPI&) = default;
				IResourceAPI(IResourceAPI&&) = default;

				IResourceAPI&operator=(const IResourceAPI&) = default;
				IResourceAPI&operator=(IResourceAPI&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ���\�[�X�̓ǂݍ���.
				/// </summary>
				/// <param name="name">�t�@�C���p�X</param>
				void Load(std::string _path);

				/// <summary>
				/// ���\�[�X�J��
				/// </summary>
				void UnLoad();

				//-----------------------------------------------------------
				// operator
				//-----------------------------------------------------------
				void operator=(std::shared_ptr<ResourceFileType> _sp);
				bool operator==(nullptr_t _pNull);
				bool operator!=(nullptr_t _pNull);
				void operator=(nullptr_t _pNull);

				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_spResourceFile, spResourceFile, std::shared_ptr<ResourceFileType>);

			protected:
				std::shared_ptr<ResourceFileType>		m_spResourceFile = nullptr;
			};
#include"IResourceAPI.inl"
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

