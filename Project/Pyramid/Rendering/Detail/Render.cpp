/**
* @file		Render.cpp
* @brief	レンダリングを行う
* @author	S.OIKAWA
* @date		2017.03.23
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Render.h"
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

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Render::Render(HLRCommand::HLRCommandPipeline & _line):
				m_Pipeline(_line)
			{
			}

			//-----------------------------------------------------------
			// Rendering
			//-----------------------------------------------------------
			void Render::Rendering()
			{
				m_Pipeline.Run();
			}
		}
	}
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------