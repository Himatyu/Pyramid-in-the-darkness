/**
* @file		LevelStream.h
* @brief	���x���Ǘ��N���X
* @author	S.OIKAWA
* @date		2016/07/26
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include<vector>
#include<functional>
#include<typeindex>
#include"../MT/Jobs/AsyncLoadLevel.h"
#include"../MT/Thread.h"
#include"../MT/ThreadSystem.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Blueprint
	{
		class Level;
		using LevelProc = void(Level& _lv);
		#define ProcType [](Level& _lv)

		/// <summary>
		/// ���x���Ǘ��N���X.
		/// �m�ۊJ���͍X�V���ɍs�������Ȃ��̂Ńt���[���̓��ōs��.
		/// </summary>
		class LevelStream final
		{
		public:
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			LevelStream() = default;
			~LevelStream();

			LevelStream(const LevelStream&) = default;
			LevelStream(LevelStream&&) = default;

			LevelStream& operator=(const LevelStream&) = default;
			LevelStream &operator=(LevelStream&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
				/// <summary>
				/// ���x���ǂݍ���.
				/// ���t���[������Load.
				/// </summary>
			template<class LevelType>
			void RequestLoad(bool _isCurrent);

			/// <summary>
			/// ���x���ǂݍ���.
			/// ���N�G�X�g�̂������S�Ẵ��x����
			/// �ǂݍ��܂�Ȃ��ƃA�N�Z�X�ł��Ȃ�.
			/// </summary>
			template<class LevelType>
			void RequestAsyncLoad();

			/// <summary>
			/// ���x���ǂݍ��݂��I����Ă��邩�m�F����.
			/// </summary>
			template<class LevelType>
			bool IsLoadedAsyncLevel();

			/// <summary>
			/// �񓯊��ǂݍ��݂𒆎~����
			/// </summary>
			void InterruptionAsyncLoad();

			/// <summary>
			/// �j�����X�g�ɒǉ�.
			/// ���t���[������UnLoad
			/// </summary>
			/// <param name="_lv">�j�����x���|�C���^</param>
			void RequestUnLoad(Level* _lv);

			/// <summary>
			/// ���x���X�V.
			/// FreamProcs�̓o�^���̂ݍX�V.
			/// �Ⴆ��FreamProcs[0~1]�Ȃ�Levels[0~1]�����X�V���Ȃ�.
			/// </summary>
			void UpdataStream();

		private:
			/// <summary>
			/// ���x���̊m�ہA�o�^
			/// </summary>
			void Load();

			/// <summary>
			/// ���x���̊J���A�o�^�j��.
			/// </summary>
			void UnLoad();

		public:
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
				/// <summary>
				/// �o�^���x���̍X�V���@.
				/// [0]���v���C���[�̂��郌�x����[1]��[2]�͋߂��̃��x��.
				/// ���݂����Ȋ����ŏ���������.
				/// inout�����������猩����.
				/// </summary>
			static std::vector<std::function<LevelProc>>		FreamProcs;

		private:
			std::list<Level*>									m_Levels;
			std::vector<std::pair<Level*, bool>>				m_requestLoadLevel;
			std::vector<Level*>									m_requestUnloadLevel;
			std::list<std::pair<Level*, std::type_index>>		m_AsyncLoadedLecelList;

			MT::Thread*											m_pLoadThread;
			MT::Jobs::AsyncLoadLevel							m_AsyncLoadLevel;

		};
#include"LevelStream.inl"
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

