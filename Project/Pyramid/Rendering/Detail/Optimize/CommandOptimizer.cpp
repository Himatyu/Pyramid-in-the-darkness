/**
* @file		CommandOptimizer.cpp
* @brief	レンダリングコマンドを最適化する
* @author	S.OIKAWA
* @date		2017.03.24
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"CommandOptimizer.h"
#include"Context.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				CommandOptimizer::CommandOptimizer(
					HLRCommand::HLRCommandPipeline & _line,
					Common::WorldVolume & _volume) :
					m_Optimizate(_line),
					m_Switcher(_volume)
				{						
				}


				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				CommandOptimizer::CommandOptimizer(const CommandOptimizer & _other):
					m_Optimizate(_other.m_Optimizate),
					m_Switcher(_other.m_Switcher)
				{
				}


				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void CommandOptimizer::Init()
				{
					m_Optimizate.Init();
				}

				//-----------------------------------------------------------
				// RunOptimize
				//-----------------------------------------------------------
				void CommandOptimizer::RunOptimize(
					const Context & _context)
				{
					m_Switcher.Run(_context.RefCameraPos);
					m_Optimizate.Execut(_context.ContinuityAttribute);
				}

				//-----------------------------------------------------------
				// AddLODSwitchEvent
				//-----------------------------------------------------------
				void CommandOptimizer::AddLODSwitchEvent(SwitchEvent & _event)
				{
					m_Switcher.Add(&_event);
				}

				//-----------------------------------------------------------
				// RemoveLODSwitchEvent
				//-----------------------------------------------------------
				void CommandOptimizer::RemoveLODSwitchEvent(SwitchEvent & _event)
				{
					m_Switcher.Remove(&_event);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------