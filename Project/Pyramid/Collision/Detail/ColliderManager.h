/**
* @file		ColliderManager.h
* @brief	Collider‚Ì“o˜^Aíœ‚ğs‚¤
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include<utility>
#include<typeindex>
#include"Nullable.h"
#include"FindResult.h"
#include"Collider\ICollider.h"
#include"Estd.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			class ICollidee;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			/// <summary>
			/// Collider‚Ì“o˜^AíœAŒŸõ‚ğs‚¤
			/// </summary>
			class ColliderManager
			{
				using RegisterInfo =
					std::pair<Collider::ICollider*, std::type_index>;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ColliderManager() = default;
				~ColliderManager();

				ColliderManager(const ColliderManager&) = default;
				ColliderManager(ColliderManager&&) = default;

				ColliderManager& operator=(const ColliderManager&) = default;
				ColliderManager& operator=(ColliderManager&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// Collider’Ç‰Á
				/// </summary>
				template<class AddCollider>
				void Add();

				/// <summary>
				/// Collideríœ
				/// </summary>
				template<class RemoveCollider>
				void Remove();

				/// <summary>
				/// Collider‚ğŒŸõ‚·‚é
				/// ‚»‚ÌÛCollidee‚Ì‡˜‚à‘Î‰‚³‚¹‚é
				/// </summary>
				Utility::Nullable<FindResult> Find(
					Common::Sp<IVolume>, Common::Sp<IVolume>);

				/// <summary>
				/// Collider‚ğŒŸõ‚·‚é
				/// </summary>
				template<class FindCollider>
				Utility::Nullable<Collider::ICollider*> Find();
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			private:
				std::list<RegisterInfo*>	m_ColliderList;
#pragma endregion
			};
#include"ColliderManager.inl"
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------