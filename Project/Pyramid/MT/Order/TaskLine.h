/**
* @file		TaskLine.h
* @brief	平行して行うタスク可変長配列
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include<functional>
#include"IExecuteable.h"
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
			/// 平行して行うタスク可変長配列
			/// </summary>
			class TaskLine
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				TaskLine();
				~TaskLine() = default;

				TaskLine(const TaskLine&) = default;
				TaskLine(TaskLine&&) = default;

				TaskLine& operator=(const TaskLine&) = default;
				TaskLine& operator=(TaskLine&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// タスク追加.
				/// </summary>
				void Add(Utility::IExecuteable* _job);

				/// <summary>
				/// タスク除去.
				/// </summary>
				void Remove(Utility::IExecuteable* _job);

				/// <summary>
				/// 実行.
				/// 順不同.
				/// </summary>
				void Run();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(
					m_pJobList, 
					pJobList, 
					std::vector<Utility::IExecuteable*>);
#pragma endregion

			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::vector<Utility::IExecuteable*> m_pJobList;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------