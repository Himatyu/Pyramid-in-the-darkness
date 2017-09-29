/**
* @file		TypePossession.h
* @brief	型情報を所持する
* @author	S.OIKAWA
* @date		2016.09.28
*/
#pragma once

#pragma region include
	//-----------------------------------------------------------
	// include
	//-----------------------------------------------------------
#include<typeindex>
#include<vector>
#include"NullType.h"
#include"Nullable.h"
#include"TypeList.h"
#pragma endregion

#pragma region define
	//-----------------------------------------------------------
	// define
	//-----------------------------------------------------------

#pragma endregion

namespace Utility
{
	/// <summary>
	/// 型情報を所持する .
	/// Applyしていない場合TypePossession型を持つ.
	/// </summary>
	class TypePossession
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		TypePossession();
		virtual ~TypePossession() = default;

		TypePossession(const TypePossession&) = default;
		TypePossession(TypePossession&&) = default;

		TypePossession& operator=(const TypePossession&) = default;
		TypePossession& operator=(TypePossession&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// 型情報を変更する.
		/// 内部で仮想関数をコールしてるので
		/// フックオーバーライドしたらコンストラクタで呼ばないように.
		/// </summary>
		template<class ...Type>
		void TypeApply();

		/// <summary>
		/// 型確定用のイベントフック.
		/// </summary>
		virtual void OnApply();
		
		/// <summary>
		/// インデックス射影.
		/// </summary>
		Nullable<std::type_index*> AccessOfIndex(unsigned);
	
#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------


#pragma endregion

	protected:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		std::vector<std::type_index> m_Types;
#pragma endregion
	};
#include"TypePossession.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

