/**
* @file		VO.h
* @brief	�o�����[�I�u�W�F�N�g���
* @author	S.OIKAWA
* @date		2016.11.4
*/
#pragma once

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Utility
{
	template<class ValueType, bool isRef>
	class VO;
}

namespace Utility
{
	/// <summary>
	/// �Q�ƕԂ��o�����[�I�u�W�F�N�g
	/// </summary>
	template<class ValueType>
	class VO<ValueType, true>
	{
	public:
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		VO(ValueType _Value);

		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_REF(m_Value, Value, ValueType);
	private:
		ValueType m_Value;
	};

	/// <summary>
	/// �l�Ԃ��o�����[�I�u�W�F�N�g
	/// </summary>
	template<class ValueType>
	class VO<ValueType, false>
	{
	public:
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		VO(ValueType _Value);

		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY(m_Value, Value, ValueType);
	private:
		ValueType m_Value;
	};
#include"VO.inl"
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------