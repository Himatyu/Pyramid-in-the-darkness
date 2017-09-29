/**
* @file		OrderedJobExcuter.cpp
* @brief	タスクを実行するジョブを持つ
* @author	S.OIKAWA
* @date		2016.11.25
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OrderedJobExcuter.h"
#include"../MT/Worker/IOrderedJobExecutable.h"
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
			// dtor
			//-----------------------------------------------------------
			OrderedJobExcuter::~OrderedJobExcuter()
			{
				for (auto& _ : m_Executers)
				{
					if (_.second.second)
					{
						SAFE_DELETE(_.second.first);
					}
				}
			}

			//-----------------------------------------------------------
			// UnRegister
			//-----------------------------------------------------------
			void OrderedJobExcuter::UnRegister(const std::string& _key)
			{
				auto findResult = m_Executers.find(_key);
				if (m_Executers.end() == findResult)
				{
					return;
				}
				SAFE_DELETE((*findResult).second.first);
				m_Executers.erase(_key);
			}

			//-----------------------------------------------------------
			// Run
			//-----------------------------------------------------------
			void OrderedJobExcuter::Run(const std::string& _key)
			{
				auto findResult = m_Executers.find(_key);
				if (m_Executers.end() == findResult)
				{
					return;
				}
				(*findResult).second.first->Execution();
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


