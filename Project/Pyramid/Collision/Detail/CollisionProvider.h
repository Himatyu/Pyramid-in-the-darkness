/**
* @file		CollisionProvider.h
* @brief	�Փ˔�����񋟂���
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"
#include"ColliderManager.h"
#include"FindResult.h"
#include"Nullable.h"
#include"Defines.h"
#include"CollisionProvider.h"
#include<vector>
#include<array>
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
			namespace Collider
			{
				class ICollider;
			}
			namespace Tester
			{
				class ITester;
			}

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
			/// �Փ˔�����񋟂���
			/// Enter����������Cllider�͂���Collider�̉ߒ���Log���Ĉȍ~�̔���Ɏg�p
			/// Enter�Ɏ���܂ł̉ߒ��̃L���b�V���͔j���^�C�~���O���s���Ȃ��ߍs��Ȃ�
			/// </summary>
			class CollisionProvider final
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				CollisionProvider() ;
				~CollisionProvider();

				CollisionProvider(const CollisionProvider&) = default;
				CollisionProvider(CollisionProvider&&) = default;

				CollisionProvider& operator=(const CollisionProvider&) = default;
				CollisionProvider& operator=(CollisionProvider&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ��Έ�̏Փ�
				/// </summary>
				Utility::Nullable<EventPair> Collision(ICollidee*, ICollidee*);

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_ColliderManager, Manager, ColliderManager);
#pragma endregion

#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				ColliderManager					m_ColliderManager;
				std::array<
					Tester::ITester*,
					static_cast<size_t>(Detection::Count)> m_TesterArray;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------