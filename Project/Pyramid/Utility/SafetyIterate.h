/**
* @file		SafetyIterate.h
* @brief	ベクターの追加削除を遅延して行う
* @author	S.OIKAWA
* @date		2016.09.25
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include"Estd.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Utility
{
	/// <summary>
	/// ベクターの追加削除を遅延して行う
	/// </summary>
	template<class Type>
	class SafetyIterate
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		SafetyIterate() = default;
		~SafetyIterate() = default;

		SafetyIterate(const SafetyIterate&);
		SafetyIterate(SafetyIterate&&);

		SafetyIterate& operator=(const SafetyIterate&) = default;
		SafetyIterate& operator=(SafetyIterate&&);
#pragma endregion


#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// 追加要求.
		/// </summary>
		void AddRequest(Type _value);

		/// <summary>
		/// 削除要求.
		/// </summary>
		void RemoveRequest(Type _value);

		/// <summary>
		/// 含まれているかを確かめる
		/// </summary>
		bool IsContains(Type _value);

		/// <summary>
		/// リクエストを実行する.
		/// </summary>
		void Apply();

#pragma endregion

#pragma region operaotor

		operator std::vector<Type>&();
#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_REF(m_Vector, Vector, std::vector<Type>);
#pragma endregion
	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		std::vector<Type>		m_Vector;
		std::list<Type>			m_AddRequestList{};
		std::list<Type>			m_RemoveRequestList{};
#pragma endregion
	};
#include"SafetyIterate.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

