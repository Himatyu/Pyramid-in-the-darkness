/**
* @file		Buffer.inl
* @brief	DirectX�̃����_�����O�Ɏg�p����o�b�t�@�iVertex,Index�j
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"Buffer.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

/// <summary>
/// ctor
/// </summary>
template<class Ty,
template<class> class Create ,
template<class> class Delete >
Buffer<Ty, Create, Delete>::operator Ty() const
{
	return m_Buffer;
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------