/**
* @file		StaticDefaultCommand.cpp
* @brief	デフォルトのコマンドを所持
* @author	S.OIKAWA
* @date		2016.12.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"StaticDefaultCommand.h"
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
			namespace Default
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				StaticDefaultCommand::StaticDefaultCommand():
					m_DefaultCommands{
					new Default::BeginScene,
					new Default::SetVertexDeclaration,
					new Default::SetVertex,
					new Default::SetIndex,
					new Default::SetMaterial,
					new Default::Draw,
					new Default::RiseMateral,
					new Default::EndScene }
				{
				}

				//-----------------------------------------------------------
				// dtor
				//-----------------------------------------------------------
				StaticDefaultCommand::~StaticDefaultCommand()
				{
					for (auto& _ : m_DefaultCommands)
					{
						SAFE_DELETE(_);
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------