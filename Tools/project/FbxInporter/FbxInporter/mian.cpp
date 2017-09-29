#include<fbxsdk.h>
#include"FbxService.h"
#include"FbxModelFile.h"
#include"FbxLoader.h"
#include"DateObject\DOFbxFile.h"
#include"FbxAndBMInterconverter.h"

#include<vector>
#include<utility>
#include<string>
#include <algorithm>
#include<fstream>
#include<iostream>
#include<tuple>
#include<typeindex>
using namespace std;

std::vector<std::string> 
get_file_path_in_dir(const std::string& dir_name, const std::string& extension) noexcept(false)
{
	HANDLE hFind;
	WIN32_FIND_DATA win32fd;
	std::vector<std::string> file_names;

	std::string search_name = dir_name + "\\*." + extension;
	hFind = FindFirstFile(search_name.c_str(), &win32fd);

	if (hFind == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("file not found");
	}

	do 
	{
		if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) 
		{
		}
		else 
		{
			file_names.push_back(win32fd.cFileName);
		}
	} while (FindNextFile(hFind, &win32fd));

	FindClose(hFind);
	return file_names;
}

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	TCHAR crDir[MAX_PATH + 1];

	GetCurrentDirectory(MAX_PATH + 1, crDir);
	auto& nameList =  get_file_path_in_dir(crDir,"fbx");

	auto& ins = FbxLoader::Instantiate();
	auto& converter = FbxAndBMInterconverter::Instantiate();

	string log("");

	for(auto& _ : nameList)
	{ 
		log += _;
		log += "\n";

		auto pModel = ins.Load(_);
		auto pOut = converter.ToSerializeFile(pModel);

		printf(" %s \n", _.c_str());

		for (auto& mesh : pOut->File.Meshs)
		{
			string data;
			data += " Min:X ";
			data += std::to_string(mesh.Volume.m_Min.x);
			data += " Min:Y ";
			data += std::to_string(mesh.Volume.m_Min.y);
			data += " Min:Z ";
			data += std::to_string(mesh.Volume.m_Min.z);
			data += "\n";

			auto sp1 = sqrt(
				mesh.Volume.m_Min.x + mesh.Volume.m_Min.x +
				mesh.Volume.m_Min.y + mesh.Volume.m_Min.y +
				mesh.Volume.m_Min.z + mesh.Volume.m_Min.z);

			data += " Max:X ";
			data += std::to_string(mesh.Volume.m_Max.x);
			data += " Max:Y ";
			data += std::to_string(mesh.Volume.m_Max.y);
			data += " Max:Z ";
			data += std::to_string(mesh.Volume.m_Max.z);
			data += "\n";

			auto sp2 = sqrt(
				mesh.Volume.m_Max.x + mesh.Volume.m_Max.x +
				mesh.Volume.m_Max.y + mesh.Volume.m_Max.y +
				mesh.Volume.m_Max.z + mesh.Volume.m_Max.z);

			auto sp = max(sp1,sp2);
			data += " sphere: ";
			data += std::to_string(sp);

			printf(" %s \n", data.c_str());
			log += data;
			log += "\n";
		}

		float scale = 0;
		printf(" scale \n");
		scanf("%f", &scale);

		log += " scale ";
		log += std::to_string(scale);
		log += "\n";

		if (1.0 != scale)
		{
			pOut->Scaleing(scale);
		}

		pOut->Serialize();
	
		SAFE_DELETE(pOut);
	}
	SingletonFinalizer::Finalize();


	fstream out;
	out.open("log.txt",std::ios::trunc);
	out << log;
	out.close();
	return 0;
}