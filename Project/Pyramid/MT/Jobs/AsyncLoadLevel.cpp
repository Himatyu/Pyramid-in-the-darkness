/**
* @file		AsyncLoadLevel.cpp
* @brief	�񓯊��̃��x���ǂݍ��݂��
* @author	S.OIKAWA
* @date		2016.10.08
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"AsyncLoadLevel.h"
#include"../Blueprint/Level.h"
#include"Creator.h"
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{
		class Level;
	}
}

namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			//-----------------------------------------------------------
			// dtor 
			//-----------------------------------------------------------
			AsyncLoadLevel::~AsyncLoadLevel()
			{
				Utility::Estd::for_each(
					m_LevelLoadRequestList,
					[](auto& _) {SAFE_DELETE(_.first); });
				m_LevelLoadRequestList.clear();
			}

			//-----------------------------------------------------------
			// Job 
			//-----------------------------------------------------------
			void AsyncLoadLevel::Job()
			{
				while (true)
				{
					m_LevelLoadRequestListMutex.lock();
					if (!m_LevelLoadRequestList.size())
					{
						m_LevelLoadRequestListMutex.unlock();
						break;
					}

					auto reqestDate = m_LevelLoadRequestList.front();
					m_LevelLoadRequestList.pop_front();
					//�����ŊJ�����ă��[�h��������Rqest���X�g��ǉ��\�ɂ���
					m_LevelLoadRequestListMutex.unlock();

					m_IsInterruptionMutex.lock();
					if (m_IsInterruption)
					{
						m_IsInterruptionMutex.unlock();
						break;
					}
					m_IsInterruptionMutex.unlock();

					//���b�N���Ԃ�Z���������̂ŊO�Ńf�[�^���쐬
					auto pLevel = reqestDate.first->Create();
					SAFE_DELETE(reqestDate.first);

					auto data = std::make_pair(pLevel, reqestDate.second);

					m_LoadedLevelListMutex.lock();
					m_LoadedLevelList.push_back(data);
					m_LoadedLevelListMutex.unlock();
				}

				Utility::Estd::for_each(
					m_LevelLoadRequestList, 
					[](auto& _) {SAFE_DELETE(_.first); });
				m_LevelLoadRequestList.clear();
			}

			//-----------------------------------------------------------
			// Interruption 
			//-----------------------------------------------------------
			void AsyncLoadLevel::Interruption()
			{
				std::lock_guard<::std::mutex> lg(m_IsInterruptionMutex);
				m_IsInterruption = true;
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
