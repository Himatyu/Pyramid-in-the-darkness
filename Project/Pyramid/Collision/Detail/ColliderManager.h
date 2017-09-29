/**
* @file		ColliderManager.h
* @brief	Collider�̓o�^�A�폜���s��
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
			/// Collider�̓o�^�A�폜�A�������s��
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
				/// Collider�ǉ�
				/// </summary>
				template<class AddCollider>
				void Add();

				/// <summary>
				/// Collider�폜
				/// </summary>
				template<class RemoveCollider>
				void Remove();

				/// <summary>
				/// Collider����������
				/// ���̍�Collidee�̏������Ή�������
				/// </summary>
				Utility::Nullable<FindResult> Find(
					Common::Sp<IVolume>, Common::Sp<IVolume>);

				/// <summary>
				/// Collider����������
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