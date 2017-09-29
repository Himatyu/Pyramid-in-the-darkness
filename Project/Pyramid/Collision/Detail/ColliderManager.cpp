/**
* @file		ColliderManager.cpp
* @brief	Collider‚Ì“o˜^Aíœ‚ðs‚¤
* @author	S.OIKAWA
* @date		2017.03.04
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ColliderManager.h"
#include"../Collision/Detail/Collider/ICollider.h"
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
			// dtor
			//-----------------------------------------------------------
			ColliderManager::~ColliderManager()
			{
				for (auto& _ : m_ColliderList)
				{
					SAFE_DELETE(_->first);
					SAFE_DELETE(_);
				}
			}

			//-----------------------------------------------------------
			// Find
			//-----------------------------------------------------------
			Utility::Nullable<FindResult>
				ColliderManager::Find(Common::Sp<IVolume> _lhv, Common::Sp<IVolume> _rhv)
			{
				for (auto& _ : m_ColliderList)
				{
					if (auto result = _->first->IsMatch(_lhv, _rhv))
					{
						return 
							Utility::Nullable<FindResult>(
									{ _->first,
									result.Value.first,
									result.Value.second });
					}
				}
				return Utility::Nullable<FindResult>();
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------