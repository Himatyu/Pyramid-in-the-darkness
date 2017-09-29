/**
* @file		Application.h
* @brief	�A�v���P�[�V�����N���X
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
		/// �v���O�����̑�g.
		/// �ėp���͂���܂�l���ĂȂ�.
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
			/// �A�v���P�[�V�����̏�����.
			/// </summary>
			void Init(
				int _cmdShow,
				int _w,
				int _h,
				LPCTSTR _windowName,
				bool _isWindow);

			/// <summary>
			/// ���\�[�X�̊J���Ƃ�.
			/// </summary>
			void Finit();

			/// <summary>
			/// �J�n.
			/// </summary>
			void Run();

			/// <summary>
			/// ���x���ǂݍ���.
			/// ���t���[������Load.
			/// </summary>
			template<class LevelType>
			static void LoadLevel(bool isCurrent = false);

			/// <summary>
			/// ���x���ǂݍ���.
			/// Load�͂��ꂸ��LoadLevel����
			/// �ǂݍ��݊������Ă���Α����ɓǂݍ��܂��.
			/// </summary>
			template<class LevelType>
			static void AsyncLoadLevel();

			/// <summary>
			/// ���x���ǂݍ��݂��I����Ă��邩�m�F����.
			/// </summary>
			template<class LevelType>
			static bool IsLoadedAsyncLevel();

			/// <summary>
			/// �񓯊��ǂݍ��݂𒆎~����
			/// </summary>
			static void InterruptionAsyncLoad();

			/// <summary>
			/// ���x���p��.
			/// ���t���[������UnLoad.
			/// </summary>
			/// <param name="_lv"></param>
			static void UnLoadLevel(Level* _lv);

			/// <summary>
			/// �A�v���P�[�V���������I��.
			/// </summary>
			static void Quit();

			/// <summary>
			/// ���C���E�B���h�̃X�}�|�擾.
			/// �v���p�e�B�ŏo�������݂���.
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
