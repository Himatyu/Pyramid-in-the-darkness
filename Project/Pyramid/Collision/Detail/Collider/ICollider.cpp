/**
* @file		ICollider.cpp
* @brief	ColliderÇ™éùÇ¬Ç◊Ç´ã@î\
* @author	S.OIKAWA
* @date		2017.03.04
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICollider.h"
#include"../../IVolume.h"
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
			namespace Collider
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				ICollider::ICollider():
					m_Type1(typeid(ICollider)),
					m_Type2(typeid(ICollider))
				{
				}

				//-----------------------------------------------------------
				// IsMatch
				//-----------------------------------------------------------
				Utility::Nullable<MatchingResult>
					ICollider::IsMatch(
						Common::Sp<IVolume>& _spLhv,
						Common::Sp<IVolume>& _spRhv)
				{
					if (_spLhv->IsSame(m_Type1,0) &&
						_spRhv->IsSame(m_Type2,0))
					{
						return Utility::Nullable<MatchingResult>(
							MatchingResult(_spLhv, _spRhv));
					}

					if (_spRhv->IsSame(m_Type1,0) &&
						_spLhv->IsSame(m_Type2,0))
					{
						return Utility::Nullable<MatchingResult>(
							MatchingResult(_spRhv, _spLhv));
					}

					return Utility::Nullable<MatchingResult>();
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------