/**
* @file			ThreadJob.h
* @brief		�񓯊��Ŏ��s�����I�u�W�F�N�g�X�V
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
			/// �񓯊��Ŏ��s�����I�u�W�F�N�g�X�V
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
				/// �I�u�W�F�N�g�X�V
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
