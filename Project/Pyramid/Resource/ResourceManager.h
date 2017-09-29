/**
* @file		ResourceManager.h
* @brief	リソースを管理するクラス
* @author	S.OIKAWA
* @date		2016.08.13
*/
#pragma once

//-----------------------------------------------------------
//　include 
//-----------------------------------------------------------
#include<string>
#include<memory>
#include"MultiTypeMap.h"
#include"singleton.h"
#include"Nullable.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		/// <summary>
		/// リソース生成・破棄を行う.
		/// </summary>
		class ResourceManager final :
			public Utility::Singleton<ResourceManager>
		{
		public:
			//-----------------------------------------------------------
			// defaults 
			//-----------------------------------------------------------
			ResourceManager() = default;
			~ResourceManager() = default;

			ResourceManager(const ResourceManager&) = default;
			ResourceManager(ResourceManager&&) = default;

			ResourceManager&operator=(const ResourceManager&) = default;
			ResourceManager&operator=(ResourceManager&&) = default;

			//-----------------------------------------------------------
			// function 
			//-----------------------------------------------------------

			/// <summary>
			/// 型登録.
			/// </summary>
			template<class ResourceTypeList>
			void RegisterUseResource();

			/// <summary>
			/// 型情報の抹消.
			/// </summary>
			template<class ResourceTypeList>
			void UnRegisterUseResource();

			/// <summary>
			/// なければ読み込む
			/// </summary>
			template<class ResourceType>
			std::shared_ptr<ResourceType>
				OnLoad(std::string _key);

			/// <summary>
			/// 開放.
			/// 他に実体がなければここで開放される.
			/// </summary>
			template<class ResourceType>
			void UnLoad(std::string _key);

			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
		private:
			Utility::MultiTypeMap m_ResourceMap;
		};
#include"ResourceManager.inl"

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------