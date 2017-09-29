/**
* @file		Factory.h
* @brief	オブジェクト、コンポーネントベース
* @author	S.OIKAWA
* @date		2016/2/19
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<map>
#include<string>
#include<typeindex>
#include"singleton.h"
#include"Creator.h"
#include"Exception.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	/// <summary>
	/// オブジェクト・コンポーネントのファクトリ
	/// オブジェクト・コンポーネントの子も生成可
	/// </summary>
	/// <typeparam name="Base">生成型</typeparam>
	template<class Base>
	class Factory :
		public Singleton<Factory<Base>>
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------

		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		Factory() = default;

		/// <summary>
		/// コピーコンストラクタ:削除
		/// </summary>
		Factory(const Factory&) = delete;

		/// <summary>
		/// ムーブコンストラクタ：削除
		/// </summary>
		Factory(Factory&&) = delete;

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~Factory();

		//-----------------------------------------------------------
		// operators
		//-----------------------------------------------------------

		/// <summary>
		/// コピー禁止
		/// </summary>
		Factory& operator = (const Factory&) = delete;

		/// <summary>
		/// ムーブ禁止
		/// </summary>
		Factory& operator = (Factory&&) = delete;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>生成</summary>
		///<returns>成功すればChildポインタ.失敗はnullptr</returns>
		///<typeparam name="Child">生成型</typeparam>
		/// <remarks>
		/// Child型を生成するクリエイターを登録していること。
		/// ChildはBaseの継承先でも可
		/// </remarks>
		template <class Child>
		Child Create();

		/// <summary>生成</summary>
		///<param name = "_type">生成型</param>
		///<remarks>
		/// ほぼコピー用。
		/// 形名を渡せば登録しているクリエイターで生成
		/// </remarks>
		Base Create(std::type_index _type);

		/// <summary>クリエイター登録</summary>
		///<param name="_pCreator">クリエイターポインタ</param>
		///<typeparam name="Type">生成型</typeparam>
		///<returns>登録成功でtrue 失敗でfalse</returns>
		template <class CreaterType>
		bool Register();

		/// <summary>クリエイターを所持してるか</summary>
		///<param name = "_type">生成型</param>
		///<returns>登録済み:true 未登録:false</returns>
		bool HasType(std::type_index _type);

		/// <summary>
		/// クリエイターを所持してるか
		/// </summary>
		/// <typeparam name="Type">生成型</typeparam>
		template <class Type>
		bool HasType();

		/// <summary>Mapが空か確認</summary>
		///<returns>空:true 要素あり:false</returns>
		bool IsEmpty();

		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
	private:
		/// <summary>
		/// 生成関数マップ
		/// </summary>
		using CreatorMap = std::map<std::type_index, Creator<Base>*>;
		CreatorMap m_CreatorMap;

	};

#include"Factory.inl"
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------