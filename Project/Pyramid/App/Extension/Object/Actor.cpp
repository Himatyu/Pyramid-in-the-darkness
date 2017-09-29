/**
* @file		Actor.cpp
* @brief	TransformÇéùÇ¡ÇΩGameObject
* @author	S.OIKAWA
* @date		2017.02.13
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Actor.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Object
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				Actor::Actor(Blueprint::Level* _pLevel) :
					GameObject::Object(_pLevel)
				{
					m_spTransform = AddComponent<Components::Transform>();
					m_spTransform->Init();
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------