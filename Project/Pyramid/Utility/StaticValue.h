/**
* @file		StaticValue.h
* @brief	静的変数で開放順序を指定したいオブジェクに使用する
* @author	S.OIKAWA
* @date		2016.11.14
*/

#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	/// 静的変数の開放
	/// </summary>
	class StaticValueFinalizer
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor 
		//-----------------------------------------------------------
		StaticValueFinalizer() = default;
		~StaticValueFinalizer() = default;

		StaticValueFinalizer(const StaticValueFinalizer&) = default;
		StaticValueFinalizer(StaticValueFinalizer&&) = default;

		StaticValueFinalizer& operator=(const StaticValueFinalizer&) = default;
		StaticValueFinalizer& operator=(StaticValueFinalizer&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		using FinalizerFunc = void(*)();

		/// <summary>
		/// 開放関数を登録
		/// </summary>
		static void AddFinalizer(FinalizerFunc _func);

		/// <summary>
		/// 開放を実行
		/// </summary>
		static void Finalize();

	private:
		//-----------------------------------------------------------
		// Val 
		//-----------------------------------------------------------
		static std::vector<FinalizerFunc> m_Finalizers;

	};

	/// <summary>
	/// 静的変数で開放順序を指定したいオブジェクに使用する
	/// </summary>
	template<class Ty>
	class StaticValue
	{
	public:
		//-----------------------------------------------------------
		// defaullts 
		//-----------------------------------------------------------
		StaticValue();
		~StaticValue() = default;

		StaticValue(const StaticValue&) = default;
		StaticValue(StaticValue&&) = default;

		StaticValue&operator=(const StaticValue&) = default;
		StaticValue&operator=(StaticValue&&) = default;

		//-----------------------------------------------------------
		// operator
		//-----------------------------------------------------------
		operator Ty();
		Ty& operator = (Ty);
		Ty& operator->();
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
	private:
		static void Destroy();

		//-----------------------------------------------------------
		// var
		//-----------------------------------------------------------
		static Ty*	m_pInstance;
	};
#include"StaticValue.inl"
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

