/**
* @file		Actor.h
* @brief	TransformÇéùÇ¡ÇΩGameObject
* @author	S.OIKAWA
* @date		2017.02.13
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Includer.h"
#include<memory>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Object
			{
				/// <summary>
				/// TransformÇéùÇ¡ÇΩGameObject
				/// </summary>
				class Actor :
					public GameObject::Object
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Actor(Blueprint::Level*);
					~Actor() = default;

					Actor(const Actor&) = default;
					Actor(Actor&&) = default;

					Actor& operator=(const Actor&) = default;
					Actor& operator=(Actor&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
					PROPERTY_REF(m_spTransform, spTransform,
						std::shared_ptr<Components::Transform>);
#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					std::shared_ptr<Components::Transform>		m_spTransform;
#pragma endregion
				};
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------