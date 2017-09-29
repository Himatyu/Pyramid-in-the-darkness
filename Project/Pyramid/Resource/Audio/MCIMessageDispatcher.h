/**
* @file		MCIMessageDispatcher.h
* @brief	WinProcから投げられるMCIメッセージを投げる
* @author	S.OIKAWA
* @date		2016.08.24
*/

#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<list>
#include<memory>
#include"singleton.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Audio
		{
			class MCIAudioFile;
			/// /// <summary>
			/// メッセージディスパッチャ
			/// </summary>
			class MCIMessageDispatcher final :
				public Utility::Singleton<MCIMessageDispatcher>
			{
				//-----------------------------------------------------------
				// defaluts 
				//-----------------------------------------------------------
			public:
				MCIMessageDispatcher() = default;
				~MCIMessageDispatcher() = default;

				MCIMessageDispatcher(const MCIMessageDispatcher&) = default;
				MCIMessageDispatcher(MCIMessageDispatcher&&) = default;

				MCIMessageDispatcher&operator=(const MCIMessageDispatcher&) = default;
				MCIMessageDispatcher&operator=(MCIMessageDispatcher&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// メッセージディスパッチ
				/// </summary>
				void DispatchMessage(WPARAM wp, LPARAM lp);

				/// <summary>
				/// 登録.
				/// </summary>
				void Register(MCIAudioFile* _pMCIAudioFile);

				/// <summary>
				/// 登録解除. 
				/// </summary>
				void UnRegister(MCIAudioFile* _pMCIAudioFile);

			private:
				//-----------------------------------------------------------
				// val 
				//-----------------------------------------------------------
				std::list<MCIAudioFile*> m_pListenerList;

			};
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
