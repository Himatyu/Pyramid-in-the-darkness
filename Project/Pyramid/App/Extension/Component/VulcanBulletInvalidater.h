/**
* @file		VulcanBulletInvalidater.h
* @brief	ƒoƒ‹ƒJƒ“–C‚ð–³Œø‚É‚·‚é
* @author	S.OIKAWA
* @date		2017.02.15
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Includer.h"
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
			namespace Component
			{
				/// <summary>
				/// ƒoƒ‹ƒJƒ“–C‚ð–³Œø‚É‚·‚é
				/// </summary>
				class VulcanBulletInvalidater :
					public Components::Component
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					VulcanBulletInvalidater() ;
					~VulcanBulletInvalidater() = default;

					VulcanBulletInvalidater(const VulcanBulletInvalidater&) = default;
					VulcanBulletInvalidater(VulcanBulletInvalidater&&) = default;

					VulcanBulletInvalidater& operator=(const VulcanBulletInvalidater&) = default;
					VulcanBulletInvalidater& operator=(VulcanBulletInvalidater&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					void Init() override;
					void Updata() override;

					void OnInvalidate();
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
					PROPERTY(m_IsFire, IsFire, bool);
#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					Common::Timer										m_DisableTimer;
					bool												m_IsFire = false;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------