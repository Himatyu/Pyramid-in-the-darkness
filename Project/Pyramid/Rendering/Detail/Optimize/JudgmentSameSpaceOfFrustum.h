/**
* @file		JudgmentSameSpaceOfFrustum.h
* @brief	������Ɠ���Ԃ����肷��
* @author	S.OIKAWA
* @date		2017.01.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Common/SpaceDivide/OctreeRegistrableObject.h"
#include"ICastable.h"
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
				class MLRCPublisher;
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
				/// ������Ɠ���Ԃ����肷��
				/// </summary>
				class JudgmentSameSpaceOfFrustum :
					public Common::SpaceDivide::OctreeRegistrableObject
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					JudgmentSameSpaceOfFrustum(Common::WorldVolume&);
					~JudgmentSameSpaceOfFrustum() = default;

					JudgmentSameSpaceOfFrustum(const JudgmentSameSpaceOfFrustum&);
					JudgmentSameSpaceOfFrustum(JudgmentSameSpaceOfFrustum&&) = default;

					JudgmentSameSpaceOfFrustum& operator=(const JudgmentSameSpaceOfFrustum&) = default;
					JudgmentSameSpaceOfFrustum& operator=(JudgmentSameSpaceOfFrustum&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// ���X�g�ǉ�
					/// </summary>
					void Add(MLRCPublisher&);

					/// <summary>
					/// ���X�g�폜
					/// </summary>
					void Remove(MLRCPublisher&);

#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_REF_R_ONLY(m_MLRCPublisherList,
						MLRCPublisherList, std::list<MLRCPublisher*>);

#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					std::list<MLRCPublisher*>		m_MLRCPublisherList;

#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------