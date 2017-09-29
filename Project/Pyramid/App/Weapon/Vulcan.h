/**
* @file		Vulcan.h
* @brief	ƒoƒ‹ƒJƒ“–C
* @author	S,OIKAWA
* @date		2017.02.15
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"WeaponBase.h"
#include<array>
#include<vector>
#pragma endregion

#pragma region define
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
				class VulcanBullet;
			}
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace App
	{
		namespace Weapon
		{
			/// <summary>
			/// ƒoƒ‹ƒJƒ“–C
			/// </summary>
			class Vulcan :
				public WeaponBase
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Vulcan(Extension::Object::Actor *);
				~Vulcan() = default;

				Vulcan(const Vulcan&) = default;
				Vulcan(Vulcan&&) = default;

				Vulcan& operator=(const Vulcan&) = default;
				Vulcan& operator=(Vulcan&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				void Fire() override;

				void Init();
				
			private:
				Utility::Nullable<std::vector<int>>
					FindUnusedBullletIndexList(int Count);
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::array<Extension::Object::VulcanBullet*, 20> m_BulletPool;
				Common::Timer									m_FireDistance;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------