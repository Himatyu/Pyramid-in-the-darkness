/**
* @file		UIPublishSystem.cpp
* @brief	UI�̃C�x���g���X�i�[/�p�u���b�V���[��o�^���A�C�x���g�̔��s���s��
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UIPublishSystem.h"
#include"Publisher\Abstract.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			UIPublishSystem::~UIPublishSystem()
			{
				for (auto& _ : m_Publishrs)
				{
					SAFE_DELETE(_.second);
				}
			}

			//-----------------------------------------------------------
			// Updata
			//-----------------------------------------------------------
			void UIPublishSystem::Updata()
			{
				for (auto& _ : m_Publishrs)
				{
					_.second->InspectAndPublish();
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------