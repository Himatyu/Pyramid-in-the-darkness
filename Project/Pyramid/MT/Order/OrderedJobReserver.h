/**
* @file		OrderedJobReserver.h
* @brief	マルチスレッドで実行されるタスクを持つ
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
			/// マルチスレッドで実行されるタスクを持つ.
			/// 持てるタスクはIExecuteableの継承したもののみ
			/// それ以外は別のタスクの集合体を直にOrderedJobExcuterに登録する
			/// TODO Key:stringじゃなくてu_intで良さそう
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
				/// 関数の登録.
				/// 重複登録はしない.
				/// グループかラインが異なれば登録可.
				/// </summary>
				void Register(
					Utility::IExecuteable* _pJob,
					std::string _group, 
					u_int _lineID);

				/// <summary>
				/// 登録削除.
				/// なければ何もしない.
				/// </summary>
				void UnRegister(
					Utility::IExecuteable* _pJob,
					std::string _group, 
					u_int _lineID);

				/// <summary>
				/// コンテナ検索.
				/// </summary>
				Utility::Nullable<TaskContainer*> SearchContainer(std::string _group);

				/// <summary>
				/// コンテナを事前確保する
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

