/**
* @file		UICursor.h
* @brief	カーソルの状態によるイベントを発行する
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UICursor.h"
#include"../../IUI.h"
#include"Vector3.h"
#include"../Common/InputDevice/Mouse.h"
#include"Mathf.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Common::InputDevice;
namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			namespace Publisher
			{
				//-----------------------------------------------------------
				// dtor
				//-----------------------------------------------------------
				UICursor::~UICursor()
				{
					for (auto& _ : m_Listener.Value)
					{
						SAFE_DELETE(::std::get<2>(*_));
						SAFE_DELETE(_);
					}
				}

				//-----------------------------------------------------------
				// InspectAndPublish
				//-----------------------------------------------------------
				void UICursor::InspectAndPublish()
				{
					if (m_Listener.Value.empty())
					{
						return;
					}
					
					auto& mouse = Mouse::Instantiate();
					auto result = FindHitNearUI(mouse);

					if (!result)
					{
						if (mouse.IsUpButton(Mouse::Id::LButton))
						{
							ResetStateLog();
						}
						return;
					}

					std::function<bool(ElementData*)> pred =
						[&](ElementData* _)
					{
						return ::std::get<0>(*_) == *result;
					};
					auto listenerList = m_Listener.Select(pred);//必ず存在する
					auto pElement = (*listenerList.Value.begin());
					auto pInterface = ::std::get<1>(*pElement);

					if (mouse.IsDownButton(Mouse::Id::LButton))
					{
						::std::get<3>(*pElement) = true;
						pInterface->OnCursorEnter();
						return;
					}

					if (mouse.IsUpButton(Mouse::Id::LButton))
					{
						pInterface->OnCursorExit();
						if (::std::get<3>(*pElement))
						{
							pInterface->OnCursorClick();
						}
						ResetStateLog();
					}
				}

				//-----------------------------------------------------------
				// AddListener
				//-----------------------------------------------------------
				void UICursor::AddListener(IUI * _pUI, ::Utility::IUnknown* _pInterface)
				{
					std::function<bool(ElementData*)> pred =
						[&](ElementData* _)
					{
						return ::std::get<0>(*_) == _pUI;
					};
					auto result = m_Listener.Select(pred);

					if (result)
					{
						return;
					}

					auto pObb = new Common::Diagram::OBB();
					pObb->Center = _pUI->Transform.Position;
					auto halfSize = _pUI->Transform.Size*0.5f;
					pObb->Half = ::Utility::Vector3(halfSize.X, halfSize.Y, 1.0f);

					auto pData = new ElementData(
						_pUI,
						static_cast<Listener::IUICursor*>(_pInterface),
						pObb,
						false);
					
					m_Listener.Add(pData);
				}

				//-----------------------------------------------------------
				// RemoveListener
				//-----------------------------------------------------------
				void UICursor::RemoveListener(IUI * _pUI, ::Utility::IUnknown*)
				{
					std::function<bool(ElementData*)> pred =
						[&](ElementData* _)
					{
						return ::std::get<0>(*_) == _pUI;
					};
					auto result = m_Listener.Select(pred);

					if (!result)
					{
						return;
					}

					for (auto& _ : *result)
					{
						m_Listener.Remove(_);
						SAFE_DELETE(_);
					}
				}

				//-----------------------------------------------------------
				// FindHitNearUI
				//-----------------------------------------------------------
				::Utility::Nullable<IUI*> 
					UICursor::FindHitNearUI(Common::InputDevice::Mouse & mouse)
				{
					auto mousePos = mouse.Position;
					IUI* pNearUI = nullptr;
					for (auto& _ : m_Listener.Value)
					{
						auto pObb = ::std::get<2>(*_);
						UpdataUIObb(_);
						auto result = pObb->IsInside(
							::Utility::Vector3(mousePos.X, mousePos.Y, 0.0f));

						if (result)
						{
							continue;
						}
						auto pUI = ::std::get<0>(*_);

						if (!pNearUI)
						{
							pNearUI = pUI;
							continue;
						}

						if (pNearUI->Transform.Position.Z < pUI->Transform.Position.Z)
						{
							pNearUI = pUI;
						}
					}
					if (!pNearUI)
					{
						return {};
					}

					return { pNearUI };
				}

				//-----------------------------------------------------------
				// UpdataUIObb
				//-----------------------------------------------------------
				void UICursor::UpdataUIObb(ElementData * _pElement)
				{
					auto pUI = ::std::get<0>(*_pElement);
					auto& trans = pUI->Transform;
					auto pObb = ::std::get<2>(*_pElement);
					
					pObb->Initialize();
					pObb->Center = trans.Position + trans.ParentsPosition;
					auto halfSize = (trans.Size * (trans.Scale * trans.ParentsScale)) *0.5f;
					pObb->Half = ::Utility::Vector3(halfSize.X, halfSize.Y, 1.0f);
					pObb->RotateTo(
						::Utility::Vector3(
							0,
							0,
							trans.RotateZ + trans.ParentsRotateZ));
				}

				//-----------------------------------------------------------
				// ResetStateLog
				//-----------------------------------------------------------
				void UICursor::ResetStateLog()
				{
					for (auto& _ : m_Listener.Value)
					{
						::std::get<3>(*_) = false;
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------