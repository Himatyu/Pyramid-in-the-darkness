/**
* @file		UICursor.h
* @brief	�J�[�\���̏�Ԃɂ��C�x���g�𔭍s����
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
				/// �J�[�\���̏�Ԃɂ��C�x���g�𔭍s����
				/// </summary>
				class UICursor final:
					public Base<Listener::IUICursor>
				{
					using ElementData =
						::std::tuple<
						Pyramid::UI::IUI*,
						Pyramid::UI::Event::Listener::IUICursor*,
						Pyramid::Common::Diagram::OBB*,
						bool/*���g�̗̈��ŉ������܂ꂽ���ǂ���*/>;
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
					/// �}�E�X�̏�ԂƔ�r���ăC�x���g�̔��s
					/// </summary>
					void InspectAndPublish() override;

					/// <summary>
					/// ���X�i�[�o�^
					/// </summary>
					void AddListener(IUI*,::Utility::IUnknown*) override;

					/// <summary>
					/// ���X�i�[�o�^�폜
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