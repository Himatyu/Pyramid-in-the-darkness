/**
* @file		JudgmentSameSpaceOfFrustum.h
* @brief	視錐台と同空間か判定する
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
				/// 視錐台と同空間か判定する
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
					/// リスト追加
					/// </summary>
					void Add(MLRCPublisher&);

					/// <summary>
					/// リスト削除
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