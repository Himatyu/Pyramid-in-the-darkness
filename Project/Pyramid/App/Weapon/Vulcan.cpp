/**
* @file		Vulcan.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Vulcan.h"
#include"../Includer.h"
#include"../App/Extension/Object/Actor.h"
#include"../App/Extension/Object/VulcanBullet.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace App
	{
		namespace Weapon
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Vulcan::Vulcan(Extension::Object::Actor * _pPlayer):
				WeaponBase(_pPlayer),
				m_FireDistance(0.2f,true)
			{
				//HACK new 20‰ñ‚Í‹–—e‚µ‚©‚Ë‚é
				auto pLevel = m_pPlayer->pOwner;
				for (auto& _ : m_BulletPool)
				{
					_ = &pLevel->Instantiate<Extension::Object::VulcanBullet>(pLevel);
					_->Init();
				}
			}

			//-----------------------------------------------------------
			// Fire
			//-----------------------------------------------------------
			void Vulcan::Fire()
			{
 				if (m_FireDistance.IsElapsed)
				{
					auto index = FindUnusedBullletIndexList(2);
					if (!index)
					{
						return;
					}

					auto& trans = m_pPlayer->spTransform;
					auto center = trans->Position + trans->Forward;
					auto popRight = center + trans->Right*0.5f;
					auto popLeft = center - trans->Right*0.5f;
					
					m_BulletPool[index.Value[0]]->OnFire(
						popRight, m_pPlayer->spTransform);

					m_BulletPool[index.Value[1]]->OnFire(
						popLeft , m_pPlayer->spTransform);
				}
			}

			//-----------------------------------------------------------
			// Init
			//-----------------------------------------------------------
			void Vulcan::Init()
			{
				m_FireDistance.IsActive = true;
			}

			//-----------------------------------------------------------
			// FindUnusedBullletIndex
			//-----------------------------------------------------------
			Utility::Nullable<std::vector<int>>
				Vulcan::FindUnusedBullletIndexList(int _count)
			{
				std::vector<int> List;
				auto size = m_BulletPool.size();

				for (int i = 0; i < size;i++)
				{
					if (!m_BulletPool[i]->IsFire)
					{
						List.push_back(i);
					}
				}

				if (List.size() < _count)
				{
					return Utility::Nullable<std::vector<int>>();
				}

				return Utility::Nullable<std::vector<int>>(std::move(List));
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------