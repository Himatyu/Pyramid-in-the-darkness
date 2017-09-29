/**
* @file		ICollider.h
* @brief	Colliderが持つべき機能
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<typeindex>
#include<utility>
#include"Nullable.h"
#include"../Common/Defines.h"
#include"../Defines.h"
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
				using MatchingResult = 
					std::pair<Common::Sp<IVolume>, Common::Sp<IVolume>>;
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
			namespace Collider
			{
				/// <summary>
				/// Colliderが持つべき機能
				/// </summary>
				class ICollider
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					ICollider();
					virtual ~ICollider() = default;

					ICollider(const ICollider&) = default;
					ICollider(ICollider&&) = default;

					ICollider& operator=(const ICollider&) = default;
					ICollider& operator=(ICollider&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					/// <summary>
					/// Colliderの所持する型一致を確認し、
					/// 存在するのであれば適した順の結果を返す
					/// </summary>
					Utility::Nullable<MatchingResult> IsMatch(
						Common::Sp<IVolume>&, Common::Sp<IVolume>&);

					/// <summary>
					/// 衝突判定
					/// </summary>
					virtual Utility::Nullable<ResultPair> IsCollision(IVolume*, IVolume*) = 0;
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				protected:
					std::type_index		m_Type1;
					std::type_index		m_Type2;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------