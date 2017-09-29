/**
* @file		UIChangeState.h
* @brief	�L��������؂�ւ����ۂ̃C�x���g�𔭍s����
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
				/// �L��������؂�ւ����ۂ̃C�x���g�𔭍s����
				/// �o�^�E�o�^�폜�̃|���V�[��UIPublishSystem�Ɠ���
				/// </summary>
				class UIChangeState final :
					public Base<Listener::IUIChangeState>
				{
					using ElementData =
						::std::tuple<Pyramid::UI::IUI*,
						Pyramid::UI::Event::Listener::IUIChangeState*,
						bool/*�O�t���[���̃o�b�t�@*/,
						bool/*�e���l�������ŏI�I�ȃX�e�[�g*/>;
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
					/// �O�t���[���Ƃ�Active���r���ăC�x���g���s
					/// </summary>
					void InspectAndPublish() override;

					/// <summary>
					/// ���X�i�[�o�^
					/// </summary>
					void AddListener(IUI*,::Utility::IUnknown*) override;

					/// <summary>
					/// ���X�i�[�o�^�폜
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