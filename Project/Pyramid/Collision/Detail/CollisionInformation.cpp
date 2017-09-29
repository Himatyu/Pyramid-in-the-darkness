/**
* @file		CollisionInformation.cpp
* @brief	è’ìÀíÜÇÃèÓïÒ
* @author	S.OIKAWA
* @date		2017.04.19
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "CollisionInformation.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			CollisionInformation::CollisionInformation(
				bool _isHit,
				HitResult _hitResult):
				m_IsHitInFream(_isHit),
				m_CeshOfResult(_hitResult)
			{
			}

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			CollisionInformation::CollisionInformation(
				bool _isHit, 
				HitResult _hitResult,
				std::list<FindResult::ForLog> _Log):
				m_IsHitInFream(_isHit),
				m_CeshOfResult(_hitResult),
				m_LogListOfFindResult(_Log)
			{
			}

		}
	}
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
