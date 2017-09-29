/**
* @file		Profiler.cpp
* @brief	Profiler�̃e���v���[�g����
* @author	S.OIKAWA
* @date		2016.05.23
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Profiler.h"
#include<direct.h>

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace std;
namespace Utility
{
	//-----------------------------------------------------------
	// dtor
	//-----------------------------------------------------------
	Profiler::~Profiler()
	{
		if (m_CategoryMap.empty())
		{
			return;
		}
		string mode;
#ifdef _DEBUG
		mode += "Debug\n\n";
#else
		mode += "Release\n\n";
#endif // _DEBUG

		_mkdir(g_FileDirectory.c_str());

		CollectData();
		m_OutputFile.Buffer = mode + m_DataString;
		m_OutputFile.Write(g_FileDirectory + "Profile.txt");

		for (auto& cit : m_CategoryMap)
		{
			for (auto it : *cit.second)
			{
				SAFE_DELETE(it.second);
			}
			SAFE_DELETE(cit.second);
		}
	}

	//-----------------------------------------------------------
	// Instance
	//-----------------------------------------------------------
	Profiler & Profiler::Instance()
	{
		static Profiler prof;
		return prof;
	}

	//-----------------------------------------------------------
	// Begin
	//-----------------------------------------------------------
	void Profiler::Begin(std::string _category, std::string _name)
	{
		m_ParentCategory = _category;
		auto cit = m_CategoryMap.find(_category);
		if (cit == m_CategoryMap.end())
		{
			//�}�b�v����
			auto pMap = new DataMap;
			m_CategoryMap.insert(make_pair(_category, pMap));

			//�f�[�^����
			ProfileData* pData = new ProfileData(_name);

			//�o�^
			pMap->insert(make_pair(_name, pData));
			return;
		}

		//����
		auto dit = cit->second->find(_name);
		if (dit == cit->second->end())
		{
			//�Ȃ���ΐ���
			ProfileData* pData = new ProfileData(_name);

			//�o�^
			cit->second->insert(make_pair(_name, pData));

			return;
		}

		//�f�[�^�擾�E�X�V
		dit->second->start = clock();
	}

	void Profiler::Begin(std::string _name)
	{
		Begin(m_ParentCategory, _name);
	}

	//-----------------------------------------------------------
	// End
	//-----------------------------------------------------------
	void Profiler::End(std::string _category, std::string _name)
	{
		//�Ȃ���Ή������Ȃ�
		auto cit = m_CategoryMap.find(_category);
		if (cit == m_CategoryMap.end() || cit->second->find(_name) == cit->second->end())
		{
			return;
		}



		auto pData = (*m_CategoryMap[_category])[_name];
		//�f�[�^�X�V
		pData->end = clock();

		//���Z
		auto distans = (double)(pData->end - pData->start);
		auto ave = (pData->commonSum + distans) / (pData->distances.size() + 1);
		if (ave != 0)
		{
			pData->processtime = ave;
		}

		double popData = 0;
		if (pData->distances.size() > m_SamplingCountMax)
		{
			popData = *(pData->distances.begin());
			pData->distances.pop_front();
		}

		pData->commonSum += distans - popData;

		//�v�f�ǉ�
		pData->distances.emplace_back(distans);

	}

	//-----------------------------------------------------------
	// End
	//-----------------------------------------------------------
	void Profiler::End(std::string _name)
	{
		End(m_ParentCategory, _name);
	}

	//-----------------------------------------------------------
	// CollectData
	//-----------------------------------------------------------
	void Profiler::CollectData()
	{
		string buffer;
		for (auto& cit : m_CategoryMap)
		{
			//�J�e�S�������o��
			buffer += cit.first + "------------------------\n";

			//�f�[�^�����o��
			for (auto it : *cit.second)
			{
				buffer +=
					it.second->name + " : " + std::to_string(it.second->processtime) + "\n";
			}

			buffer += "\n";
		}

		m_DataString = std::move(buffer);

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------