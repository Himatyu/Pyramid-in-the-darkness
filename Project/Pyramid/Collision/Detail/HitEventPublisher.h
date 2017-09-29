/**
* @file		HitEventPublisher.h
* @brief	�Փˎ��̃C�x���g�𔭍s����
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"FindResult.h"
#include"../HitResult.h"
#include"singleton.h"
#include"Defines.h"
#include"DelayEvent.h"
#include<vector>
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
			/// �Փˎ��̃C�x���g�𔭍s����
			/// </summary>
			class HitEventPublisher : 
				public Utility::Singleton<HitEventPublisher>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				HitEventPublisher() = default;
				~HitEventPublisher() = default;

				HitEventPublisher(const HitEventPublisher&) = default;
				HitEventPublisher(HitEventPublisher&&) = default;

				HitEventPublisher& operator=(const HitEventPublisher&) = default;
				HitEventPublisher& operator=(HitEventPublisher&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �Փ˃p�����[�^�̏�����
				/// </summary>
				void PreparationOfPublish(ICollidee*);
				
				/// <summary>
				/// Enter�𔭍s����
				/// ������CollisionInformation�𐶐����邽�߂�Log��v��
				/// </summary>
				EventPair PublishEventEnter(
					ICollidee*, HitResult&,
					ICollidee*, HitResult&,
					std::list<FindResult::ForLog>&);

				/// <summary>
				/// Enter�𔭍s����
				/// SVT�p
				/// </summary>
				EventPair PublishEventEnter(
					ICollidee*, HitResult&,
					ICollidee*, HitResult&);

				/// <summary>
				/// Stay�𔭍s����
				/// �}�`��Log�����S�Ȃ���Log�͂���Ȃ�
				/// </summary>
				EventPair PublishEventStay(
					ICollidee*, HitResult&,
					ICollidee*, HitResult&);
				
				/// <summary>
				/// �ՓˏI���C�x���g�𔭍s
				/// </summary>
				std::vector<DelayEvent> PublishEventOfExit(ICollidee*);

			private:
				DelayEvent PublishOfStay(ICollidee*, ICollidee*, HitResult);
				DelayEvent PublishOfEnter(ICollidee*, ICollidee*,
					HitResult, std::list<FindResult::ForLog>&);
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
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------