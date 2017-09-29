/**
* @file		VO.inl
* @brief	�o�����[�I�u�W�F�N�g���
* @author	S.OIKAWA
* @date		2016.11.4
*/
#pragma once

//-----------------------------------------------------------
// ctor 
//-----------------------------------------------------------
template<class ValueType>
inline VO<ValueType, true>::VO(ValueType _value)
	:m_Value(_value)
{
}

//-----------------------------------------------------------
// ctor 
//-----------------------------------------------------------
template<class ValueType>
inline VO<ValueType, false>::VO(ValueType _value)
	: m_Value(_value)
{
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------