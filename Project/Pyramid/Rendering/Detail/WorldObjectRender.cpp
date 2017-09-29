/**
* @file		WorldObjectRender.cpp
* @brief	ワールド空間のオブジェクトをレンダリングする
* @author	S.OIKAWA
* @date		2017.03.24
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"WorldObjectRender.h"
#include"../Components/Transform.h"
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
			WorldObjectRender::WorldObjectRender(
				HLRCommand::HLRCommandPipeline& _line):
				Render(_line)
			{
			}

			//-----------------------------------------------------------
			// Init
			//-----------------------------------------------------------
			void WorldObjectRender::Init(
				Common::Diagram::AABB & _aabb, Utility::Vector3 * _pPos)
			{
				m_RenderVolume.pPosition = _pPos;
				m_RenderVolume.Volume = _aabb;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------