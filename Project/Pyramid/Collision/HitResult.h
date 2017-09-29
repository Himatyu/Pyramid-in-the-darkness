/**
* @file		HitResult.h
* @brief	è’ìÀîªíËåãâ 
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Common/Defines.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		class Transform;
	}
	namespace GameObject
	{
		class Object;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		/// <summary>
		/// è’ìÀîªíËåãâ 
		/// </summary>
		class HitResult
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			HitResult();
			HitResult(Common::Sp<Components::Transform>, GameObject::Object*);
			~HitResult() = default;

			HitResult(const HitResult&) = default;
			HitResult(HitResult&&) = default;

			HitResult& operator=(const HitResult&) = default;
			HitResult& operator=(HitResult&&) = default;
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
			PROPERTY(m_pObject, pObject, GameObject::Object*);
			PROPERTY(m_Transfom, Transfom, Common::Sp<Components::Transform>);
#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
		private:
			Common::Sp<Components::Transform>	m_Transfom;
			GameObject::Object*					m_pObject;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------