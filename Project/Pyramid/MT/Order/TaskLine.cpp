/**
* @file		TaskLine.cpp
* @brief	平行して行うタスク可変長配列
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TaskLine.h"
#include"IExecuteable.h"
#include"../Constant.h"
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{
		namespace Order
		{

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			TaskLine::TaskLine()
			{
				m_pJobList
					.reserve(Constant::JobListDefaultReserveInLine);
			}

			//-----------------------------------------------------------
			// Add 
			//-----------------------------------------------------------
			void TaskLine::Add(Utility::IExecuteable * _job)
			{
#ifdef _DEBUG 
				auto it = Utility::Estd::find(m_pJobList, _job);
				if (m_pJobList.end() != it)
				{
					___D_LOG("ジョブの多重登録");
				}
#endif // _DEBUG 
				
				m_pJobList.push_back(_job);
			}

			//-----------------------------------------------------------
			// Remove 
			//-----------------------------------------------------------
			void TaskLine::Remove(Utility::IExecuteable * _job)
			{
				m_pJobList.erase(
					std::find(m_pJobList.begin(), m_pJobList.end(), _job));
			}

			//-----------------------------------------------------------
			// Run 
			//-----------------------------------------------------------
			void TaskLine::Run()
			{
				Utility::Estd::for_each(m_pJobList, [](auto& _) {_->Execution(); });
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------