/**
* @file		ICollidee.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICollidee.h"
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
			// UpdateTransform
			//-----------------------------------------------------------
			void ICollidee::UpdateTransform(
				Common::Sp<Components::Transform>& _spTrans)
			{
				m_CacheOfPrevFream = m_CacheOfThisFream;
				m_CacheOfThisFream = _spTrans;
				m_spTransform = _spTrans;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------