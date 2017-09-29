/**
* @file		OrderedJobReserver.h
* @brief	マルチスレッドで実行されるタスクを持つ
* @author	S.OIKAWA
* @date		2016.09.20
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TaskContainer.h"
#include"OrderedJobReserver.h"
#include"IExecuteable.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Utility;
namespace Pyramid
{
	namespace MT
	{
		namespace Order
		{
			using namespace std;
			//-----------------------------------------------------------
			// ctor 
			//-----------------------------------------------------------
			OrderedJobReserver::OrderedJobReserver()
			{
			}
			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			OrderedJobReserver::~OrderedJobReserver()
			{
				Utility::Estd::for_each(
					m_Reserve,
					[](auto& _) {SAFE_DELETE(_.second); });
			}

			//-----------------------------------------------------------
			// Register
			//-----------------------------------------------------------
			void OrderedJobReserver::Register(
				Utility::IExecuteable * _pJob,
				std::string _group,
				u_int _lineID)
			{
				auto it = m_Reserve.find(_group);
				if (m_Reserve.end() == it)
				{
					m_Reserve.insert(make_pair(_group, new TaskContainer));
					it = m_Reserve.find(_group);
				}
				it->second->Add(_pJob, _lineID);
			}

			//-----------------------------------------------------------
			// UnRegister
			//-----------------------------------------------------------
			void OrderedJobReserver::UnRegister(
				Utility::IExecuteable * _pJob,
				std::string _group,
				u_int _lineID)
			{
				auto it = m_Reserve.find(_group);
				if (m_Reserve.end() == it)
				{
					___D_LOG("存在しないグループへの登録解除要求 : " + _group);
					return;
				}
				it->second->Remove(_pJob, _lineID);
			}

			//-----------------------------------------------------------
			// Search
			//-----------------------------------------------------------
			Nullable<TaskContainer*> OrderedJobReserver::SearchContainer(
				std::string _group
			)
			{
				auto it = m_Reserve.find(_group);
				if (m_Reserve.end() == it)
				{
					return Nullable<TaskContainer*>();
				}
				return Nullable<TaskContainer*>(it->second);
			}

			//-----------------------------------------------------------
			// Reserve
			//-----------------------------------------------------------
			TaskContainer* OrderedJobReserver::Reserve(std::string _group)
			{
				auto it = m_Reserve.find(_group);
				if (m_Reserve.end() != it)
				{
					return (*it).second;
				}
				auto pContainer = new TaskContainer;
				m_Reserve.insert(make_pair(_group, pContainer));
				return pContainer;
			}

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
