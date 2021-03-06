/**
* @file		HavingChildType.h
* @brief	派生先の型情報を保持する
* @author	S.OIKAWA
* @date		2016.09.07
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<typeinfo>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Utility
{
	/// <summary>
	/// 型情報を保持する、
	/// 継承して使用することが前提
	/// </summary>
	class HavingChildType
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		HavingChildType(std::type_index);
		virtual ~HavingChildType() = default;

		HavingChildType(const HavingChildType&) = default;
		HavingChildType(HavingChildType&&) = default;

		HavingChildType& operator=(const HavingChildType&) = default;
		HavingChildType& operator=(HavingChildType&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		template<class Type>
		bool HasType();
#pragma endregion

	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		std::type_index m_ChildType = typeid(HavingChildType);
#pragma endregion
	};
#include"HavingChildType.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


