/**
* @file		JobExecuterBase.h
* @brief	タスク実行機能ベースの機能提供
* @author	S.OIKAWA
* @date		2016.11.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IOrderedJobExecutable.h"
#include"../ThreadSystem.h"
#include"../Order/TaskContainer.h"
#include"../Order/TaskLine.h"
#include<vector>
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
		namespace Worker
		{
			/// <summary>
			/// ディスパッチと現スレッド実行のインターフェースを定義
			/// </summary>
			class JobExecuterBase :
				public IOrderedJobExecutable
			{
			protected:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				JobExecuterBase();
				virtual ~JobExecuterBase() = default;

				JobExecuterBase(const JobExecuterBase&) = default;
				JobExecuterBase(JobExecuterBase&&) = default;

				JobExecuterBase& operator=(const JobExecuterBase&) = default;
				JobExecuterBase& operator=(JobExecuterBase&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// タスクをジョブに振り分ける
				/// </summary>
				template<class JobType,class OrderData>
				void JobDispatch(std::vector<JobType>&, OrderData&);

				/// <summary>
				/// ジョブを現在のスレッドで実行する
				/// スレッドが使えなかった場合に使用
				/// </summary>
				virtual void ExecuteThisThread() = 0;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion
			protected:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				ThreadSystem&					m_ThreadSystem;
#pragma endregion
			};
#include"JobExecuterBase.inl"

		}
	}
}
	

	//-----------------------------------------------------------
	// EOF
	//-----------------------------------------------------------