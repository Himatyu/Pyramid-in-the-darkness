/**
* @file		WorldObjectRender.h
* @brief	ワールド空間のオブジェクトをレンダリングする
* @author	S.OIKAWA
* @date		2017.03.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Render.h"
#include"../Common/WorldVolume.h"
#include"../Common/Defines.h"
#include"../HLRCommand/HLRCommandPipeline.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			/// <summary>
			/// ワールド空間のオブジェクトをレンダリングする
			/// </summary>
			class WorldObjectRender : 
				public Render
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				WorldObjectRender(HLRCommand::HLRCommandPipeline&);
				~WorldObjectRender() = default;

				WorldObjectRender(const WorldObjectRender&) = default;
				WorldObjectRender(WorldObjectRender&&) = default;

				WorldObjectRender& operator=(const WorldObjectRender&) = default;
				WorldObjectRender& operator=(WorldObjectRender&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// WorldVolumeを初期化する
				///	初期化を継承先のInitで行うよう推奨
				/// 継承先のInitがない際Initを生成しないように公開関数
				/// </summary>
				void Init(Common::Diagram::AABB&, Utility::Vector3*);

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY_REF(m_RenderVolume, RenderVolume, Common::WorldVolume);
#pragma endregion
			protected:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				Common::WorldVolume		m_RenderVolume;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------