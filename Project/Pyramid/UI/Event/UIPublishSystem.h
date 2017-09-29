/**
* @file		UIPublishSystem.h
* @brief	UI�̃C�x���g���X�i�[/�p�u���b�V���[��o�^���A�C�x���g�̔��s���s��
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
			/// UI�̃C�x���g���X�i�[��o�^���A�C�x���g�̔��s���s��
			/// �o�^�|���V�[	:�d������
			/// �o�^�����|���V�[:�Ώۂ��Ȃ����͉������Ȃ�
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
				/// �p�u���b�V���[�X�V
				/// </summary>
				void Updata();

				/// <summary>
				/// �p�u���b�V���[�ւ̓o�^
				/// </summary>
				template<class Publisher,class Ty>
				void AddListener(Ty*);

				/// <summary>
				/// �p�u���b�V���[�ւ̓o�^����
				/// </summary>
				template<class Publisher, class Ty>
				void RemoveListener(Ty*);

				/// <summary>
				/// �p�u���b�V���[�̓o�^
				/// </summary>
				template<class Publisher>
				void RegisterOfPublisher();

				/// <summary>
				/// �p�u���b�V���[�̓o�^����
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