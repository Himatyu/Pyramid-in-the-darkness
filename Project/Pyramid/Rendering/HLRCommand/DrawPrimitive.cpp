/**
* @file		DrawPrimitive.cpp
* @brief	レンダリングコマンド
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"DrawPrimitive.h"
#include"../Graphics.h"
#include"CommandExecutor.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			DrawPrimitive::DrawPrimitive(DrawParam _param,
				::Utility::CommandExecutor* _pExe):
				HLRCommandBase(_param,_pExe)
			{
			}

			//-----------------------------------------------------------
			// Execute
			//-----------------------------------------------------------
			void DrawPrimitive::Execute()
			{
				auto pDevice = Graphics::Instantiate().Device;
				pDevice->DrawPrimitive(
					std::get<0>(m_PushData), 
					std::get<1>(m_PushData), 
					std::get<2>(m_PushData));
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------