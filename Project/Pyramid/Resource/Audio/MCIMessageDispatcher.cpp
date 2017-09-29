/**
* @file		MCIMessageDispatcher.cpp
* @brief	メッセージディスパッチ実装
* @author	S.OIKAWA
* @date		2016.08.24
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "MCIMessageDispatcher.h"
#include"MCIAudioFile.h"
#include"Estd.h"
#include<algorithm>

namespace Pyramid
{
	namespace Resources
	{
		namespace Audio
		{
			using namespace std;
			//-----------------------------------------------------------
			// DispatchMessage 
			//-----------------------------------------------------------
			void MCIMessageDispatcher::DispatchMessage(WPARAM wp, LPARAM lp)
			{
				Utility::Estd::for_each
				(
					m_pListenerList,
					[lp, wp](MCIAudioFile* _)
				{
					if (_->OpenParams.wDeviceID == lp && wp == MCI_NOTIFY_SUCCESSFUL)
						_->NotifySuccessFul();
				});
			}

			//-----------------------------------------------------------
			// Register 
			//-----------------------------------------------------------
			void MCIMessageDispatcher::Register(MCIAudioFile * _pMCIAudioFile)
			{
				m_pListenerList.push_back(_pMCIAudioFile);
			}

			//-----------------------------------------------------------
			// UnRegister 
			//-----------------------------------------------------------
			void MCIMessageDispatcher::UnRegister(MCIAudioFile * _pMCIAudioFile)
			{
				//staticなAudioがあると開放順序の関係でイテレータが死ぬ
				if (m_pListenerList.empty())
				{
					return;
				}
				m_pListenerList.remove(_pMCIAudioFile);
			}
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------