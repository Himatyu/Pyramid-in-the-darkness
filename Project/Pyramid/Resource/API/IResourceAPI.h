/**
* @file		IResourceAPI.h
* @brief	抽象リソースAPI
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
			///	抽象リソースAPI
			/// リソースを持つ
			/// 読み込みと開放機能を持つ
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
				/// リソースの読み込み.
				/// </summary>
				/// <param name="name">ファイルパス</param>
				void Load(std::string _path);

				/// <summary>
				/// リソース開放
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

