/**
* @file		MLRCPublisher.h
* @brief	可視判定を行い、必要であればレンダリングを行う
* @author	S.OIKAWA
* @date		2016.12.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"VisibleDeterminer.h"
#include"../../RendringPriority.h"
#include"../../Detail/Optimize/MLRC.h"
#include"../MT/Order/IMLRCPublishable.h"
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
			class OptimizationRender;
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
				/// 可視判定を行い、必要であればコマンドの発行を行う
				/// OptimizationRender対応なのはMTで最適化を行うのが前提だから
				/// </summary>
				class MLRCPublisher :
					public MT::Order::IMLRCPublishable
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					MLRCPublisher(Common::WorldVolume&, OptimizationRender*);
					virtual ~MLRCPublisher() = default;

					MLRCPublisher(const MLRCPublisher&);
					MLRCPublisher(MLRCPublisher&&) = default;

					MLRCPublisher& operator=(const MLRCPublisher&);
					MLRCPublisher& operator=(MLRCPublisher&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					/// <summary>
					/// コマンド発行の有無を確認する
					/// </summary>
					bool IsPublish(Frustum&);

					/// <summary>
					/// MLRCのコマンドを設定する
					/// </summary>
					void SetMLRCommand(UINT);

					/// <summary>
					/// 
					/// </summary>
					MLRC* PublishMLRC() override;

#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_REF(m_IsCommandPublish, IsCommandPublish, bool);
#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					VisibleDeterminer			m_Determiner;
					MLRC						m_MLRC;
					bool						m_IsCommandPublish = true;
					OptimizationRender*			m_pRender;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------