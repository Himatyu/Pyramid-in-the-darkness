/**
	  * @file	FbxAndBMInterconverter.h
	  * @brief	Fbx��BM�𑊌ݕϊ�����@�\���
	  * @author	S.OIKAWA
	  * @date	2016.10.15
	  */

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxLoader.h"
#include"FbxModelFile.h"
#include"DateObject\DOFbxFile.h"
#include"singleton.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

/// <summary>
/// Fbx��BM�𑊌ݕϊ�����.
/// �ϊ����t�@�C������ϊ���t�@�C���𐶐�����
/// </summary>
class FbxAndBMInterconverter : 
	public Singleton<FbxAndBMInterconverter>
{
public:
	FbxAndBMInterconverter() {}
	~FbxAndBMInterconverter() {}

	/// <summary>
	/// FbxModelFile������DO�����.
	/// FbxModelFile�͉�������
	/// </summary>
	DataObject::POCO::Serialize::FbxFile *
		ToSerializeFile(FbxModelFile* _serializeFile);

	/// <summary>
	/// DO������FbxModelFile���쐬����
	/// DO�͉�������
	/// </summary>
	FbxModelFile* ToFbxModelFile(DataObject::POCO::Deserialize::FbxFile* _deserializedFile);
};

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------