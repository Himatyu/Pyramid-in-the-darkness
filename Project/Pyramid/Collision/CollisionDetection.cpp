/**
* @file		CollisionDetection.cpp
* @brief	è’ìÀîªíËÇÃé¿çsï˚ñ@ÇíËã`Ç∑ÇÈ
* @author	S.OIKAWA
* @date		2017.04.29
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"CollisionDetection.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		CollisionDetection::CollisionDetection()
		{
			m_Detection = Detection::Discontinuity;
			m_IsIgnoreRotateThenSVT = 0.0f;
			m_IsIgnoreScaleThenSVT = 0.0f;
		}

		//-----------------------------------------------------------
		// copy
		//-----------------------------------------------------------
		CollisionDetection::CollisionDetection(const CollisionDetection & _other)
		{
			m_Detection = _other.m_Detection;
			m_IsIgnoreRotateThenSVT  = _other.m_IsIgnoreRotateThenSVT;
			m_IsIgnoreScaleThenSVT   = _other.m_IsIgnoreScaleThenSVT;
		}

		//-----------------------------------------------------------
		// move
		//-----------------------------------------------------------
		CollisionDetection::CollisionDetection(CollisionDetection && _other)
		{
			m_Detection = _other.m_Detection;
			m_IsIgnoreRotateThenSVT  = _other.m_IsIgnoreRotateThenSVT;
			m_IsIgnoreScaleThenSVT   = _other.m_IsIgnoreScaleThenSVT;
		}

		//-----------------------------------------------------------
		// =&
		//-----------------------------------------------------------
		CollisionDetection & 
			CollisionDetection::operator=(const CollisionDetection & _other)
		{
			m_Detection = _other.m_Detection;
			m_IsIgnoreRotateThenSVT = _other.m_IsIgnoreRotateThenSVT;
			m_IsIgnoreScaleThenSVT = _other.m_IsIgnoreScaleThenSVT;

			return *this;
		}

		//-----------------------------------------------------------
		// =&&
		//-----------------------------------------------------------
		CollisionDetection & 
			CollisionDetection::operator=(CollisionDetection && _other)
		{
			m_Detection = _other.m_Detection;
			m_IsIgnoreRotateThenSVT = _other.m_IsIgnoreRotateThenSVT;
			m_IsIgnoreScaleThenSVT = _other.m_IsIgnoreScaleThenSVT;

			return *this;
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------