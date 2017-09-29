/**
* @file		TypeStringConvertible.h
* @brief	型情報のstring化機能提供
* @author	S.OIKAWA
* @date		2016.09.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>
#include"TypePossession.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Utility
{
	/// <summary>
	/// 型情報のstring化機能提供.
	/// </summary>
	class TypeStringConvertible :
		public virtual TypePossession
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		TypeStringConvertible() = default;
		virtual ~TypeStringConvertible() = default;

		TypeStringConvertible(const TypeStringConvertible&) = default;
		TypeStringConvertible(TypeStringConvertible&&) = default;

		TypeStringConvertible& operator=(const TypeStringConvertible&) = default;
		TypeStringConvertible& operator=(TypeStringConvertible&&) = default;
#pragma endregion

	protected:
#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// 変更時フック. 
		/// </summary>
		void OnApply() override;

#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_REF_R_ONLY(m_TypeName, TypeName, std::string);

#pragma endregion

	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		std::string m_TypeName;

#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------