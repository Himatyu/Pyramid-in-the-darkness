/**
* @file		MCIMessageDispatcher.h
* @brief	WinProc���瓊������MCI���b�Z�[�W�𓊂���
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
			/// ���b�Z�[�W�f�B�X�p�b�`��
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
				/// ���b�Z�[�W�f�B�X�p�b�`
				/// </summary>
				void DispatchMessage(WPARAM wp, LPARAM lp);

				/// <summary>
				/// �o�^.
				/// </summary>
				void Register(MCIAudioFile* _pMCIAudioFile);

				/// <summary>
				/// �o�^����. 
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
