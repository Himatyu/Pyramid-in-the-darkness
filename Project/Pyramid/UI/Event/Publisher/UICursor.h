/**
* @file		UICursor.h
* @brief	カーソルの状態によるイベントを発行する
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Manager.h"
#include"IUnknown.h"
#include"../Listener/IUICursor.h"
#include"../Common/Diagram/OBB.h"
#include"Nullable.h"
#include"Base.h"
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
				/// カーソルの状態によるイベントを発行する
				/// </summary>
				class UICursor final:
					public Base<Listener::IUICursor>
				{
					using ElementData =
						::std::tuple<
						Pyramid::UI::IUI*,
						Pyramid::UI::Event::Listener::IUICursor*,
						Pyramid::Common::Diagram::OBB*,
						bool/*自身の領域上で押し込まれたかどうか*/>;
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					UICursor() = default;
					~UICursor();

					UICursor(const UICursor&) = default;
					UICursor(UICursor&&) = default;

					UICursor& operator=(const UICursor&) = default;
					UICursor& operator=(UICursor&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// マウスの状態と比較してイベントの発行
					/// </summary>
					void InspectAndPublish() override;

					/// <summary>
					/// リスナー登録
					/// </summary>
					void AddListener(IUI*,::Utility::IUnknown*) override;

					/// <summary>
					/// リスナー登録削除
					/// </summary>
					void RemoveListener(IUI*, ::Utility::IUnknown*) override;

				private:
					::Utility::Nullable<IUI*> FindHitNearUI(Common::InputDevice::Mouse&);
					void UpdataUIObb(ElementData*);
					void ResetStateLog();
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
					::Utility::Manager<::std::vector<ElementData*>> m_Listener;

#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------