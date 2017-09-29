/**
* @file		Model.inl
* @brief	モデルAPIのテンプレート実装
* @author	S.OIKAWA
* @date		2016.09.03
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Model.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

//-----------------------------------------------------------
// Init
//-----------------------------------------------------------
template<class Type>
inline void Model<Type>::Init()
{
	m_spResourceFile->InitializeUseDaveice();
	m_Volume = m_spResourceFile->Volume;
}

/// <summary>
/// 行列を設定する
/// </summary>
template<class Type>
inline void Model<Type>::SetMatrix(D3DXMATRIX & _mat)
{
	m_spResourceFile->SetMatrix(_mat);
}

//-----------------------------------------------------------
// OnLost
//-----------------------------------------------------------
template<class Type>
inline void Model<Type>::OnLost()
{
	if (!m_spResourceFile )
	{
		return;
	}
	m_spResourceFile->Discard();
}

//-----------------------------------------------------------
// Recover
//-----------------------------------------------------------
template<class Type>
inline void Model<Type>::Recover()
{
	if (!m_spResourceFile)
	{
		return;
	}
	m_spResourceFile->Read(m_spResourceFile->FilePath);
}

//-----------------------------------------------------------
// = shared_ptr<ResourceFileType>
//-----------------------------------------------------------
template<class Type>
inline void Model<Type>::operator=(std::shared_ptr<Type> _sp)
{
	IResourceAPI<Type>::operator=(_sp);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------