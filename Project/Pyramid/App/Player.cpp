/**
* @file		Player.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Player.h"
#include"Constant.h"
#include"../App/Extension/Component/MovementControl.h"
#include"../App/Extension/Component/PlayerTrackingCamara.h"
#include"../App/Extension/Component/FirearmsControler.h"
#include"../App/Extension/Component/BackJetEffector.h"
#include"../App/Extension/Component/LifeManeger.h"
#include"../Includer.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Components;
using namespace Pyramid::Resources;
using namespace Pyramid::App::Extension::Component;
using namespace Pyramid::App::Extension::Object;
using namespace Pyramid::Common::Diagram;

namespace Pyramid
{
	namespace App
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Player::Player(Blueprint::Level * _pLevel):
			Actor(_pLevel)
		{			
			m_Tag = "Player";
		}

		//-----------------------------------------------------------
		// Initialize
		//-----------------------------------------------------------
		void Player::Initialize(Extension::Object::Actor* _pCameraActor)
		{
			auto& mesh =
				AddComponent<Mesh>(Constant::PathOfPlayerModel);
			mesh->Init(spTransform);
			auto& material = mesh->Materials;

			for (auto& _ : material)
			{
				_->Emissive.Value = {0.1f,0.1f,0.1f,0.1f };
				_->Ambient.Value = {0,0,0,0};
				_->Diffuse.Value = {1,1,1,1};
				_->Transparency = 1.0f;
			}
			//AddComponent<MovementControler>(this)->Init();
			AddComponent<PlayerTrackingCamara>(this)->Init(_pCameraActor);
			//AddComponent<FirearmsControler>(this)->Init();
			//AddComponent<BackJetEffector>(this)->Init();
			auto& colEvent = AddComponent<LifeManeger>(this);

			auto& col = 
				AddComponent<Components::Collidee<Sphere,OBB>>();
			col->Init(spTransform);
			col->Add(&*colEvent);

			auto volume = col->AccessOfCastedVolumeForIndex<1>();
			volume->BV.Half = Utility::Vector3::once*0.5;//Utility::Vector3(0.5f, 0.5f, 0.5f);
			volume->BV.LocalAxisX = Utility::Vector3(1, 0, 0);
			volume->BV.LocalAxisY = Utility::Vector3(0, 1, 0);
			volume->BV.LocalAxisZ = Utility::Vector3(0, 0, 1);

			//spTransform->Scale = Utility::Vector3::once*2.0f;

			//auto aabb = col->AccessOfCastedVolumeForIndex<0>();
			//aabb->BV = AABB({-0.5,-0.5,-0.5 }, {0.5,0.5,0.5 });

			auto sphere = col->AccessOfCastedVolumeForIndex<0>();
			sphere->BV.R = 1.5;


		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------