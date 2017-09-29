/**
* @file		LifeManeger.cpp
* @brief	プレイヤーのライフを管理する
* @author	S.OIKAWA
* @date		2017.04.05
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"LifeManeger.h"
#include"../Includer.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Component
			{

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				LifeManeger::LifeManeger():
					PlayerModule(nullptr)
				{
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				LifeManeger::LifeManeger(Object::Actor * _pActor):
					PlayerModule(_pActor)
				{
				}

				//-----------------------------------------------------------
				// OnCollisionEnter
				//-----------------------------------------------------------
				void LifeManeger::OnCollisionEnter(Collision::HitResult _hit)
				{
					___D_LOG("OnCollisionEnter : "+ _hit.pObject->Tag);
					auto& mesh = 
						m_pOwner->GetComponentFromTag<Components::Mesh>("DebugCollisionModel1");
					mesh->Materials[0]->Emissive.Value = { 1,0,0,1 };

				}
				
				//-----------------------------------------------------------
				// OnCollisionStay
				//-----------------------------------------------------------
				void LifeManeger::OnCollisionStay(Collision::HitResult _hit)
				{
					___D_LOG("OnCollisionStay : " + _hit.pObject->Tag);

					auto& mesh = 
						m_pOwner->GetComponentFromTag<Components::Mesh>("DebugCollisionModel1");
					mesh->Materials[0]->Emissive.Value = {0,1,0,1};
				}
				
				//-----------------------------------------------------------
				// OnCollisionExit
				//-----------------------------------------------------------
				void LifeManeger::OnCollisionExit(Collision::HitResult _hit)
				{
					___D_LOG("OnCollisionExit : " + _hit.pObject->Tag);

					auto& mesh = 
						m_pOwner->GetComponentFromTag<Components::Mesh>("DebugCollisionModel1");
					mesh->Materials[0]->Emissive.Value = { 0,0,1,1 };
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------