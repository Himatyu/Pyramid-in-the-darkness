/**
	  * @file		FbxModelFile.h
	  * @brief		�Q�[�����Ŏg�p����Fbx��Model�f�[�^���`
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<d3dx9.h>
#include<vector>
#include<unordered_map>
#include<array>
#include<algorithm>
#include"Macro.h"
#include"AABB.h"

/// <summary>
/// �F���ێ�
/// </summary>
struct ColorChannel
{
	ColorChannel()
	{
		___FOREACH(color, [](auto& _) {_ = 0.0f; });
	}
	std::array<float, 4>		color;
	std::vector<std::pair<std::string,std::vector<char>>>	m_Textures;
};

/// <summary>
/// �}�e���A���̏���ێ�����
/// </summary>
struct FbxMaterial
{
	ColorChannel mEmissive;
	ColorChannel mAmbient;
	ColorChannel mDiffuse;
	ColorChannel mSpecular;
	ColorChannel mBump;

	float mShinness		= 1.0;
	float mTransparency = 1.0;
	float mReflectivity = 0.0;
};

/// <summary>
/// Fbx���f�����\�z����C���i�[���b�V��
/// </summary>
struct FbxInnerMesh
{
	~FbxInnerMesh();
	size_t						m_IndexCount	= 0;
	size_t						m_VertexCount	= 0;
	size_t						m_PolygonCount	= 0;

	std::vector<D3DXVECTOR3>		m_VertexArray;
	std::vector<int>				m_IndexArray;
	std::vector<D3DXVECTOR3>		m_NormalArray;
	std::vector<D3DXVECTOR2>		m_UVArray;

	std::unordered_map<std::string, std::vector<D3DXVECTOR2>> m_UVs;
	std::vector<FbxMaterial*>	m_Materials;
	AABB						m_Volume;
};

/// <summary>
/// Fbx��Model�f�[�^
/// </summary>
struct FbxModelFile
{
	~FbxModelFile();
	std::vector<FbxInnerMesh*> meshs;
	std::string filePath;
};
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------