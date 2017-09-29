/**
* @file		TaskOrder.h
* @brief	�R���|�[�l���g�E�I�u�W�F�N�g�Ƀ^�X�N��o�^����@�\���
* @author	S.OIKAWA
* @date		2016.09.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>
#include"OrderData.h"
#include"IExecuteable.h"
#include"OrderedJobReserver.h"
#include"Executer.h"
#include"Estd.h"
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
			/// <summary>
			/// �R���|�[�l���g�E�I�u�W�F�N�g�Ƀ^�X�N��o�^����@�\���
			/// </summary>
			template<class Type>
			class TaskOrder
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				TaskOrder() = default;
				virtual ~TaskOrder();

				TaskOrder(const TaskOrder&) = default;
				TaskOrder(TaskOrder&&) = default;

				TaskOrder& operator=(const TaskOrder&) = default;
				TaskOrder& operator=(TaskOrder&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �^�X�N����s���s���郊�X�g�ɓo�^����.
				/// ���O���[�v�������C���ɓ���C���X�^���X�̊֐���o�^���Ȃ�����.
				/// </summary>
				template<class Func>
				void Order(Func && _func, std::string _group, u_int _lineID);

				/// <summary>
				/// �I�[�_�[���ꂽ�W���u���L�����Z�����āA�f�[�^���J������
				/// </summary>
				void OrderCancel(OrderData*);

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_OrderList, OrderList, std::vector<OrderData*>);
#pragma endregion

			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::vector<OrderData*>		m_OrderList;
#pragma endregion
			};
#include"TaskOrder.inl"
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

