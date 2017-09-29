/**
* @file		ResourceManager.inl
* @brief	���\�[�X���ꌳ�Ǘ�����N���X
* @author	S.OIKAWA
* @date		2016.09.10
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ResourceManager.h"

//-----------------------------------------------------------
// RegisterUseResource
//-----------------------------------------------------------
template<class ResourceTypeList>
inline void ResourceManager::RegisterUseResource()
{
	m_ResourceMap.RegisterUseType<ResourceTypeList>();
}

//-----------------------------------------------------------
// UnRegisterUseResource
//-----------------------------------------------------------
template<class ResourceTypeList>
inline void ResourceManager::UnRegisterUseResource()
{
	m_ResourceMap.UnRegisterUseType<ResourceTypeList>();
}

//-----------------------------------------------------------
// OnLoad
//-----------------------------------------------------------
template<class ResourceType>
inline
std::shared_ptr<ResourceType>
ResourceManager::OnLoad(std::string _key)
{
	auto res = m_ResourceMap.Find<std::shared_ptr<ResourceType>>(_key);
	if (!res)
	{
		auto spRes = std::make_shared<ResourceType>();
		spRes->Read(_key);
		m_ResourceMap.Add(_key, spRes);
		return spRes;
	}
	//���\�[�X�����[�h�ł��Ȃ���Η�O������̂ł����ł͊m����API��Ԃ�
	return res.Value;
}

//-----------------------------------------------------------
// UnLoad
//-----------------------------------------------------------
template<class ResourceType>
inline void ResourceManager::UnLoad(std::string _key)
{
	m_ResourceMap.Remove<std::shared_ptr<ResourceType>>(_key);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------