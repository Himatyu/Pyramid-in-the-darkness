/**
* @file		UIChangeState.h
* @brief	有効無効を切り替えた際のイベントを発行する
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Manager.h"
#include"Base.h"
#include"../Listener/IUIChangeState.h"
#include<vector>
#include<utility>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace UI
	{
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
			namespace Publisher
			{
				/// <summary>
				/// 有効無効を切り替えた際のイベントを発行する
				/// 登録・登録削除のポリシーはUIPublishSystemと同じ
				/// </summary>
				class UIChangeState final :
					public Base<Listener::IUIChangeState>
				{
					using ElementData =
						::std::tuple<Pyramid::UI::IUI*,
						Pyramid::UI::Event::Listener::IUIChangeState*,
						bool/*前フレームのバッファ*/,
						bool/*親を考慮した最終的なステート*/>;
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					UIChangeState() = default;
					~UIChangeState();

					UIChangeState(const UIChangeState&) = default;
					UIChangeState(UIChangeState&&) = default;

					UIChangeState& operator=(const UIChangeState&) = default;
					UIChangeState& operator=(UIChangeState&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// 前フレームとのActiveを比較してイベント発行
					/// </summary>
					void InspectAndPublish() override;

					/// <summary>
					/// リスナー登録
					/// </summary>
					void AddListener(IUI*,::Utility::IUnknown*) override;

					/// <summary>
					/// リスナー登録削除
					/// </summary>
					void RemoveListener(IUI*,::Utility::IUnknown*) override;

				private:

					void UpdataActiveFlags(ElementData*);
					void EventPublish(ElementData*);
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
					::Utility::Manager<::std::vector<ElementData*>> m_Data;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------