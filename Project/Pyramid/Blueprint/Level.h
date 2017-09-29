/**
* @file		Level.h
* @brief	レベルベース
* @author	S.OIKAWA
* @date		2016/07/28
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TimerClient.h"
#include"../GameObject/ObjectManager.h"
#include"../GameObject/Object.h"
#include"../Utility/Factory.h"
#include"../Utility/Nullable.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{

		/// <summary>
		/// レベルブループリントみたいな扱い
		/// </summary>
		class Level
		{
		public:
			//-----------------------------------------------------------
			// defalult
			//-----------------------------------------------------------
			Level();
			virtual ~Level();

			Level(const Level&) = default;
			Level(Level&&) = default;

			Level& operator=(const Level&) = default;
			Level& operator=(Level&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			/// <summary>
			/// 更新.
			/// </summary>
			virtual void Updata();

			/// <summary>
			/// 描画.
			/// </summary>
			virtual void Draw();

			/// <summary>
			/// オブジェクト実体化.
			/// </summary>
			template <class Type, class... Param>
			Type& Instantiate(Param&&... param);

			/// <summary>
			/// オブジェクト破棄.
			/// </summary>
			/// <param name="_pObj">破壊オブジェクト</param>
			void Destory(GameObject::Object* _pObj);

			/// <summary>
			/// タグ検索.
			/// </summary>
			/// <param name="_tag">タグ</param>
			/// <returns>結果ポインタ.なければnullptr.</returns>
			Utility::Nullable<GameObject::Object*> FindWithTag(std::string _tag);

			/// <summary>
			/// タグ検索.複数.
			/// </summary>
			/// <param name="_tag">タグ</param>
			/// <returns>結果ベクトル.</returns>
			Utility::Nullable<std::vector<GameObject::Object*>> FindObjectsWithTag(std::string _tag);

			/// <summary>
			/// 型検索
			/// </summary>
			template<class TY>
			Utility::Nullable<GameObject::Object*> FindWithType();
			
			/// <summary>
			/// 型検索、複数
			/// </summary>
			template<class Ty>
			Utility::Nullable<std::vector<GameObject::Object*>>
				FindObjectsWithType();

			//-----------------------------------------------------------
			// property 
			//-----------------------------------------------------------
			PROPERTY_REF_R_ONLY(m_ObjectManager, ObjectManager, GameObject::ObjectManager);

		protected:
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			GameObject::ObjectManager m_ObjectManager;

		};
#include"Level.inl"
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

