/**
	* @file		Profiler.h
	* @brief	�v���t�@�C���@�\��� 
	* @author	SOIKAWA
	* @date		2016.05.23
	*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>
#include<map>
#include<time.h>
#include<list>
#include"TextFile.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	/// �����[�X���ɌĂяo�����Ə�����֐�
	/// </summary>

#ifdef _DEBUG
#define ___D_PROFILE_BEGIN(category,name)\
		::Utility::Profiler::Instance().Begin(#category,#name);

#define ___D_PROFILE_END(category,name)\
		::Utility::Profiler::Instance().End(#category,#name);

#define ___D_PROFILE_BEGIN(name)\
		::Utility::Profiler::Instance().Begin(#name);

#define ___D_PROFILE_END(name)\
		::Utility::Profiler::Instance().End(#name);
#else
#define	___D_PROFILE_BEGIN(category,name)
#define	___D_PROFILE_END(category,name)
#define	___D_PROFILE_BEGIN(category,name)
#define	___D_PROFILE_END(category,name)

#endif // !_DEBUG


/// <summary>
/// �����[�X���Ɏc��֐�
/// </summary>

#ifdef USE_RELEASE_PROFILE
#define ___PROFILE_BEGIN(category,name)\
		Profiler::Instance().Begin(#category,#name);

#define ___PROFILE_END(category,name)\
		Profiler::Instance().End(#category,#name);

#define ___PROFILE_BEGIN_IN_CATEGORY(name)\
		Profiler::Instance().Begin(#name);

#define ___PROFILE_END_IN_CATEGORY(name)\
		Profiler::Instance().End(#name);
#else

#define ___PROFILE_BEGIN(category,name)
#define ___PROFILE_END(category,name)
#define ___PROFILE_BEGIN_IN_CATEGORY(name)
#define ___PROFILE_END_IN_CATEGORY(name)

#endif

/// <summary>
/// �v���N���X
/// </summary>
	class Profiler
	{
		//-----------------------------------------------------------
		// private struct
		//-----------------------------------------------------------
		class ProfileData
		{
		public:
			ProfileData(std::string _name) :
				name(_name)
			{
				start = clock();
			}
			std::list<double>	distances;
			double				commonSum = 0;
			double				processtime = 0;

			clock_t				start;
			clock_t				end;

			std::string			name;
		};
		//-----------------------------------------------------------
		// using
		//-----------------------------------------------------------
		using DataMap = std::map<std::string, ProfileData*>;
		using CategoryMap = std::map<std::string, DataMap*>;
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
		Profiler() = default;
	public:
		virtual ~Profiler();

		//-----------------------------------------------------------
		// default
		//-----------------------------------------------------------
		Profiler(const Profiler&) = default;
		Profiler(Profiler&&) = default;

		Profiler& operator=(const Profiler&) = default;
		Profiler& operator=(Profiler&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
			/// <summary>
			/// �����֐�
			/// </summary>
			/// <returns>�C���X�^���X�Q��</returns>
		static Profiler& Instance();

		/// <summary>
		/// ����J�n
		/// </summary>
		/// <param name="_category">�J�e�S��</param>
		/// <param name="_name">�v���p�e�B��</param>
		void Begin(std::string _category, std::string _name);

		/// <summary>
		/// ����J�n
		/// ���O�̃J�e�S���������p��
		/// </summary>
		/// <param name="_name">�v���p�e�B��</param>
		void Begin(std::string _name);

		/// <summary>
		/// ����I��
		/// </summary>
		/// <param name="_category">�J�e�S��</param>
		/// <param name="_name">�v���p�e�B��</param>
		void End(std::string _category, std::string _name);

		/// <summary>
		/// ����I��
		/// ���O�̃J�e�S���������p��
		/// </summary>
		/// <param name="_name">�v���p�e�B��</param>
		void End(std::string _name);

		/// <summary>
		/// �f�[�^�̕�����
		/// ��t���[����񂭂炢�ł���
		/// </summary>
		void CollectData();

		//-----------------------------------------------------------
		//Property
		//-----------------------------------------------------------
		PROPERTY(m_SamplingCountMax, SamplingCountMax, int);
		PROPERTY_CR_R_ONLY(m_DataString, Data, std::string);
	private:
		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
		CategoryMap			m_CategoryMap;
		TextFile			m_OutputFile;
		std::string			m_DataString;
		std::string			m_ParentCategory;
		unsigned			m_SamplingCountMax = 60;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------