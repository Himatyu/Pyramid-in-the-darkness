/**
* @file		FindResult.h
* @brief	弱参照に変換可能な検索結果
* @author	S.OIKAWA
* @date		2017.04.21
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Common/Defines.h"
#include<utility>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		class IVolume;
		namespace Detail
		{
			namespace Collider
			{
				class ICollider;
			}
		}
	}
}
#pragma endregion


namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			/// <summary>
			/// ColliderManagerの検索結果
			/// </summary>
			class FindResult
			{
			public:
				using ForLog =
					std::tuple<Collider::ICollider*,
					Common::Wp<IVolume>,
					Common::Wp<IVolume>>;
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				FindResult() = default;
				FindResult(Collider::ICollider*, 
					Common::Sp<IVolume>&, 
					Common::Sp<IVolume>&);
				~FindResult() = default;

				FindResult(const FindResult&);
				FindResult(FindResult&&) = default;

				FindResult& operator=(const FindResult&);
				FindResult& operator=(FindResult&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 弱参照にキャストする
				/// </summary>
				ForLog ConvertItForRegistration();

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY_R_ONLY(m_pCollider, pCollider, Collider::ICollider*);
				PROPERTY_REF_R_ONLY(m_spIVolumeL, spVolumeL, Common::Sp<IVolume>);
				PROPERTY_REF_R_ONLY(m_spIVolumeR, spVolumeR, Common::Sp<IVolume>);
#pragma endregion

#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				Common::Sp<IVolume>		m_spIVolumeL;
				Common::Sp<IVolume>		m_spIVolumeR;
				Collider::ICollider*	m_pCollider;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------