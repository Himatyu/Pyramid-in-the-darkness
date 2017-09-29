/**
* @file		UIChangeState.h
* @brief	有効無効を切り替えた際のイベントを発行する
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UIChangeState.h"
#include"../UI/IUI.h"
#include"../Listener/IUIChangeState.h"
#pragma endregion

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

				//-----------------------------------------------------------
				// dtor
				//-----------------------------------------------------------
				UIChangeState::~UIChangeState()
				{
					for (auto& _ : m_Data.Value)
					{
						SAFE_DELETE(_);
					}
				}

				//-----------------------------------------------------------
				// InspectAndPublish
				//-----------------------------------------------------------
				void UIChangeState::InspectAndPublish()
				{
					for (auto& _ : m_Data.Value)
					{
						UpdataActiveFlags(_);
						EventPublish(_);

						::std::get<2>(*_) = ::std::get<3>(*_);
					}
				}

				//-----------------------------------------------------------
				// AddListener
				//-----------------------------------------------------------
				void UIChangeState::AddListener(IUI * _pUI,::Utility::IUnknown* _pInterface)
				{
					std::function<bool(ElementData*)> pred =
						[&](ElementData* _)
					{
						return ::std::get<0>(*_) == _pUI;
					};
					auto result = m_Data.Select(pred);

					if (result)
					{
						return;
					}

					m_Data.Add(
						new ElementData(
							_pUI,
							static_cast<Listener::IUIChangeState*>(_pInterface),
							_pUI->isActive,
							_pUI->isActive));
				}

				//-----------------------------------------------------------
				// RemoveListener
				//-----------------------------------------------------------
				void UIChangeState::RemoveListener(IUI * _pUI,::Utility::IUnknown* _pInterface)
				{
					std::function<bool(ElementData*)> pred =
						[&](ElementData* _)
					{
						return ::std::get<0>(*_) == _pUI;
					};
					auto result = m_Data.Select(pred);

					if (!result)
					{
						return;
					}

					for (auto& _ : *result)
					{
						m_Data.Remove(_);
						SAFE_DELETE(_);
					}
				}

				//-----------------------------------------------------------
				// UpdataActiveFlags
				//-----------------------------------------------------------
				void UIChangeState::UpdataActiveFlags(ElementData* _pData)
				{
					auto pUI = ::std::get<0>(*_pData);
					auto& trans = pUI->Transform;
					auto pParent = trans.pParent;

					if (!pParent)
					{
						::std::get<3>(*_pData) = pUI->isActive;
						return;
					}
						
					bool pred = true;
					while (pParent)
					{
						pred &= pParent->isActive;
						pParent = pParent->Transform.pParent;
					}

					::std::get<3>(*_pData) = pUI->isActive & pred;
				}

				//-----------------------------------------------------------
				// EventPublish
				//-----------------------------------------------------------
				void UIChangeState::EventPublish(ElementData * _pData)
				{
					auto pUI = ::std::get<0>(*_pData);
					auto finalState = ::std::get<3>(*_pData);

					if (finalState == ::std::get<2>(*_pData))
					{
						return;
					}

					if (finalState)
					{
						::std::get<1>(*_pData)->OnActivate();
						return;
					}
					::std::get<1>(*_pData)->OnDeactivate();


				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
