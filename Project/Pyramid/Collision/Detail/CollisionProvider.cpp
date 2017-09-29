/**
* @file		CollisionProvider.cpp
* @brief	è’ìÀî≠ê∂ÇíÒãüÇ∑ÇÈ
* @author	S.OIKAWA
* @date		2017.03.04
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "CollisionProvider.h"
#include "HitEventPublisher.h"
#include "Collider/ICollider.h"
#include "../HitResult.h"
#include "Defines.h"
#include "CollisionInformation.h"
#include "ColliderManager.h"
#include "../CollisionDetection.h"
#include "ICollidee.h"
#include "../IVolume.h"
#include "../CollisionDetection.h"
#include "Tester/ITester.h"
#include "Tester/TesterOfDiscreet.h"
#include "Tester/TesterOfSVT.h"
#include "Estd.h"
#include <typeindex>
#include <algorithm>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace std;
using namespace Pyramid::Collision::Detail;
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			CollisionProvider::CollisionProvider()
			{
				m_TesterArray[static_cast<int>(Detection::Discontinuity)] =
					new Tester::TesterOfDiscreet(m_ColliderManager);
				m_TesterArray[static_cast<int>(Detection::SVT)] = 
					new Tester::TesterOfSVT(m_ColliderManager);
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			CollisionProvider::~CollisionProvider()
			{
				for (auto _ : m_TesterArray)
				{
					SAFE_DELETE(_);
				}
			}

			//-----------------------------------------------------------
			// Collision
			//-----------------------------------------------------------
			Utility::Nullable<EventPair>
				CollisionProvider::Collision(ICollidee * _lhv, ICollidee * _rhv)
			{
				_ASSERT_EXPR(
					_lhv->Precision.Value != Collision::Detection::Count &&
					_rhv->Precision.Value != Collision::Detection::Count,
					_T(L"Collision::Detection::CountÇÃégóp"));
				auto index = max(
					static_cast<int>(_lhv->Precision.Value),
					static_cast<int>(_rhv->Precision.Value));

				return Utility::Nullable<EventPair>(m_TesterArray[index]->Run(_lhv, _rhv));
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------