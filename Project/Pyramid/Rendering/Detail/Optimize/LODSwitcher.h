/**
* @file		LODSwitcher.h
* @brief	レベルに応じてパイプラインを組み替える
* @author	S.OIKAWA
* @date		2017.01.27
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Common/WorldVolume.h"
#include"../Utility/Vector3.h"
#include"../Utility/Range.h"
#include"../Utility/Manager.h"
#include<vector>
#include<functional>
#include<utility>
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
			namespace Optimize
			{
				using SwitchEvent = std::pair<Utility::Range<float>, std::function<void()>>;
			}
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
				/// レベルに応じてパイプラインを組み替える
				/// ハイレベルとローレベルで切り分ける
				/// 閾値の初期値は1000
				/// </summary>
				class LODSwitcher : 
					public Utility::Manager<std::vector<SwitchEvent*>>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					LODSwitcher(Common::WorldVolume&);
					~LODSwitcher() = default;

					LODSwitcher(const LODSwitcher&);
					LODSwitcher(LODSwitcher&&) = default;

					LODSwitcher& operator=(const LODSwitcher&) = default;
					LODSwitcher& operator=(LODSwitcher&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// カメラとの距離から自身のレベルを算出しイベントを発行
					/// </summary>
					void Run(Utility::Vector3& _cameraPos);

				private:
					float CulclateDistance(Utility::Vector3& _cameraPos);
										
#pragma endregion
				public:
#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_R_ONLY(m_DistanceToCamera, DistanceToCamera,float);
#pragma endregion
				
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					Common::WorldVolume&	m_RefRenderingVolume;
					Utility::Range<float>	m_Cash;
					float					m_DistanceToCamera;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------