/**
* @file		JudgmentSameSpaceOfCollidee.cpp
* @brief	�Փ˔���p�̔����ؓo�^�I�u�W�F�N�g
* @author	S.OIKAWA
* @date		2017.03.05
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"JudgmentSameSpaceOfCollidee.h"
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
			JudgmentSameSpaceOfCollidee::
				JudgmentSameSpaceOfCollidee(Common::WorldVolume & _volume) :
				OctreeRegistrableObject(_volume)
			{
				TypeComparable::TypeApply<JudgmentSameSpaceOfCollidee>();
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------