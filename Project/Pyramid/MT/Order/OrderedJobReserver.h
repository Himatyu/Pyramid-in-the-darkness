/**
* @file		OrderedJobReserver.h
* @brief	�}���`�X���b�h�Ŏ��s�����^�X�N������
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<unordered_map>
#include<string>
#include"singleton.h"
#include"Nullable.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion

namespace Pyramid
{
	namespace MT
	{
		namespace Order
		{
			class TaskContainer;

			/// <summary>
			/// �}���`�X���b�h�Ŏ��s�����^�X�N������.
			/// ���Ă�^�X�N��IExecuteable�̌p���������̂̂�
			/// ����ȊO�͕ʂ̃^�X�N�̏W���̂𒼂�OrderedJobExcuter�ɓo�^����
			/// TODO Key:string����Ȃ���u_int�ŗǂ�����
			/// </summary>
			class OrderedJobReserver final :
				public Utility::Singleton<OrderedJobReserver>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				OrderedJobReserver();
				~OrderedJobReserver();

				OrderedJobReserver(const OrderedJobReserver&) = default;
				OrderedJobReserver(OrderedJobReserver&&) = default;

				OrderedJobReserver& operator=(const OrderedJobReserver&) = default;
				OrderedJobReserver& operator=(OrderedJobReserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �֐��̓o�^.
				/// �d���o�^�͂��Ȃ�.
				/// �O���[�v�����C�����قȂ�Γo�^��.
				/// </summary>
				void Register(
					Utility::IExecuteable* _pJob,
					std::string _group, 
					u_int _lineID);

				/// <summary>
				/// �o�^�폜.
				/// �Ȃ���Ή������Ȃ�.
				/// </summary>
				void UnRegister(
					Utility::IExecuteable* _pJob,
					std::string _group, 
					u_int _lineID);

				/// <summary>
				/// �R���e�i����.
				/// </summary>
				Utility::Nullable<TaskContainer*> SearchContainer(std::string _group);

				/// <summary>
				/// �R���e�i�����O�m�ۂ���
				/// </summary>
				TaskContainer* Reserve(std::string _group);
#pragma endregion

			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::unordered_map<std::string, TaskContainer*>		m_Reserve;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

