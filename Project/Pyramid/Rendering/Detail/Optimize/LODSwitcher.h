/**
* @file		LODSwitcher.h
* @brief	���x���ɉ����ăp�C�v���C����g�ݑւ���
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
				/// ���x���ɉ����ăp�C�v���C����g�ݑւ���
				/// �n�C���x���ƃ��[���x���Ő؂蕪����
				/// 臒l�̏����l��1000
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
					/// �J�����Ƃ̋������玩�g�̃��x�����Z�o���C�x���g�𔭍s
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