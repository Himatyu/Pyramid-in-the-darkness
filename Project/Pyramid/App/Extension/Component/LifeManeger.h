/**
* @file		LifeManeger.h
* @brief	�v���C���[�̃��C�t���Ǘ�����
* @author	S.OIKAWA
* @date		2017.04.05
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"PlayerModule.h"
#include"../Collision/IHitEvent.h"
#include"../Object/Actor.h"

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
				/// �v���C���[�̃��C�t���Ǘ�����
				///	�ŏI�I�ɂ͓�����N���X�ɃC�x���g�������[���ă_���[�W�𔽉f������
				/// </summary>
				class LifeManeger :
					public PlayerModule,
					public Collision::IHitEvent
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					LifeManeger();
					LifeManeger(Object::Actor*);
					~LifeManeger() = default;

					LifeManeger(const LifeManeger&) = default;
					LifeManeger(LifeManeger&&) = default;

					LifeManeger& operator=(const LifeManeger&) = default;
					LifeManeger& operator=(LifeManeger&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					void OnCollisionEnter(Collision::HitResult) override;
					void OnCollisionStay(Collision::HitResult)  override;
					void OnCollisionExit(Collision::HitResult)  override;

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

#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------