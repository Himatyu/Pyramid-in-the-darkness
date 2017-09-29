
#include"Blueprint\Application.h"
#include"App/Level/TestLevel.h"
#include"TypeComparable.h"

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

using namespace Pyramid::Blueprint;
using namespace Pyramid::Components;
using namespace DataObject;

using namespace Pyramid::Rendering::HLRCommand;
int WINAPI _tWinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInst, 
	LPTSTR lpCmdLine, 
	int iCmdShow)
{
	ON_SEARCH_LEAK;
	//ON_BREAK_ALLOC(275);

#pragma region App
	try
	{
		
		Application app;
		app.Init(iCmdShow, 800, 800, _T("Pyramid"), true);
		Application::LoadLevel<Pyramid::TestLevel>();

		auto& procs = LevelStream::FreamProcs;
		procs.push_back(ProcType{ _lv.Updata(); _lv.Draw(); });
		procs.push_back(ProcType{ _lv.Updata(); _lv.Draw(); });
		procs.push_back(ProcType{ _lv.Updata(); _lv.Draw(); });
		___D_PROFILE_BEGIN("Application", "Run");
		app.Run();
		___D_PROFILE_END("Application", "Run");
		app.Finit();
		
	}
	catch (::Utility::Exception* _e)
	{
		___LOG(_e->Detail);
		delete _e;
	}
	catch (std::exception e)
	{
		___LOG(e.what());
	}
	catch (...)
	{
		___LOG("不明なエラー終了");
	}
#pragma endregion

	::Utility::SingletonFinalizer::Finalize();
	return 0;
}

