/**
* @file		JudgmentSameSpaceOfCollidee.cpp
* @brief	衝突判定用の八分木登録オブジェクト
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