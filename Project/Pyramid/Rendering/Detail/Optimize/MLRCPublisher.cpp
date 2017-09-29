/**
* @file		MLRCPublisher.cpp
* @brief	��������s���A�K�v�ł���΃����_�����O���s��
* @author	S.OIKAWA
* @date		2016.12.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"MLRCPublisher.h"
#include"../Frustum.h"
#include"../WorldObjectRender.h"
#include"../OptimizationRender.h"
#include"../Common/WorldVolume.h"
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
				MLRCPublisher::MLRCPublisher(
					Common::WorldVolume &	_vol,
					OptimizationRender*		_pRender) :
					m_Determiner(_vol),
					m_pRender(_pRender)
				{
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				MLRCPublisher::MLRCPublisher(const MLRCPublisher& _publisher):
					m_Determiner(_publisher.m_Determiner),
					m_pRender(_publisher.m_pRender),
					m_MLRC(_publisher.m_MLRC)
				{
				}

				//-----------------------------------------------------------
				// IsPublish
				//-----------------------------------------------------------
				bool MLRCPublisher::IsPublish(Frustum& _frustum)
				{
					if (!m_IsCommandPublish)
					{
						return false;
					}
					return m_Determiner.IsInSideFrustum(_frustum);
				}

				//-----------------------------------------------------------
				// SetCommand
				//-----------------------------------------------------------
				void MLRCPublisher::SetMLRCommand(UINT _priority)
				{
					auto& Com = m_MLRC;
					Com.pTarget = m_pRender;
					Com.pWorldPosition = m_pRender->RenderVolume.pPosition;
					Com.Priority = _priority;

					m_Determiner.RenderVolume.pPosition = Com.pWorldPosition;
				}

				//-----------------------------------------------------------
				// PublishMLRC
				//-----------------------------------------------------------
				MLRC * MLRCPublisher::PublishMLRC()
				{
					return &m_MLRC;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------