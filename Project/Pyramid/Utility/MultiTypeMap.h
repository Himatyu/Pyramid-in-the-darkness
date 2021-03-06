/**
* @file		MultiTypeMap.h
* @brief	複数の型を保持するマップ
* @author	S.OIKAWA
* @date		2016.09.07
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include<algorithm>
#include"SingleTypeMap.h"
#include"HavingChildType.h"
#include"TypeList.h"
#include"NullType.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion

namespace Utility
{
	/// <summary>
	/// 複数の型を所持するmap.
	/// 任意型を登録する.
	/// 検索は保持種類*保持個数を錯綜する.
	/// 登録種類は最小限にすること.
	/// </summary>
	class MultiTypeMap
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		MultiTypeMap() = default;
		~MultiTypeMap();

		MultiTypeMap(const MultiTypeMap&) = default;
		MultiTypeMap(MultiTypeMap&&) = default;

		MultiTypeMap& operator=(const MultiTypeMap&) = default;
		MultiTypeMap& operator=(MultiTypeMap&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// 要素追加.
		/// </summary>
		template<class Type>
		void Add(std::string _key, Type _value);

		/// <summary>
		/// 要素削除.
		/// </summary>
		template<class Type>
		void Remove(std::string _key);

		/// <summary>
		/// 検索.
		/// </summary>
		/// <returns>なければヌルポ</returns>
		template<class Type>
		Nullable<Type> Find(std::string _key);

		/// <summary>
		/// 使用する型を登録する.
		/// </summary>
		template <class Type>
		void RegisterUseType();

		/// <summary>
		/// 型情報を抹消する.
		/// </summary>
		template<class Type>
		void UnRegisterUseType();

		/// <summary>
		/// 各型のマップを取得する.
		/// </summary>
		template<class Type>
		SingleTypeMap<Type>& GetSingleTypeMap();

		/// <summary>
		/// 型情報の所持を確認.
		/// </summary>
		template<class Type>
		bool HasType();

#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
#pragma endregion

	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		std::vector<HavingChildType*> m_Maps;
#pragma endregion
	};
#include"MultiTypeMap.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
