/**
* @file		Context.cpp
* @brief	最適化時に渡される情報
* @author	S.OIKAWA
* @date		2017.03.28
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Context.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				Context::Context(
					const Continuity _continuity, 
					Utility::Vector3 & _refCamera):
					m_ContinuityAttribute(_continuity),
					m_RefCameraPos(_refCamera)
				{
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------