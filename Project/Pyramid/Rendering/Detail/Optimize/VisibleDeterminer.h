/**
* @file		VisibleDeterminer.h
* @brief	オブジェクト単位の可視決定を行う
* @author	S.OIKAWA
* @date		2016.12.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../../../Common/Diagram/Plane.h"
#include"../../../Common/WorldVolume.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			class Frustum;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				/// <summary>
				/// オブジェクト単位の可視決定を行う
				/// </summary>
				class VisibleDeterminer final
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					VisibleDeterminer(Common::WorldVolume&);
					~VisibleDeterminer() = default;

					VisibleDeterminer(const VisibleDeterminer&);
					VisibleDeterminer(VisibleDeterminer&&) = default;

					VisibleDeterminer& operator=(const VisibleDeterminer&) = default;
					VisibleDeterminer& operator=(VisibleDeterminer&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// TODO ヒットコードから次の当たり判定順を決定
					/// </summary>
					bool IsInSideFrustum(Frustum&);
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY(m_RenderVolume, RenderVolume, Common::WorldVolume&);
#pragma endregion
				protected:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					Common::WorldVolume&	m_RenderVolume;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------