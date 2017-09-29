/**
* @file		JudgmentSameSpaceOfCollidee.h
* @brief	衝突判定用の八分木登録オブジェクト
* @author	S.OIKAWA
* @date		2017.03.05
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Common/SpaceDivide/OctreeRegistrableObject.h"
#include"../Collision/Detail/ICollidee.h"
#include"Manager.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			/// <summary>
			/// 衝突判定用の八分木登録オブジェクト
			/// </summary>
			class JudgmentSameSpaceOfCollidee :
				public Common::SpaceDivide::OctreeRegistrableObject,
				public Utility::Manager<std::list<ICollidee*>>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				JudgmentSameSpaceOfCollidee(Common::WorldVolume&);
				~JudgmentSameSpaceOfCollidee() = default;

				JudgmentSameSpaceOfCollidee(const JudgmentSameSpaceOfCollidee&) = default;
				JudgmentSameSpaceOfCollidee(JudgmentSameSpaceOfCollidee&&) = default;

				JudgmentSameSpaceOfCollidee& operator=(const JudgmentSameSpaceOfCollidee&) = default;
				JudgmentSameSpaceOfCollidee& operator=(JudgmentSameSpaceOfCollidee&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY_REF_R_ONLY(m_Container, CollideeList,decltype(m_Container));
#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------