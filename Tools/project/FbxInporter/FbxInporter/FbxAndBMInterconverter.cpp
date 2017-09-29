#include "FbxAndBMInterconverter.h"

//-----------------------------------------------------------
// ToSerializeFile 
//-----------------------------------------------------------
DataObject::POCO::Serialize::FbxFile *
FbxAndBMInterconverter::ToSerializeFile(FbxModelFile * _pLoadedFile)
{
	if (!_pLoadedFile)
	{
		return nullptr;
	}

	auto filePath = _pLoadedFile->filePath;
	auto fileName = filePath.substr(filePath.find_last_of("/") + 1, filePath.size());
	auto fileNameNonExtension = fileName.substr(0,fileName.find("."));

	auto pSerializeFile = new DataObject::POCO::Serialize::FbxFile(fileNameNonExtension + ".bm");

	//TODO もう少しスマートに出来ないかな？
	for (auto& _ : _pLoadedFile->meshs)
	{
		
		//ポインタアクセスめんどい
		DataObject::DTO::FbxInnerMesh mesh;

		mesh.VertexCount = _->m_VertexCount;
		mesh.IndexCount = _->m_IndexCount;
		mesh.PolygonCount = _->m_PolygonCount;

		for (auto& vertex : _->m_VertexArray)
		{
			DataObject::float3 DOVertex;
			DOVertex.x = vertex.x;
			DOVertex.y = vertex.y;
			DOVertex.z = vertex.z;
			mesh.VertexArray.emplace_back(DOVertex);
		}

		mesh.IndexArray = std::move(_->m_IndexArray);

		for (auto& normal : _->m_NormalArray)
		{
			DataObject::float3 DONarmal;
			DONarmal.x = normal.x;
			DONarmal.y = normal.y;
			DONarmal.z = normal.z;
			mesh.NormalArray.emplace_back(DONarmal);
		}

		for (auto& uvPair : _->m_UVs)
		{
			auto& name = uvPair.first;
			auto& uv_d3dx = uvPair.second;
			std::vector<DataObject::float2> uv;
			for (auto& _ : uv_d3dx)
			{
				DataObject::float2 DOUv;
				DOUv.x = _.x;
				DOUv.y = _.y;
				uv.emplace_back(DOUv);
			}

			mesh.UVNameArray.emplace_back(name);
			mesh.UVArrays.emplace_back(uv);
		}

		for (auto& mat : _->m_Materials)
		{
			DataObject::DTO::FbxMaterial Mat;

			size_t arraySize = sizeof(float) * 4;
			memmove_s(Mat.Emissive.Value.Value,	arraySize, mat->mEmissive.color.data(), arraySize);
			memmove_s(Mat.Ambient.Value.Value,		arraySize, mat->mAmbient.color.data(),	arraySize);
			memmove_s(Mat.Diffuse.Value.Value,		arraySize, mat->mDiffuse.color.data(),	arraySize);
			memmove_s(Mat.Specular.Value.Value,	arraySize, mat->mSpecular.color.data(), arraySize);
			memmove_s(Mat.Bump.Value.Value,		arraySize, mat->mBump.color.data(),		arraySize);
			
			Mat.Emissive.Textures = std::move(mat->mEmissive.m_Textures);
			Mat.Ambient.Textures = std::move(mat->mAmbient.m_Textures);
			Mat.Diffuse.Textures = std::move(mat->mDiffuse.m_Textures);
			Mat.Specular.Textures = std::move(mat->mSpecular.m_Textures);
			Mat.Bump.Textures = std::move(mat->mBump.m_Textures);

			Mat.Shinness = mat->mShinness;
			Mat.Transparency = mat->mTransparency;
			Mat.Reflectivity = mat->mReflectivity;

			mesh.MaterialArray.emplace_back(Mat);
		}

		mesh.Volume = _->m_Volume;

		pSerializeFile->File.Meshs.emplace_back(mesh);
	}

	SAFE_DELETE(_pLoadedFile);
	return pSerializeFile;
}

//-----------------------------------------------------------
// ToFbxModelFile 
//-----------------------------------------------------------
FbxModelFile * FbxAndBMInterconverter::ToFbxModelFile(DataObject::POCO::Deserialize::FbxFile * _deserializedFile)
{
	auto pModelFile = new FbxModelFile;
	
	pModelFile->filePath  = std::move(_deserializedFile->fileName);

	auto& meshs = _deserializedFile->File.Meshs;
	for (auto& mesh : meshs)
	{
		auto pMesh = new FbxInnerMesh;

		for (auto& _ : mesh.VertexArray)
		{
			pMesh->m_VertexArray.emplace_back(D3DXVECTOR3(_.Value));
		}

		pMesh->m_IndexArray = std::move(mesh.IndexArray);

		for (auto& _ : mesh.NormalArray)
		{
			pMesh->m_NormalArray.emplace_back(D3DXVECTOR3(_.Value));
		}

		auto mapSize = mesh.UVNameArray.size();
		for (int i = 0; i < mapSize;i++)
		{
			std::vector<D3DXVECTOR2> d3dUV;
			for (auto& _ : mesh.UVArrays[i])
			{
				d3dUV.emplace_back(D3DXVECTOR2(_.Value));
			}
			pMesh->m_UVs
				.insert(std::move(std::make_pair(mesh.UVNameArray[i], d3dUV)));
		}

		for (auto& _ : mesh.MaterialArray)
		{
			auto pMat = new FbxMaterial;
			size_t arraySize = sizeof(float) * 4;

			memmove_s(pMat->mEmissive.color.data(), arraySize	,_.Emissive.Value.Value, arraySize	);
			memmove_s(pMat->mAmbient.color.data(), arraySize	,_.Ambient.Value.Value, arraySize	);
			memmove_s(pMat->mDiffuse.color.data(), arraySize	,_.Diffuse.Value.Value, arraySize	);
			memmove_s(pMat->mSpecular.color.data(), arraySize	,_.Specular.Value.Value, arraySize	);
			memmove_s(pMat->mBump.color.data(), arraySize		,_.Bump.Value.Value,	arraySize 	);

			pMat->mAmbient.m_Textures	= std::move(_.Ambient.Textures);
			pMat->mBump.m_Textures		= std::move(_.Bump.Textures);
			pMat->mDiffuse.m_Textures	= std::move(_.Diffuse.Textures);
			pMat->mEmissive.m_Textures	= std::move(_.Emissive.Textures);
			pMat->mSpecular.m_Textures	= std::move(_.Specular.Textures);

			pMat->mShinness		= _.Shinness;
			pMat->mTransparency = _.Transparency;
			pMat->mReflectivity = _.Reflectivity;

			pMesh->m_Materials.emplace_back(pMat);
		}

		pModelFile->meshs.emplace_back(pMesh);
	}
	SAFE_DELETE(_deserializedFile);
	return pModelFile;
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------