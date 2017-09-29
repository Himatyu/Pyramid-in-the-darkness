/**
* @file		DrawIndexedPrimitive.cpp
* @brief	インデックス付きのレンダリングコマンド
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"DrawIndexedPrimitive.h"
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
			DrawIndexedPrimitive::DrawIndexedPrimitive(
				DrawIndexedParam _param, ::Utility::CommandExecutor* _pExe):
				HLRCommandBase(_param,_pExe)
			{
			}

			//-----------------------------------------------------------
			// Execute
			//-----------------------------------------------------------
			void DrawIndexedPrimitive::Execute()
			{
				auto pDevice = Graphics::Instantiate().Device;
				pDevice->DrawIndexedPrimitive(
					std::get<0>(m_PushData),
					std::get<1>(m_PushData),
					std::get<2>(m_PushData),
					std::get<3>(m_PushData),
					std::get<4>(m_PushData),
					std::get<5>(m_PushData));
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------