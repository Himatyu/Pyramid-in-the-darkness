/**
* @file		Texture.inl
* @brief	ƒCƒ“ƒ‰ƒCƒ“ŽÀ‘•
* @author	S.OIKAWA
* @date		2016.08.21
*/

#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Texture.h"
#include<typeinfo>

//-----------------------------------------------------------
// OnLostRelease
//-----------------------------------------------------------
template<class Type>
void Texture<Type>::OnLost()
{
	if (!m_spResourceFile ||
		!ResourceIsType<Resources::Texture::DirectXTextureFile>()&&
		!ResourceIsType<Resources::Texture::DirectXTextureFileFromInMemory>())
	{
		return;
	}
	m_spResourceFile->Discard();
}

//-----------------------------------------------------------
// Recover
//-----------------------------------------------------------
template<class Type>
void Texture<Type>::Recover()
{
	if (!m_spResourceFile ||
		!ResourceIsType<Resources::Texture::DirectXTextureFile>() &&
		!ResourceIsType<Resources::Texture::DirectXTextureFileFromInMemory>()) 
	{
		return;
	}
	m_spResourceFile->Read(m_spResourceFile->FilePath);
}

//-----------------------------------------------------------
// = shared_ptr<ResourceFileType>
//-----------------------------------------------------------
template<class Type>
inline void Texture<Type>::operator=(std::shared_ptr<Type> _sp)
{
	IResourceAPI<Type>::operator=(_sp);
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

