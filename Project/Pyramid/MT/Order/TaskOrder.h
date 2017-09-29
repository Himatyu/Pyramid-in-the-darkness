/**
* @file		TaskOrder.h
* @brief	コンポーネント・オブジェクトにタスクを登録する機能を提供
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
			/// コンポーネント・オブジェクトにタスクを登録する機能を提供
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
				/// タスクを並行実行するリストに登録する.
				/// 同グループかつ同ラインに同一インスタンスの関数を登録しないこと.
				/// </summary>
				template<class Func>
				void Order(Func && _func, std::string _group, u_int _lineID);

				/// <summary>
				/// オーダーされたジョブをキャンセルして、データを開放する
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

