/**
* @file		CollisionInformation.h
* @brief	è’ìÀíÜÇÃèÓïÒ
* @author	S.OIKAWA
* @date		2017.04.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../HitResult.h"
#include"ColliderManager.h"
#include"FindResult.h"
#include"Manager.h"
#include<list>
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
		namespace Detail
		{
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
			/// è’ìÀíÜÇÃèÓïÒ
			/// </summary>
			class CollisionInformation
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				CollisionInformation(bool, HitResult);
				CollisionInformation(bool, HitResult, std::list<FindResult::ForLog>);
				~CollisionInformation() = default;

				CollisionInformation(const CollisionInformation&) = default;
				CollisionInformation(CollisionInformation&&) = default;

				CollisionInformation& operator=(const CollisionInformation&) = default;
				CollisionInformation& operator=(CollisionInformation&&) = default;
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
				PROPERTY_REF(m_IsHitInFream, IsHitInFream, bool);
				PROPERTY_REF(m_CeshOfResult, Result, HitResult);
				PROPERTY_REF(m_LogListOfFindResult,
					FindedLogList, std::list<FindResult::ForLog>);
#pragma endregion

#pragma region value
			private:
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				bool									m_IsHitInFream;
				HitResult								m_CeshOfResult;
				std::list<FindResult::ForLog>			m_LogListOfFindResult;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------