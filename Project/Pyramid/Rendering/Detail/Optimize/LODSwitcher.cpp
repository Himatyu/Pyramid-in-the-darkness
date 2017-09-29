/**
* @file		LODSwitcher.cpp
* @brief	レベルに応じてパイプラインを組み替える
* @author	S.OIKAWA
* @date		2017.01.27
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"LODSwitcher.h"
#include"../../Constant.h"
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
				LODSwitcher::LODSwitcher(Common::WorldVolume & _refVolume) :
					m_RefRenderingVolume(_refVolume),
					m_Cash(-1,-1)
				{
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				LODSwitcher::LODSwitcher(const LODSwitcher & _other) :
					Utility::Manager<std::vector<SwitchEvent*>>(*this),
					m_RefRenderingVolume(_other.m_RefRenderingVolume),
					m_Cash(-1, -1)
				{
				}

				//-----------------------------------------------------------
				// CalculatLevel
				//-----------------------------------------------------------
				void LODSwitcher::Run(Utility::Vector3& _cameraPos)
				{
					m_DistanceToCamera= CulclateDistance(_cameraPos);

					std::function<bool(SwitchEvent*)>
					 pred =
						[this](SwitchEvent* _pEvent)
					{
						return _pEvent->first.IsContains(m_DistanceToCamera);
					};
					auto result = Select(pred);

					
					if (!result)
					{
						return;
					}
								
					_ASSERT_EXPR(result.Value.size()<=1,L"重複するLODRangeの設定");

					auto& pair = result.Value.front();
					if(pair->first == m_Cash)
					{
						return;
					}

					pair->second();
				}

				//-----------------------------------------------------------
				// CulclateDistance
				//-----------------------------------------------------------
				float
				LODSwitcher::CulclateDistance(Utility::Vector3 & _cameraPos)
				{
					auto woldVolume = m_RefRenderingVolume.CalculatWorldVolume();

					auto min = woldVolume.Min - _cameraPos;
					auto max = woldVolume.Max - _cameraPos;

					auto distanceToCamera =
						sqrt(min(min.GetLengthSquared(), max.GetLengthSquared()));

					return distanceToCamera;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------