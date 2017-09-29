/**
* @file		Application.cpp
* @brief	アプリケーション実装
* @author	S.OIKAWA
* @date		2016/07/26
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Application.h"
#include"GameWindow.h"
#include"../Rendering/Graphics.h"
#include"../Rendering/RenderProvider.h"
#include"../Rendering/HLRCommand/Default/StaticDefaultCommand.h"
#include"LevelStream.h"
#include"Level.h"
#include"../Blueprint/Constant.h"
#include"../MT/Order/OrderedJobReserver.h"
#include"../MT/Order/TaskContainer.h"
#include"../MT/Order/TaskOrder.h"
#include"../MT/Order/TaskLine.h"
#include"../MT/Jobs/ThreadJob.h"
#include"../MT/ThreadSystem.h"
#include"../MT/Order/OrderedJobReserver.h"
#include"../MT/Order/OrderedJobExcuter.h"
#include"../MT/Worker/MLRCPublisher.h"
#include"../MT/Worker/JobExecuter.h"
#include"../Common/Timer.h"
#include"../Common/TimerServer.h"
#include"../Common/Constant.h"
#include"../Common/WorldSpaceDivider.h"
#include"../Blueprint/Constant.h"
#include"../Common/InputDevice/DeviceManager.h"
#include"../Common/InputDevice/Key.h"
#include"../Common/InputDevice/Mouse.h"
#include"../Collision/Detail/CollisionProvider.h"
#include"../Collision/Detail/Collider/AABBAndAABB.h"
#include"../Collision/Detail/Collider/AABBAndOBB.h"
#include"../Collision/Detail/Collider/OBBAndOBB.h"
#include"../Collision/Detail/Collider/OBBAndSphere.h"
#include"../Collision/Detail/Collider/SphereAndAABB.h"
#include"../Collision/Detail/Collider/SphereAndSphere.h"
#include"FPSCounter.h"
#include"../Collision/Detail/CollisionSystem.h"

#include"../UI/Event/UIPublishSystem.h"
#include"../UI/Event/Publisher/UIChangeState.h"
#include"../UI/Event/Publisher/UICursor.h"

#include<string>
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

using namespace std;
using namespace Pyramid::GameObject;
using namespace Pyramid::MT;
using namespace Pyramid::Rendering;
using namespace Pyramid;
using namespace Pyramid::Collision::Detail::Collider;

namespace
{
	inline void Updata(
		Order::OrderedJobExcuter& _exe,
		std::shared_ptr<Pyramid::Blueprint::LevelStream>&	_spStream)
	{
		_exe.Run(Common::Constant::MTUpdataGrupName);
		_spStream->UpdataStream();

		auto& ins = Collision::Detail::CollisionSystem::Instantiate();
		ins.ExecuteCollision();
		ins.ExecuteReply();

		auto& uiSystem = UI::Event::UIPublishSystem::Instantiate();
		uiSystem.Updata();

		//TODO 依存関係調べてMTJob化
		Common::WorldSpaceDivider::Instantiate()
			.UpdataRelationsBetweenRegisteredObjects();
		Common::InputDevice::DeviceManager::Instantiate()
			.UpdataRegistedDevices();
	}

	inline void Draw(
		RenderProvider&	_render)
	{
		_render.Rendering();
	}

	inline void RegisterWithExecuter(
		Order::OrderedJobExcuter& _executer )
	{
		auto& jobReserve = Order::OrderedJobReserver::Instantiate();
		auto container = jobReserve.Reserve(Common::Constant::MTUpdataGrupName);
		_executer
			.Register<Worker::JobExecuter>(Common::Constant::MTUpdataGrupName, *container);
		_executer
			.Register(&Worker::MLRCPublisher::Instantiate(), Common::Constant::MTDrawGrupName);
	}
}

namespace Pyramid
{
	namespace Blueprint
	{
		std::shared_ptr<Window> Application::m_spMainWindow;
		std::shared_ptr<LevelStream> Application::m_spLevelStream;

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		Application::~Application()
		{
		}

		//-----------------------------------------------------------
		// Init
		//-----------------------------------------------------------
		void Application::Init(
			int _cmdShow, 
			int _w,
			int _h, 
			LPCTSTR _windowName, 
			bool _isWindow)
		{
			//コンストラクタで例外出したくないので抜き出し
			m_spMainWindow = make_shared<GameWindow>();

			m_spMainWindow->Create(_windowName, _w, _h);
			m_spMainWindow->Show(_cmdShow);
			m_spMainWindow->Update();

			//中で例外投げてるから特に例外処理しない
			Rendering::Graphics::Instantiate()
				.Create(m_spMainWindow->GetHwnd(), _w, _h, _isWindow);
			m_spLevelStream = make_shared<LevelStream>();

			//TODO Initializerで初期化
			Rendering::HLRCommand::Default::StaticDefaultCommand::Instantiate();

			Common::WorldSpaceDivider::Instantiate()
				.Initialize(
					Constant::DivideSpaceLevel,
					Common::Diagram::AABB(					//TODO コンストじゃね
						Utility::Vector3::once * -10000,
						Utility::Vector3::once * 10000));
			
			Common::InputDevice::Key::Instantiate();
			Common::InputDevice::Mouse::Instantiate();

			auto& colliderManager = 
				Collision::Detail::CollisionSystem::Instantiate()
				.Provider
				.Manager;

			colliderManager.Add<AABBAndAABB>();
			colliderManager.Add<AABBAndOBB>();
			colliderManager.Add<OBBAndOBB>();
			colliderManager.Add<OBBAndSphere>();
			colliderManager.Add<SphereAndAABB>();
			colliderManager.Add<SphereAndSphere>();

			auto& uiSystem = UI::Event::UIPublishSystem::Instantiate();

			uiSystem.RegisterOfPublisher<UI::Event::Publisher::UIChangeState>();
			uiSystem.RegisterOfPublisher<UI::Event::Publisher::UICursor>();

			___DEBUG_DEFINE(
				Utility::Debug::Instantiate().UseDebugConsole(1000,200,800,800);
			)
		}

		//-----------------------------------------------------------
		// Finit
		//-----------------------------------------------------------
		void Application::Finit()
		{
			m_spLevelStream.reset();
			m_spMainWindow.reset();
		}

		//-----------------------------------------------------------
		// Run
		//-----------------------------------------------------------
		void Application::Run()
		{
			Utility::FPSCounter fps;
			Common::TimerServer timeServer;		

			auto& render = Rendering::RenderProvider::Instantiate();
			auto& jobExecuter = Order::OrderedJobExcuter::Instantiate();
			
			::RegisterWithExecuter(jobExecuter);
			while (m_spMainWindow->MessageProc())
			{
				SET_TITLE(Constant::ClassName,"%f", fps.GetFps());
				::Updata(jobExecuter, m_spLevelStream);
				::Draw( render);
			}
		}
		//-----------------------------------------------------------
		// InterruptionAsyncLoad 
		//-----------------------------------------------------------
		void Application::InterruptionAsyncLoad()
		{
			m_spLevelStream->InterruptionAsyncLoad();
		}
		//-----------------------------------------------------------
		// UnLoadLevel
		//-----------------------------------------------------------
		void Application::UnLoadLevel(Level* _lv)
		{
			m_spLevelStream->RequestUnLoad(_lv);
		}

		//-----------------------------------------------------------
		// Quit
		//-----------------------------------------------------------
		void Application::Quit()
		{
			::PostQuitMessage(0);
		}

		//-----------------------------------------------------------
		// GetMainWindow
		//-----------------------------------------------------------
		std::shared_ptr<Window> Application::GetMainWindow()
		{
			return m_spMainWindow;
		}

	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------