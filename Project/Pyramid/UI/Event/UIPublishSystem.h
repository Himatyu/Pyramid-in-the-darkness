/**
* @file		UIPublishSystem.h
* @brief	UIのイベントリスナー/パブリッシャーを登録し、イベントの発行を行う
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"
#include"Estd.h"
#include"Nullable.h"
#include"Publisher\Abstract.h"
#include<unordered_map>
#include<typeindex>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			namespace Publisher
			{
				class Abstract;
			}
		}
		class IUI;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			/// <summary>
			/// UIのイベントリスナーを登録し、イベントの発行を行う
			/// 登録ポリシー	:重複無し
			/// 登録解除ポリシー:対象がない時は何もしない
			/// </summary>
			class UIPublishSystem final:
				public ::Utility::Singleton<UIPublishSystem>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				UIPublishSystem() = default;
				~UIPublishSystem();

				UIPublishSystem(const UIPublishSystem&) = default;
				UIPublishSystem(UIPublishSystem&&) = default;

				UIPublishSystem& operator=(const UIPublishSystem&) = default;
				UIPublishSystem& operator=(UIPublishSystem&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// パブリッシャー更新
				/// </summary>
				void Updata();

				/// <summary>
				/// パブリッシャーへの登録
				/// </summary>
				template<class Publisher,class Ty>
				void AddListener(Ty*);

				/// <summary>
				/// パブリッシャーへの登録解除
				/// </summary>
				template<class Publisher, class Ty>
				void RemoveListener(Ty*);

				/// <summary>
				/// パブリッシャーの登録
				/// </summary>
				template<class Publisher>
				void RegisterOfPublisher();

				/// <summary>
				/// パブリッシャーの登録解除
				/// </summary>
				template<class Publisher>
				void UnRegisterOfPublisher();

			private:
				template<class Ty>
				::Utility::Nullable<Publisher::Abstract*> FindPublisher();

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			private:
				::std::unordered_map<
					::std::type_index, 
					Publisher::Abstract*>	m_Publishrs;
#pragma endregion
			};
#include"UIPublishSystem.inl"
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------