/**
* @file		TestLevel.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TestLevel.h"
#include"../Includer.h"
#include"../Resource/DataObject/ScriptableObject.h"
#include"../Resource/API/DataObject.h"
#include"../UI/IUI.h"
#include"../Components/UIImage.h"
#include"../Components/UIButton.h"
#include"../Common/InputDevice/Mouse.h"
#pragma endregion


//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	using namespace Rendering;
	using namespace Resources;
	using namespace GameObject;
	using namespace Components;
	using namespace DataObject;
	using namespace Common::Diagram;

	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	Transform*	pTrans;
	UIImage*	pParent;
	TestLevel::TestLevel()
	{
		//auto ins = ResourceManager::Instantiate()
		//	.OnLoad< Resources::DataObject::ScriptableObject<A>>(
		//		"Assets/DataObject/ScriptableObject.dat");

		MT::ThreadSystem::Instantiate().isActive = false;

		auto& tex = ResourceManager::Instantiate()
			.OnLoad< Resources::Texture::DirectXTextureFile>(
				"Assets/Texture/effect2.png");
		auto& ui = Instantiate<Object>(this);
		ui.Tag = "ui";

		auto& image = ui.AddComponent<UIButton>();
		image->Transform.Position.X = 400;
		image->Transform.Position.Y = 400;
		image->Transform.RotateZ = 0;
		image->Transform.Size.X = 200;
		image->Transform.Size.Y = 100;		

		image->Texture.spResourceFile = (tex);

		//auto& image2 = ui.AddComponent<UIButton>();
		//image2->Transform.Position.X = 400;
		//image2->Transform.Position.Y = 400;
		//image2->Transform.Position.Z = 1;
		//image2->Transform.RotateZ = 0;
		//image2->Transform.Size.X = 200;
		//image2->Transform.Size.Y = 100;

		//pParent = &*image;
		//image->Transform.AddChild(*image2);
		//image->isActive = false;

		auto& camera = Instantiate<App::Extension::Object::Actor>(this);
		camera.Init();
		camera.Tag = "camera";

		auto& cameraCom = camera.AddComponent<Camera>();
		cameraCom->Init();
		
		auto& light = Instantiate<Object>(this);
		light.AddComponent<Transform>()->Init();
		light.AddComponent<DirectionalLight>()->Diffuse = Color(1, 1, 1, 1);
		light.Tag = "light";

		m_pPlayer = &Instantiate<App::Player>(this);
		m_pPlayer->Initialize(&camera);

		auto& col = Instantiate<Object>(this);
		col.Tag = "TestObject";
		auto& colTrans = col.AddComponent<Transform>();
		colTrans->Position = Utility::Vector3(7, 0, 0);
		colTrans->Scale = Utility::Vector3(1,1,1);
		auto& colCom = 
			col.AddComponent<Collidee<Sphere,AABB>>();
		colCom->Init(colTrans);
		auto volume = colCom->AccessOfCastedVolumeForIndex<0>();
		volume->Offset.Position.Y = 0.0;
		//sphere->Volume.BV.R = 1.0f;
		//sphere->Volume.BV = Common::Diagram::AABB({ -1,-1,-1 }, { 1,1,1 });
		
		//auto sphere = colCom->AccessOfCastedVolumeForIndex<0>();
		volume->BV.R = 1.0;
		colCom->Precision.Value = Collision::Detection::SVT;
		//volume->BV.Half = Utility::Vector3(1.0f,1.0f,1.0f);
		//volume->BV.LocalAxisX = Utility::Vector3(1, 0,0);
		//volume->BV.LocalAxisY = Utility::Vector3(0, 1, 0);
		//volume->BV.LocalAxisZ = Utility::Vector3(0, 0, 1);
		pTrans = &*colTrans;
	}
	//-----------------------------------------------------------
	// Updata
	//-----------------------------------------------------------
	void TestLevel::Updata()
	{	
		pTrans->Position.X -= Common::TimerServer::DeltaTime;
		pTrans->Rotation.Y += Common::TimerServer::DeltaTime;
		m_ObjectManager.CallUpdatas();

		auto ui = this->FindObjectsWithTag("ui").Value[0];
		ui->GetComponent<UIButton>()
			.Value->Transform.RotateZ += Common::TimerServer::DeltaTime*10;

		
		//if (Common::InputDevice::Key::Instantiate().IsKeyPush(DIK_SPACE))
		//{
		//	pParent->isActive = false;
		//}
		//else
		//{
		//	pParent->isActive = true;
		//}


	}
	//-----------------------------------------------------------
	// PreDraw
	//-----------------------------------------------------------
	void TestLevel::Draw()
	{
		m_ObjectManager.CallPreDraw();
	}

}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
