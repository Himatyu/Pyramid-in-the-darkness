/**
* @file		ICollider.h
* @brief	Collider�����ׂ��@�\
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<typeindex>
#include<utility>
#include"Nullable.h"
#include"../Common/Defines.h"
#include"../Defines.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{		
		class IVolume;
		namespace Detail
		{
			namespace Collider
			{
				using MatchingResult = 
					std::pair<Common::Sp<IVolume>, Common::Sp<IVolume>>;
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
			namespace Collider
			{
				/// <summary>
				/// Collider�����ׂ��@�\
				/// </summary>
				class ICollider
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					ICollider();
					virtual ~ICollider() = default;

					ICollider(const ICollider&) = default;
					ICollider(ICollider&&) = default;

					ICollider& operator=(const ICollider&) = default;
					ICollider& operator=(ICollider&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					/// <summary>
					/// Collider�̏�������^��v���m�F���A
					/// ���݂���̂ł���ΓK�������̌��ʂ�Ԃ�
					/// </summary>
					Utility::Nullable<MatchingResult> IsMatch(
						Common::Sp<IVolume>&, Common::Sp<IVolume>&);

					/// <summary>
					/// �Փ˔���
					/// </summary>
					virtual Utility::Nullable<ResultPair> IsCollision(IVolume*, IVolume*) = 0;
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
				protected:
					std::type_index		m_Type1;
					std::type_index		m_Type2;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------