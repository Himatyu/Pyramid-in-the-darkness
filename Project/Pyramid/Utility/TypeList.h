/**
* @file		TypeList.h
* @brief	タイプリストを提供
* @author	S.OIKAWA
* @date		2016.09.07
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"NullType.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	//-----------------------------------------------------------
	// TypeList
	//-----------------------------------------------------------
	template <class T, class U>
	struct TypeList
	{
		using Head = T;
		using Tail = U;
	};

#pragma region define

	template<typename T1>
	using TypeList1 =
		Utility::TypeList<T1, NullType>;

	template<
		typename T1,
		typename T2>
		using TypeList2 =
		Utility::TypeList<T1, TypeList1<T2>>;

	template<
		typename T1,
		typename T2,
		typename T3>
		using TypeList3 =
		Utility::TypeList<T1, TypeList2<T2, T3>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4>
		using TypeList4 =
		Utility::TypeList<T1, TypeList3<T2, T3, T4>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5>
		using TypeList5 =
		Utility::TypeList<T1, TypeList4<T2, T3, T4, T5>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6>
		using TypeList6 =
		Utility::TypeList<T1, TypeList5<T2, T3, T4, T5, T6>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7>
		using TypeList7 =
		Utility::TypeList<T1, TypeList6<T2, T3, T4, T5, T6 ,T7>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8>
		using TypeList8 =
		Utility::TypeList<T1, TypeList7<T2, T3, T4, T5, T6, T7, T8>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9>
		using TypeList9 =
		Utility::TypeList<T1, TypeList8<T2, T3, T4, T5, T6, T7, T8, T9>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10>
		using TypeList10 =
		Utility::TypeList<T1, TypeList9<T2, T3, T4, T5, T6, T7, T8, T9 ,T10>>;



	template<typename T1>
	using SpTypeList1 =
		Utility::TypeList<std::shared_ptr<T1>, Utility::NullType>;

	template<
		typename T1,
		typename T2>
		using SpTypeList2 =
		Utility::TypeList<std::shared_ptr<T1>, SpTypeList1<T2>>;

	template<
		typename T1,
		typename T2,
		typename T3>
		using SpTypeList3 =
		Utility::TypeList<std::shared_ptr<T1>, SpTypeList2<T2, T3>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4>
		using SpTypeList4 =
		Utility::TypeList<std::shared_ptr<T1>, SpTypeList3<T2, T3, T4>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5>
		using SpTypeList5 =
		Utility::TypeList<std::shared_ptr<T1>, SpTypeList4<T2, T3, T4, T5>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6>
		using SpTypeList6 =
		Utility::TypeList<std::shared_ptr<T1>, SpTypeList5<T2, T3, T4, T5, T6>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7>
		using SpTypeList7 =
		Utility::TypeList<std::shared_ptr<T1>, SpTypeList6<T2, T3, T4, T5, T6, T7>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8>
		using SpTypeList8 =
		Utility::TypeList<std::shared_ptr<T1>, SpTypeList7<T2, T3, T4, T5, T6, T7, T8>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9>
		using SpTypeList9 =
		Utility::TypeList<std::shared_ptr<T1>, SpTypeList8<T2, T3, T4, T5, T6, T7, T8, T9>>;

	template<
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10>
		using SpTypeList10 =
		Utility::TypeList<std::shared_ptr<T1>, SpTypeList9<T2, T3, T4, T5, T6, T7, T8, T9, T10>>;

#pragma endregion

	//-----------------------------------------------------------
	// Length
	//-----------------------------------------------------------

	/// <summary>
	/// タイプリストの長さを得る
		///<example>
		/// using Size = 
		///		Length<TypeList3<int,int,int>>::Result; // 3
		///</example>
	/// </summary>

	template <class TList> struct Length;

	template<>
	struct Length<NullType>
	{
		enum : int { Result = 0 };
	};

	template<class T, class U>
	struct Length<TypeList<T, U>>
	{
		enum : int
		{
			Result = 1 + Length<U>::Result
		};
	};

	//-----------------------------------------------------------
	// TypeAt
	//-----------------------------------------------------------

	/// <summary>
	/// タイプリストから射影する
		///<example>
		/// using Type = TypeAt<0, TypeList3<int,int,int>>::Result;
		/// decltype(Type); //int
		///</example>
	/// </summary>
	template< unsigned, class TList> struct TypeAt;

	template<class Head,class Tail>
	struct TypeAt<0,TypeList<Head, Tail>>
	{
		using Result = Head;
	};

	template<unsigned Index,class Head, class Tail>
	struct TypeAt< Index,TypeList<Head, Tail>>
	{
		using Result =
			typename TypeAt< Index - 1,Tail>::Result;
	};
	
	//-----------------------------------------------------------
	// Args
	//-----------------------------------------------------------

	/// <summary>
	/// 可変長パラメータを定義
	/// </summary>
	template<class ...ArgsType>
	struct Args
	{
		enum { value = sizeof...(ArgsType) };
	};

	//-----------------------------------------------------------
	// ArgsAt
	//-----------------------------------------------------------

	/// <summary>
	/// 可変長パラメータから射影する
		///<example>
		/// using Type = ArgsAt<0, int,int,int>::Result;
		/// decltype(Type); //int
		///</example>
	/// </summary>
	template<unsigned, class>
	struct ArgsAt
	{
	};

	template<
		template<class...> class Args,
		class Head, class ...Body
	>
		struct ArgsAt<0, Args<Head, Body...>>
	{
		using Result = Head;
	};

	template<
		unsigned Index,
		template<class...> class Args,
		class Head, class ...Body
	>
		struct ArgsAt<Index, Args<Head, Body...>>
	{
		using Result = 
			typename ArgsAt<Index - 1, Args<Body...>>::Result;
	};

	//-----------------------------------------------------------
	// ConvertToTypeList
	//-----------------------------------------------------------

	namespace
	{
		template<unsigned, class>
		struct SelecterOfTypeListByLenght
		{
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<0, Args>
		{
			using Result = NullType;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<1, Args>
		{
			using Result = TypeList1<
				typename ArgsAt<0, Args>::Result>;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<2, Args>
		{
			using Result = TypeList2<
				typename ArgsAt<0, Args>::Result,
				typename ArgsAt<1, Args>::Result>;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<3, Args>
		{
			using Result = TypeList3<
				typename ArgsAt<0, Args>::Result,
				typename ArgsAt<1, Args>::Result,
				typename ArgsAt<2, Args>::Result>;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<4, Args>
		{
			using Result = TypeList4<
				typename ArgsAt<0, Args>::Result,
				typename ArgsAt<1, Args>::Result,
				typename ArgsAt<2, Args>::Result, 
				typename ArgsAt<3, Args>::Result>;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<5, Args>
		{
			using Result = TypeList5<
				typename ArgsAt<0, Args>::Result,
				typename ArgsAt<1, Args>::Result,
				typename ArgsAt<2, Args>::Result,
				typename ArgsAt<3, Args>::Result,
				typename ArgsAt<4, Args>::Result>;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<6, Args>
		{
			using Result = TypeList6<
				typename ArgsAt<0, Args>::Result,
				typename ArgsAt<1, Args>::Result,
				typename ArgsAt<2, Args>::Result,
				typename ArgsAt<3, Args>::Result,
				typename ArgsAt<4, Args>::Result,
				typename ArgsAt<5, Args>::Result>;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<7, Args>
		{
			using Result = TypeList7<
				typename ArgsAt<0, Args>::Result,
				typename ArgsAt<1, Args>::Result,
				typename ArgsAt<2, Args>::Result,
				typename ArgsAt<3, Args>::Result,
				typename ArgsAt<4, Args>::Result,
				typename ArgsAt<5, Args>::Result,
				typename ArgsAt<6, Args>::Result>;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<8, Args>
		{
			using Result = TypeList8<
				typename ArgsAt<0, Args>::Result,
				typename ArgsAt<1, Args>::Result,
				typename ArgsAt<2, Args>::Result,
				typename ArgsAt<3, Args>::Result,
				typename ArgsAt<4, Args>::Result,
				typename ArgsAt<5, Args>::Result,
				typename ArgsAt<6, Args>::Result,
				typename ArgsAt<7, Args>::Result>;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<9, Args>
		{
			using Result = TypeList9<
				typename ArgsAt<0, Args>::Result,
				typename ArgsAt<1, Args>::Result,
				typename ArgsAt<2, Args>::Result,
				typename ArgsAt<3, Args>::Result,
				typename ArgsAt<4, Args>::Result,
				typename ArgsAt<5, Args>::Result,
				typename ArgsAt<6, Args>::Result,
				typename ArgsAt<7, Args>::Result,
				typename ArgsAt<8, Args>::Result>;
		};

		template<class Args>
		struct SelecterOfTypeListByLenght<10, Args>
		{
			using Result = TypeList10<
				typename ArgsAt<0, Args>::Result,
				typename ArgsAt<1, Args>::Result,
				typename ArgsAt<2, Args>::Result,
				typename ArgsAt<3, Args>::Result,
				typename ArgsAt<4, Args>::Result,
				typename ArgsAt<5, Args>::Result,
				typename ArgsAt<6, Args>::Result,
				typename ArgsAt<7, Args>::Result,
				typename ArgsAt<8, Args>::Result,
				typename ArgsAt<9, Args>::Result>;
		};
	}

	/// <summary>
	/// 可変長パラメータをタイプリストに変換する
	/// パラメータの数は10まで必要なら追加定義して
		///<example>
		/// 
		/// using TypeList = 
		///		typename Utility::ConvertToTypeList<int,int,int>::Result;
		/// 
		/// decltype(TypeList);//TypeList3<int,int,int>
		///</example>
	/// </summary>
	template<class ...ArgsParam>
	struct ConvertToTypeList
	{
		using Result =
			typename SelecterOfTypeListByLenght
			<
				sizeof...(ArgsParam), Args<ArgsParam...>
			>::Result;
	};
	
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------