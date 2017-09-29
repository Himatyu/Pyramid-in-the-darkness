/**
* @file		SingleTypeMap.h
* @brief	マルチタイプMap内部のマップ
* @author	S.OIKAWA
* @date		2016.09.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<unordered_map>
#include<string>
#include"HavingChildType.h"
#include"Nullable.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Utility
{
	template<class Type>
	class SingleTypeMap final
		:public HavingChildType
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		SingleTypeMap();
		~SingleTypeMap();

		SingleTypeMap(const SingleTypeMap&) = default;
		SingleTypeMap(SingleTypeMap&&) = default;

		SingleTypeMap& operator=(const SingleTypeMap&) = default;
		SingleTypeMap& operator=(SingleTypeMap&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// 要素追加.
		/// </summary>
		void Add(std::string _key, Type _value);

		/// <summary>
		/// 要素削除.
		/// </summary>
		void Remove(std::string _key);

		/// <summary>
		/// 検索.
		/// </summary>
		Nullable<Type> Find(std::string _key);
#pragma endregion

	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		std::unordered_map<std::string, Type> m_Map;

#pragma endregion
	};
#include"SingleTypeMap.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
