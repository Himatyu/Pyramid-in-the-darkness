/**
* @file		ComponentStateSubject.h
* @brief	�R���|�[�l���g�̏�Ԃ��I�u�W�F�N�g�ɒʒm
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include<memory>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		class Component;
	}
};
#pragma endregion

namespace Pyramid
{
	namespace Components
	{
		namespace Observers
		{
			class ComponentStateObserver;

			/// <summary>
			/// �R���|�[�l���g�̏�Ԃ�ʒm.
			/// </summary>
			class ComponentStateSubject final
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ComponentStateSubject() = default;
				virtual ~ComponentStateSubject() = default;

				ComponentStateSubject(const ComponentStateSubject&) = default;
				ComponentStateSubject(ComponentStateSubject&&) = default;

				ComponentStateSubject& operator=(const ComponentStateSubject&) = default;
				ComponentStateSubject& operator=(ComponentStateSubject&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>�Ď��ғo�^</summary>	
				///<param name="_obser">�o�^�Ď���</param>
				void Attach(ComponentStateObserver* _obser);

				/// <summary>�Ď��ҍ폜</summary>
				///<param name="_obser">�폜�Ď���</param>
				void Detach(ComponentStateObserver* _obser);

				/// <summary>�ʒm</summary>
				void Notify();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_pOwner, pOwner, Component*);
				PROPERTY_REF(m_Ovservers, Ovservers, std::vector<ComponentStateObserver*>);
#pragma endregion

			protected:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::vector<ComponentStateObserver*>	m_Ovservers;
				Component*								m_pOwner;			//sp���Ǝ��ȎQ�Ƃ��N����
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------