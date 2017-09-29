/**
* @file		IResourceAPI.inl
* @brief	リソースAPIベースのテンプレート実装
* @author	S.OIKAWA
* @date		2016.09.03
*/
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "IResourceAPI.h"

//-----------------------------------------------------------
// Load
//-----------------------------------------------------------
template<class ResourceFileType>
inline void IResourceAPI<ResourceFileType>::Load(std::string _path)
{
	if (nullptr != m_spResourceFile)
	{
		___D_LOG("リソースの上書きを行っています");
		UnLoad();
	}
	m_spResourceFile = std::make_shared<ResourceFileType>();
	m_spResourceFile->Read(_path);
}

//-----------------------------------------------------------
// UnLoad
//-----------------------------------------------------------
template<class ResourceFileType>
inline void IResourceAPI<ResourceFileType>::UnLoad()
{
	m_spResourceFile.reset();
}

//-----------------------------------------------------------
// = shared_ptr<ResourceFileType>
//-----------------------------------------------------------
template<class ResourceFileType>
inline 
void IResourceAPI<ResourceFileType>::
operator=(std::shared_ptr<ResourceFileType> _sp)
{
	m_spResourceFile = _sp;
}

//-----------------------------------------------------------
// == nullptr_t
//-----------------------------------------------------------
template<class ResourceFileType>
inline
bool 
IResourceAPI<ResourceFileType>::operator==(nullptr_t _pNull)
{
	return (nullptr == m_spResourceFile);
}

//-----------------------------------------------------------
// == nullptr_t
//-----------------------------------------------------------
template<class ResourceFileType>
inline 
bool 
IResourceAPI<ResourceFileType>::operator!=(nullptr_t _pNull)
{
	return (nullptr != m_spResourceFile);
}

//-----------------------------------------------------------
// = nullptr_t
//-----------------------------------------------------------
template<class ResourceFileType>
inline 
void IResourceAPI<ResourceFileType>::operator=(nullptr_t _pNull)
{
	m_spResourceFile.reset();
	m_spResourceFile = nullptr;
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


