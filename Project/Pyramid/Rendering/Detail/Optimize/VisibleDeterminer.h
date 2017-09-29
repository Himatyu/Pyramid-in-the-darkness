/**
* @file		VisibleDeterminer.h
* @brief	�I�u�W�F�N�g�P�ʂ̉�������s��
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
				/// �I�u�W�F�N�g�P�ʂ̉�������s��
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
					/// TODO �q�b�g�R�[�h���玟�̓����蔻�菇������
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