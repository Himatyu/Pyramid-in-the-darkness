/**
* @file		ResourceManager.h
* @brief	���\�[�X���Ǘ�����N���X
* @author	S.OIKAWA
* @date		2016.08.13
*/
#pragma once

//-----------------------------------------------------------
//�@include 
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
		/// ���\�[�X�����E�j�����s��.
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
			/// �^�o�^.
			/// </summary>
			template<class ResourceTypeList>
			void RegisterUseResource();

			/// <summary>
			/// �^���̖���.
			/// </summary>
			template<class ResourceTypeList>
			void UnRegisterUseResource();

			/// <summary>
			/// �Ȃ���Γǂݍ���
			/// </summary>
			template<class ResourceType>
			std::shared_ptr<ResourceType>
				OnLoad(std::string _key);

			/// <summary>
			/// �J��.
			/// ���Ɏ��̂��Ȃ���΂����ŊJ�������.
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