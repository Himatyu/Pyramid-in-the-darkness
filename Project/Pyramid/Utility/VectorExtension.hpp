/**
* @file		VectorExtension.hpp
* @brief	ベクターの拡張機能を提供
* @author	Oikawa
* @date		2016.02.19
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include <vector>
#include<functional>

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>ベクタの安全削除</summary>
	///<typeparam name="Type">ベクタ要素型</typeparam>
	///<typeparam name="Pred">削除条件</typeparam>
	///<param name="_vec">対象ベクタ</param>
	///<param name="_pred">判定ラムダ式</param>
	///<param name="_isDestroy">メモリを解放するか</param>
	template <class Type,class Pred>
	void VectorClean
		(
		std::vector<Type>& _vec,
		Pred _pred,
		bool _isDestroy
		)
	{
		if (0 == _vec.size()) return;
		auto  it = std::begin(_vec);

		for (; it != std::end(_vec);)
		{
			if (_pred((*it)))
			{
				if (_isDestroy)
					delete *it;

				it = _vec.erase(it);
				continue; 
			}
			it++;
		}
	} 

	/// <summary>ベクタ</summary>
	///<typeparam name="Type">ベクタ要素型</typeparam>
	///<param name="_vec">対象ベクタ</param>
	///<param name="_action">実行ラムダ式</param>
	template <class Type>
	void VectorForEach
		(
		std::vector<Type>& _vec,
		std::function<void(Type _element)> _action
		)
	{
		if (0 == _vec.size())
		{
			return;
		}

		for (auto it : _vec)
		{
			_action(it);
		}
	}

	/// <summary>条件カウント</summary>
	///<typeparam name="Type">ベクタ要素型</typeparam>
	///<typeparam name="Pred">条件</typeparam>
	///<param name="_vec">対象ベクタ</param>
	///<param name="_pred">判定ラムダ式</param>
	///<returns>カウント</returns>
	template <class Type,class Pred>
	size_t VectorCount_if
		(
			std::vector<Type>& _vec,
			Pred _pred
		)
	{
		return std::count_if(
							std::begin(_vec), 
							std::end(_vec),
							_pred
							);
	}

	/// <summary>重複破棄</summary>
	///<typeparam ="Type">ベクタ要素型</typeparam>
	///<param ="_vec">対象ベクタ<param>
	template <class Type>
	void VectorUnique(std::vector<Type>& _vec)
	{
		std::sort(_vec.begin(), _vec.end());
		_vec.erase(std::unique(_vec.begin(), _vec.end()), _vec.end());
	}

	/// <summary>条件ソート</summary>
	///<typeparam ="Type">ベクタ要素型</typeparam>
	///<typeparam ="Pred">条件ラムダ</typeparam>
	///<param ="_vec">対象ベクタ</param>
	///<param ="_pred">条件式</param>
	template<class Type,class Pred>
	void VectorSort(
		std::vector<Type>& _vec,
		Pred _pred
		)
	{
		std::sort(_vec.begin(), _vec.end(), _pred);
	}
};

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------