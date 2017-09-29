/**
* @file		JudgmentSameSpaceOfFrustum.cpp
* @brief	éãêçë‰Ç∆ìØãÛä‘Ç©îªíËÇ∑ÇÈ
* @author	S.OIKAWA
* @date		2017.01.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"JudgmentSameSpaceOfFrustum.h"
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
				JudgmentSameSpaceOfFrustum::
					JudgmentSameSpaceOfFrustum(Common::WorldVolume & _world) :
					OctreeRegistrableObject(_world)
				{
					TypeComparable::TypeApply<JudgmentSameSpaceOfFrustum>();
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				JudgmentSameSpaceOfFrustum::
					JudgmentSameSpaceOfFrustum(const JudgmentSameSpaceOfFrustum& _other) :
					OctreeRegistrableObject(_other.ObjectVolume),
					m_MLRCPublisherList(_other.m_MLRCPublisherList)
				{
					TypeComparable::TypeApply<JudgmentSameSpaceOfFrustum>();
				}

				//-----------------------------------------------------------
				// Add
				//-----------------------------------------------------------
				void JudgmentSameSpaceOfFrustum::
					Add(Rendering::Detail::Optimize::MLRCPublisher & _publisher)
				{
					m_MLRCPublisherList.push_back(&_publisher);
				}

				//-----------------------------------------------------------
				// Remove
				//-----------------------------------------------------------
				void JudgmentSameSpaceOfFrustum::
					Remove(Rendering::Detail::Optimize::MLRCPublisher & _publisher)
				{
					m_MLRCPublisherList.remove(&_publisher);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------