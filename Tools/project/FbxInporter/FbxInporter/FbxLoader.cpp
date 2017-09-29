/**
	  * @file		FbxLoader.cpp
	  * @brief		Fbxの読み込む
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxLoader.h"
#include"FbxModelFile.h"
#include"FbxService.h"
#include<memory>
#include<fstream>
#include<string>
#include<math.h>
#include"DateObject\DateType.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
using namespace fbxsdk;
using namespace std;


void GetUV(fbxsdk::FbxMesh * _pMesh, FbxInnerMesh& _innerMesh)
{
	//エレメントのUV取得
	FbxStringList UVSetNameList;
	_pMesh->GetUVSetNames(UVSetNameList);
	const size_t uvCount = UVSetNameList.GetCount();

	//なかった時のために0で確保
	std::vector<D3DXVECTOR2> InitUvs(_innerMesh.m_VertexCount, D3DXVECTOR2(0, 0));
	_innerMesh.m_UVArray = move(InitUvs);

	for (int uvSetIndex = 0; uvSetIndex < uvCount; uvSetIndex++)
	{
		auto pUvSetName = UVSetNameList.GetStringAt(uvSetIndex);
		auto pUVElement = _pMesh->GetElementUV(pUvSetName);

		vector<D3DXVECTOR2> uv;
		string SetName(pUvSetName);

		if (!pUVElement)
			continue;

		auto mapMode = pUVElement->GetMappingMode();
		if (mapMode != FbxGeometryElement::eByPolygonVertex &&
			mapMode != FbxGeometryElement::eByControlPoint)
		{
			continue;
		}


		auto refMode = pUVElement->GetReferenceMode();
		const bool useIndex = refMode != FbxGeometryElement::eDirect;
		const int IndexCount = useIndex ? pUVElement->GetIndexArray().GetCount() : 0;

		const int polyCount = _pMesh->GetPolygonCount();

		//頂点モード
		if (FbxGeometryElement::eByControlPoint == mapMode)
		{
			int IndexCounter = 0;
			uv.resize(_innerMesh.m_VertexCount);
			for (int polygonIndex = 0; polygonIndex < polyCount; ++polygonIndex)
			{
				const int polySize = _pMesh->GetPolygonSize(polygonIndex);

				for (int vertIndex = 0; vertIndex < polySize; ++vertIndex)
				{
					FbxVector2 fbxUV;
					switch (refMode)
					{
					case FbxGeometryElement::eDirect:
					{
						fbxUV = pUVElement->GetDirectArray().GetAt(IndexCounter);
						break;
					}
					case FbxGeometryElement::eIndexToDirect:
					{
						int id = pUVElement->GetIndexArray().GetAt(IndexCounter);
						fbxUV = pUVElement->GetDirectArray().GetAt(id);
						break;
					}
					default:
						break;
					}
					//頂点取得
					int PolyVertexIndex = _pMesh->GetPolygonVertex(polygonIndex, vertIndex);
					uv[PolyVertexIndex] = (D3DXVECTOR2(fbxUV[0], fbxUV[1]));
				}
			}
			IndexCounter++;
		}
		//ポリゴンモード
		else if (FbxGeometryElement::eByPolygonVertex == mapMode)
		{
			int polyIndexCounter = 0;
			int resize = useIndex ? _innerMesh.m_VertexCount : IndexCount;
			uv.resize(resize);
			for (int polyIndex = 0; polyIndex < polyCount; ++polyIndex)
			{
				const int polySize = _pMesh->GetPolygonSize(polyIndex);
				for (int vertexIndex = 0; vertexIndex < polySize; vertexIndex++)
				{
					if (polyIndexCounter < IndexCount)
					{
						int texUVIndex = _pMesh->GetTextureUVIndex(polyIndex, vertexIndex);
						auto& normal = pUVElement->GetDirectArray().GetAt(texUVIndex);

						int polygonIndex = _pMesh->GetPolygonVertex(polyIndex, vertexIndex);
						uv[polygonIndex] = (D3DXVECTOR2(normal[0], 1 - normal[1]));
						polyIndexCounter++;
					}
				}
			}
		}
		_innerMesh.m_UVs[SetName] = uv;
	}

	//とりあえず一つ
	if (!_innerMesh.m_UVs.empty())
	{
		_innerMesh.m_UVArray = (_innerMesh.m_UVs.begin())->second;
	}
}

void GetNormal(fbxsdk::FbxMesh * _pMesh, FbxInnerMesh& _innerMesh)
{
	FbxLayerElementNormal* pNormalElement = nullptr;
	int layerNum = _pMesh->GetLayerCount();
	for (int i = 0; i < layerNum; i++)
	{
		auto pLayer = _pMesh->GetLayer(i);
		pNormalElement = pLayer->GetNormals();
		if (!pNormalElement)
		{
			continue;
		}
		break;
	}

	if (!pNormalElement)
	{
		return;
	}

	//Control Point Mode
	//頂点ごとの法線
	auto mappingMode = pNormalElement->GetMappingMode();

	vector<D3DXVECTOR3> normals;
	if (FbxGeometryElement::eByControlPoint == mappingMode)
	{
		const int controlPointCount = _pMesh->GetControlPointsCount();
		normals.resize(controlPointCount);
		//頂点分法線取得
		for (int vertexIndex = 0; vertexIndex < controlPointCount; vertexIndex++)
		{
			int normalIndex = 0;
			auto element = pNormalElement->GetReferenceMode();

			if (FbxGeometryElement::eDirect == element)
			{
				normalIndex = vertexIndex;
			}

			if (FbxGeometryElement::eIndexToDirect == element)
			{
				normalIndex = pNormalElement->GetIndexArray().GetAt(normalIndex);
			}

			auto& normal = pNormalElement->GetDirectArray().GetAt(normalIndex);
			normals[vertexIndex] = (D3DXVECTOR3(normal[0], normal[1], -normal[2]));
		}

		_innerMesh.m_NormalArray = move(normals);
	}
	//ポリゴンごとの法線
	else if (FbxGeometryElement::eByPolygonVertex == mappingMode)
	{
		//ポリゴン
		int indexByPolygonVertex = 0;
		_innerMesh.m_NormalArray.resize(_innerMesh.m_VertexCount);
		const int polygonCount = _pMesh->GetPolygonCount();

		for (int polygonIndex = 0; polygonIndex < polygonCount; polygonIndex++)
		{
			//頂点
			int polygonSize = _pMesh->GetPolygonSize(polygonIndex);
			for (int i = 0; i < polygonSize; i++)
			{
				int normalIndex = 0;
				auto elementMode = pNormalElement->GetReferenceMode();
				int PolyVertexIndex = _pMesh->GetPolygonVertex(polygonIndex, i);
				if (FbxGeometryElement::eDirect == elementMode)
				{
					normalIndex = indexByPolygonVertex;
				}

				if (FbxGeometryElement::eIndexToDirect == elementMode)
				{
					normalIndex = pNormalElement->GetIndexArray().GetAt(indexByPolygonVertex);
				}

				//登録
				auto& normal = pNormalElement->GetDirectArray().GetAt(normalIndex);
				_innerMesh.m_NormalArray[PolyVertexIndex] = (D3DXVECTOR3(normal[0], normal[1], -normal[2]));
				indexByPolygonVertex++;
			}
		}

		////アジャスト
		//NormalArray.resize(VertexCount);
		//for (int i = 0; i < IndexCount; i++)
		//{
		//	NormalArray[IndexArray[i]] = normals[i];
		//}
	}

}

std::vector<std::string> GetTextureName(const FbxSurfaceMaterial* _pSurMat, const char* _Flag)
{
	vector<std::string> textureNames;
	string fileName = "Non";

	//レイヤードテクスチャは非対応
	auto pry = _pSurMat->FindProperty(_Flag);
	int layerNum = pry.GetSrcObjectCount(FbxLayeredTexture::ClassId);

	//if (!layerNum)
	{

		//複数枚取得するけど、一枚くらいしか使わない気がする
		int numGeneralTexture = pry.GetSrcObjectCount(FbxFileTexture::ClassId);
		for (int i = 0; i < numGeneralTexture; i++)
		{
			auto texture =
				FbxCast<FbxFileTexture>(pry.GetSrcObject(FbxFileTexture::ClassId, i));
			textureNames.emplace_back(texture->GetFileName());
		}
	}

	return textureNames;
}

FbxDouble3 GetMaterialProperty(const FbxSurfaceMaterial * pMaterial,
	const char * pPropertyName,
	const char * pFactorPropertyName)
{
	FbxDouble3 Result(0, 0, 0);
	const FbxProperty Property = pMaterial->FindProperty(pPropertyName);
	const FbxProperty FactorProperty = pMaterial->FindProperty(pFactorPropertyName);
	if (Property.IsValid() && FactorProperty.IsValid())
	{
		Result = Property.Get<FbxDouble3>();
		double Factor = FactorProperty.Get<FbxDouble>();
		if (Factor != 1)
		{
			Result[0] *= Factor;
			Result[1] *= Factor;
			Result[2] *= Factor;
		}
	}

	return Result;
}

FbxMaterial* MaterialCreate(FbxSurfaceMaterial * _pMaterial, FbxInnerMesh& _innerMesh)
{
	auto pFbxMaterial = new FbxMaterial;
	auto SetProperty = 
		[&](
			ColorChannel& channel,
			const char * pPropertyName,
			const char * pFactorPropertyName
			)
	{
		auto MatProperty =
			GetMaterialProperty(_pMaterial, pPropertyName, pFactorPropertyName);
		channel.color[0] = static_cast<float>(MatProperty[0]);
		channel.color[1] = static_cast<float>(MatProperty[1]);
		channel.color[2] = static_cast<float>(MatProperty[2]);
		channel.color[3] = 1.0f;
		auto nameList = GetTextureName(_pMaterial, pPropertyName);
		channel.m_Textures.resize(nameList.size());
		for (int i = 0; i < nameList.size(); i++)
		{
			channel.m_Textures[i].first = nameList[i];
		}

	};

	SetProperty(pFbxMaterial->mEmissive,
		FbxSurfaceMaterial::sEmissive, FbxSurfaceMaterial::sEmissiveFactor);

	SetProperty(pFbxMaterial->mAmbient,
		FbxSurfaceMaterial::sAmbient, FbxSurfaceMaterial::sAmbientFactor);

	SetProperty(pFbxMaterial->mDiffuse,
		FbxSurfaceMaterial::sDiffuse, FbxSurfaceMaterial::sDiffuseFactor);

	SetProperty(pFbxMaterial->mSpecular,
		FbxSurfaceMaterial::sSpecular, FbxSurfaceMaterial::sSpecularFactor);

	SetProperty(pFbxMaterial->mBump,
		FbxSurfaceMaterial::sBump, FbxSurfaceMaterial::sBumpFactor);

	auto SetPropertyOnce =
		[&, _pMaterial](float& dest, const char * pPropertyName)
	{
		FbxProperty Property = _pMaterial->FindProperty(pPropertyName);
		if (Property.IsValid())
		{
			double Value = Property.Get<FbxDouble>();
			dest = static_cast<float>(Value);
		}
	};

	SetPropertyOnce(pFbxMaterial->mShinness, FbxSurfaceMaterial::sShininess);
	SetPropertyOnce(pFbxMaterial->mTransparency, FbxSurfaceMaterial::sTransparentColor);
	SetPropertyOnce(pFbxMaterial->mReflectivity, FbxSurfaceMaterial::sReflection);

	//TODO ReadTexture

	return pFbxMaterial;
}

void GetMaterial(fbxsdk::FbxMesh * _pMesh, FbxInnerMesh& _innerMesh)
{
	//先頭ノード有効？
	auto pNode = _pMesh->GetNode();
	if (!pNode)
	{
		return;
	}

	//マテリアルの総数所得
	int materialCount = pNode->GetMaterialCount();
	if (!materialCount)
	{
		return;
	}

	for (int materialIndex = 0; materialIndex < materialCount; materialIndex++)
	{
		//Phong かLambert
		auto pFbxMaterial = pNode->GetMaterial(materialIndex);
		auto pMaterial = MaterialCreate(pFbxMaterial, _innerMesh);
		_innerMesh.m_Materials.emplace_back(pMaterial);
	}
}

void MeshAnalize(fbxsdk::FbxMesh * _pMesh, FbxInnerMesh& _innerMesh)
{
	//なければ終了
	if (!_pMesh->GetControlPointsCount())
	{
		//Err
		return;
	}

	//情報取得
	_innerMesh.m_VertexCount	= _pMesh->GetControlPointsCount();
	_innerMesh.m_IndexCount		= _pMesh->GetPolygonVertexCount();
	_innerMesh.m_PolygonCount	= _pMesh->GetPolygonCount();

	//データ取得
	D3DXVECTOR3 Max{0,0,0};
	auto& vol = _innerMesh.m_Volume;
	vol.m_Max = { 0,0,0 };
	vol.m_Min={ 0,0,0 };
	auto pVertexHead = _pMesh->GetControlPoints();
	for (int i = 0; i < _innerMesh.m_VertexCount; i++)
	{
		auto& v = pVertexHead[i];
		auto dxVec = D3DXVECTOR3(v[0], v[1], v[2]);

		vol.m_Max.x = max(vol.m_Max.x, dxVec.x);
		vol.m_Max.y = max(vol.m_Max.y, dxVec.y);
		vol.m_Max.z = max(vol.m_Max.z, dxVec.z);

		vol.m_Min.x = min(vol.m_Min.x, dxVec.x);
		vol.m_Min.y = min(vol.m_Min.y, dxVec.y);
		vol.m_Min.z = min(vol.m_Min.z, dxVec.z);

		_innerMesh.m_VertexArray.emplace_back(dxVec);
	}

	_innerMesh.m_IndexArray =
		vector<int>(_pMesh->GetPolygonVertices(),
			_pMesh->GetPolygonVertices() + _innerMesh.m_IndexCount);

	//リサイズ
	_innerMesh.m_VertexArray.resize(_innerMesh.m_VertexCount);
	_innerMesh.m_IndexArray.resize(_innerMesh.m_IndexCount);

	GetMaterial(_pMesh, _innerMesh);
	GetUV(_pMesh, _innerMesh);
	GetNormal(_pMesh, _innerMesh);
}

//-----------------------------------------------------------
// MeshDecode
//-----------------------------------------------------------
void MeshDecode(FbxNode* _pNode, FbxModelFile& _FbxMesh)
{
	auto pMesh = _pNode->GetMesh();
	auto pInnerMesh = new FbxInnerMesh();
	MeshAnalize(pMesh,*pInnerMesh);

	_FbxMesh.meshs.push_back(pInnerMesh);
}
//-----------------------------------------------------------
// NodeDecode 
//-----------------------------------------------------------
void NodeDecode(FbxNode* _pNode, FbxModelFile& _FbxMesh)
{
	//属性取得
	FbxNodeAttribute* pAttri = _pNode->GetNodeAttribute();
	if (!pAttri)
	{
		return;
	}

	//デコード
	auto AttriType = pAttri->GetAttributeType();
	switch (AttriType)
	{
	case fbxsdk::FbxNodeAttribute::eUnknown:
		break;
	case fbxsdk::FbxNodeAttribute::eNull:
		break;
	case fbxsdk::FbxNodeAttribute::eMarker:
		break;
	case fbxsdk::FbxNodeAttribute::eSkeleton:
		break;
	case fbxsdk::FbxNodeAttribute::eMesh:
		MeshDecode(_pNode, _FbxMesh);
		break;
	case fbxsdk::FbxNodeAttribute::eCamera:
		break;
	case fbxsdk::FbxNodeAttribute::eLight:
		break;
	default:
		break;
	}

}
//-----------------------------------------------------------
// NodeSurchRecursive
//-----------------------------------------------------------
void NodeSurchRecursive(FbxNode* _pNode, FbxModelFile& _FbxMesh)
{
	//デコード
	if (_pNode->GetNodeAttribute())
	{
		NodeDecode(_pNode, _FbxMesh);
	}

	//再帰
	const int childCount = _pNode->GetChildCount();
	for (int i = 0; i < childCount; ++i)
	{
		NodeSurchRecursive(_pNode->GetChild(i), _FbxMesh);
	}
}

//スーパーHACK
void LoadBinaryTexture(std::string _filePath, FbxModelFile* pData)
{
	//テクスチャは同じ階層にある想定
	auto DirIndex = _filePath.find_last_of("/");
	std::string dir;
	if (DirIndex == string::npos)
	{
		dir = "";
	}
	else
	{
		dir = _filePath.substr(0, DirIndex + 1);
	}

	auto LoadTexFile = 
		[&](std::pair < std::string, std::vector<char>>& _data)
	{
		std::fstream stream;
		stream.open(dir + _data.first, std::ios::binary | std::ios::in);

		stream.seekg(0, std::ios::end);
		auto tell = stream.tellg();
		stream.clear();
		stream.seekg(0, std::ios::beg);
		auto head = stream.tellg();

		auto size = tell - head;
		_data.second.resize(size);
		stream.read(_data.second.data(), size);
		stream.close();
	};

	for (auto& pMesh : pData->meshs)
	{
		for (auto& pMat : pMesh->m_Materials)
		{
			for (auto& TexData : pMat->mAmbient.m_Textures)
			{
				LoadTexFile(TexData);
			}
			for (auto& TexData : pMat->mBump.m_Textures)
			{
				LoadTexFile(TexData);
			}
			for (auto& TexData : pMat->mDiffuse.m_Textures)
			{
				LoadTexFile(TexData);
			}
			for (auto& TexData : pMat->mEmissive.m_Textures)
			{
				LoadTexFile(TexData);
			}			
			for (auto& TexData : pMat->mSpecular.m_Textures)
			{
				LoadTexFile(TexData);
			}
		}
	}

}

FbxLoader::FbxLoader()
{
}

FbxLoader::~FbxLoader()
{
}

FbxModelFile* FbxLoader::Load(std::string _fileName)
{
	//キャッシュ・生成
	auto& ins = FBXServer::Instantiate();
	auto pMgr = ins.pManager;
	auto pScene =
		FbxScene::Create(pMgr, (_fileName + "Scene").c_str());
	auto pImporter =
		FbxImporter::Create(pMgr, (_fileName + "Importer").c_str());

	//読み込み
	if (!pImporter->Initialize(_fileName.c_str(), -1, pMgr->GetIOSettings()))
	{
		return nullptr;
	}
	pImporter->Import(pScene);

	auto data = new FbxModelFile;
	data->filePath = _fileName;
	//ノードから情報取得
	NodeSurchRecursive(pScene->GetRootNode(), *data);

	LoadBinaryTexture(_fileName, data);

	return data;
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------