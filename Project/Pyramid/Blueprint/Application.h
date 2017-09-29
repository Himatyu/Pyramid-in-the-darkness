/**
* @file		Application.h
* @brief	アプリケーションクラス
* @author	S.OIKAWA
* @date		2016/07/26
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<memory>
#include<string>
#include<vector>
#include"window.h"
#include"LevelStream.h"
#include"../Utility/StaticValue.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			class ThreadJob;
			class AsyncMRCPublish;
		}
	}
}

namespace Pyramid
{
	namespace Blueprint
	{

		class Window;
		class Graphics;
		class Level;

		/// <summary>
		/// プログラムの大枠.
		/// 汎用性はあんまり考えてない.
		/// </summary>
		class Application final
		{
		public:
			//-----------------------------------------------------------
			// defaluts
			//-----------------------------------------------------------
			Application() = default;
			~Application();

			Application(const Application&) = default;
			Application(Application&&) = default;

			Application& operator=(const Application&) = default;
			Application& operator=(Application&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			/// <summary>
			/// アプリケーションの初期化.
			/// </summary>
			void Init(
				int _cmdShow,
				int _w,
				int _h,
				LPCTSTR _windowName,
				bool _isWindow);

			/// <summary>
			/// リソースの開放とか.
			/// </summary>
			void Finit();

			/// <summary>
			/// 開始.
			/// </summary>
			void Run();

			/// <summary>
			/// レベル読み込み.
			/// 次フレーム頭にLoad.
			/// </summary>
			template<class LevelType>
			static void LoadLevel(bool isCurrent = false);

			/// <summary>
			/// レベル読み込み.
			/// LoadはされずにLoadLevel時に
			/// 読み込み完了していれば即時に読み込まれる.
			/// </summary>
			template<class LevelType>
			static void AsyncLoadLevel();

			/// <summary>
			/// レベル読み込みが終わっているか確認する.
			/// </summary>
			template<class LevelType>
			static bool IsLoadedAsyncLevel();

			/// <summary>
			/// 非同期読み込みを中止する
			/// </summary>
			static void InterruptionAsyncLoad();

			/// <summary>
			/// レベル廃棄.
			/// 次フレーム頭にUnLoad.
			/// </summary>
			/// <param name="_lv"></param>
			static void UnLoadLevel(Level* _lv);

			/// <summary>
			/// アプリケーション強制終了.
			/// </summary>
			static void Quit();

			/// <summary>
			/// メインウィンドのスマポ取得.
			/// プロパティで出来無いみたい.
			/// </summary>
			static std::shared_ptr<Window> GetMainWindow();

		private:
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			static std::shared_ptr<Window>		m_spMainWindow;
			static std::shared_ptr<LevelStream>	m_spLevelStream;
		};
#include"Application.inl"
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
