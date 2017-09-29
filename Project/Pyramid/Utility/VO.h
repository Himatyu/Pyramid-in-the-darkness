/**
* @file		VO.h
* @brief	バリューオブジェクトを提供
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
	/// 参照返しバリューオブジェクト
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
	/// 値返しバリューオブジェクト
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