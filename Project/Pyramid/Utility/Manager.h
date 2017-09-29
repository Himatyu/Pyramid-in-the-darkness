/**
* @file		Manager.h
* @brief	コンテナで管理するベース
* @author	S.OIKAWA
* @date		2017.03.07
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include<vector>
#include<deque>
#include<functional>
#include<type_traits>
#include"Estd.h"
#include"NullType.h"
#include"Nullable.h"
#include"IUnknown.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Utility
{
	/// <summary>
	/// コンテナを持ち操作を公開する
	/// 機能制限や拡張を容易にする
	/// Add/Remove操作は全てイテレータを破壊するのでイテレーション中には使えない
	/// vector,list,dequeに限定する(インターフェース統一のため)
	/// </summary>
	template<class Container>
	class Manager : 
		public Unknown
	{
		static_assert(
			std::is_same<Container, std::vector<typename Container::value_type>>::value ||
			std::is_same<Container, std::deque<typename Container::value_type>>::value ||
			std::is_same<Container, std::list<typename Container::value_type>>::value,
			"use container other than vector or list or deque");	//2バイト文字使えないんだがｗ
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		Manager() = default;
		virtual ~Manager() = default;

		Manager(const Manager&) = default;
		Manager(Manager&&) = default;

		Manager& operator=(const Manager&) = default;
		Manager& operator=(Manager&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// 追加
		/// </summary>
		virtual void Add(typename Container::value_type);

		/// <summary>
		/// 削除
		/// 開放は行わない
		/// </summary>
		virtual void Remove(typename Container::value_type);

		/// <summary>
		/// 射影
		/// </summary>
		virtual Nullable<std::list<typename Container::value_type>>
			Select(std::function<bool(typename Container::value_type)>&);
#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_REF(m_Container, Value, Container);

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
	protected:
		Container		m_Container;

#pragma endregion
	};
#include"Manager.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------