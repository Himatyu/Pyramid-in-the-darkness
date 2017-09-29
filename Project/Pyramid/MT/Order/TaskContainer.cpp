/**
* @file		TaskContainer.cpp
* @brief	可変長2次元配列のタスクコンテナ
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IExecuteable.h"
#include"TaskContainer.h"
#include"TaskLine.h"
#include"../Constant.h"
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
			TaskContainer::TaskContainer()
			{
				m_pJobLines
					.reserve(Constant::JobLineDefaultReserveInContainer);
				m_pJobLines
					.resize(Constant::JobLineDefaultReserveInContainer);
				Utility::Estd::for_each(m_pJobLines, [](auto& _) { _ = new TaskLine; });
			}

			//-----------------------------------------------------------
			// ctor : u_int 
			//-----------------------------------------------------------
			TaskContainer::TaskContainer(u_int _reserve)
			{
				m_pJobLines.reserve(_reserve);
				m_pJobLines.resize(_reserve);
				Utility::Estd::for_each(m_pJobLines, [](auto& _) { _ = new TaskLine; });
			}

			//-----------------------------------------------------------
			// dtor 
			//-----------------------------------------------------------
			TaskContainer::~TaskContainer()
			{
				Utility::Estd::for_each(m_pJobLines, [](auto& _) {SAFE_DELETE(_); });
			}

			//-----------------------------------------------------------
			// Add 
			//-----------------------------------------------------------
			void TaskContainer::Add(MTJob * _pJob, u_int _lineID)
			{
				if (m_pJobLines.size() < _lineID)
				{
					m_pJobLines.resize(_lineID + 1);
					Utility::Estd::for_each(m_pJobLines,
						[](auto& _) {
						if (!_)
						{
							_ = new TaskLine;
						}
					});
					m_pJobLines[_lineID]->Add(_pJob);
					return;
				}
				m_pJobLines[_lineID]->Add(_pJob);
			}

			//-----------------------------------------------------------
			// Remove 
			//-----------------------------------------------------------
			void TaskContainer::Remove(MTJob * _pJob, u_int _lineID)
			{
				if (m_pJobLines.size() < _lineID)
				{
					___D_LOG("存在しないライン " + std::to_string(_lineID) + " への削除要求");
					return;
				}
				m_pJobLines[_lineID]->Remove(_pJob);
			}

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
