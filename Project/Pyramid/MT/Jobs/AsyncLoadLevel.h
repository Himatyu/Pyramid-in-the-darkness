/**
* @file		AsyncLoadLevel.h
* @brief	�񓯊��̃��x���ǂݍ��݂��
* @author	S.OIKAWA
* @date		2016.10.08
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IThreadJob.h"
#include"../Blueprint/Creators/LevelCreator.h"
#include<mutex>
#include<list>
#include<utility>
#include<typeindex>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{
		class Level;
	}
}

namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			using LevelData = std::pair<Blueprint::Level*, std::type_index>;
			using RequestDate =
				std::pair<
				::Utility::Creator<Blueprint::Level*>*,
				std::type_index>;
#pragma endregion

			/// <summary>
			/// �񓯊��̃��x���ǂݍ���.
			/// </summary>
			class AsyncLoadLevel  final :
				public IThreadJob
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				AsyncLoadLevel() = default;
				~AsyncLoadLevel();

				AsyncLoadLevel(const AsyncLoadLevel&) = default;
				AsyncLoadLevel(AsyncLoadLevel&&) = default;

				AsyncLoadLevel& operator=(const AsyncLoadLevel&) = default;
				AsyncLoadLevel& operator=(AsyncLoadLevel&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �o�^�������x����ǂݍ���.
				/// ���X�g�������Ȃ�܂Ń��[�h��������.
				/// </summary>
				virtual void Job();

				/// <summary>
				/// �ǂݍ��ނ̂𒆒f����.
				/// ���݂̓ǂݍ��݂͊��������Ă���I������.
				/// ���N�G�X�g���X�g�͏����������.
				/// </summary>
				void Interruption();

				/// <summary>
				/// ���[�h���N�G�X�g�𑗂�.
				/// ���f��Ԃ̏ꍇ��������.
				/// </summary>
				template<class Lv>
				void LoadRequest();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				//�O�ŃN���A������̂�const�͂��Ȃ�,�X���b�h���܂����̂ŃR�s�[
				THREAD_SAFE_PROPERTY_R_ONLY(
					m_LoadedLevelList,
					LoadedLevelList,
					std::list<LevelData>,
					m_LoadedLevelListMutex
				);

#pragma endregion

			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::list <RequestDate>				m_LevelLoadRequestList;
				std::mutex							m_LevelLoadRequestListMutex;

				bool								m_IsInterruption;
				std::mutex							m_IsInterruptionMutex;

				std::mutex							m_LoadedLevelListMutex;
				std::list<LevelData>				m_LoadedLevelList;
#pragma endregion
			};
#include"AsyncLoadLevel.inl"
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

