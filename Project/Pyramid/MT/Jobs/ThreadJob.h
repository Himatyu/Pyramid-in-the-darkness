/**
* @file			ThreadJob.h
* @brief		非同期で実行されるオブジェクト更新
* @author		S.OIKAWA
* @date			2016.4.30
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../MT/Jobs/IThreadJob.h"
#include<vector>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			/// <summary>
			/// 非同期で実行されるオブジェクト更新
			/// </summary>
			class ThreadJob final :
				public IThreadJob
			{
			public:
				//-----------------------------------------------------------
				// default
				//-----------------------------------------------------------
				ThreadJob() = default;
				virtual ~ThreadJob() = default;

				ThreadJob(const ThreadJob&) = default;
				ThreadJob(ThreadJob&&) = default;

				ThreadJob&operator=(const ThreadJob&) = default;
				ThreadJob&operator=(ThreadJob&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// オブジェクト更新
				/// </summary>
				virtual void Job() override;

				//-----------------------------------------------------------
				// property 
				//-----------------------------------------------------------
				PROPERTY_REF(m_pJobs, pJobs, std::vector<Utility::IExecuteable*>);
			private:
				//-----------------------------------------------------------
				// val 
				//-----------------------------------------------------------
				std::vector<Utility::IExecuteable*>		m_pJobs;
			};

		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
