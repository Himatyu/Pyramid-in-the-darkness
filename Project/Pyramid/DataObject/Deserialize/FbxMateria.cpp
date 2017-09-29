/**
* @file		FbxMaterial.cpp
* @brief	FBXのマテリアルデシリアライズを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "FbxMateria.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Deserialize
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		FbxMaterial::FbxMaterial(std::fstream & _parentStream) :
			FileDataObjectChild(_parentStream),
			m_Emissive(_parentStream),
			m_Ambient(_parentStream),
			m_Diffuse(_parentStream),
			m_Specular(_parentStream),
			m_Bump(_parentStream)
		{
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		FbxMaterial::~FbxMaterial()
		{
		}

		//-----------------------------------------------------------
		// Deserialize
		//-----------------------------------------------------------
		void FbxMaterial::Deserialize()
		{
			m_Emissive.Deserialize();
			m_Ambient.Deserialize();
			m_Diffuse.Deserialize();
			m_Specular.Deserialize();
			m_Bump.Deserialize();

			m_Dto.Emissive = std::move(m_Emissive.Dto);
			m_Dto.Ambient = std::move(m_Ambient.Dto);
			m_Dto.Diffuse = std::move(m_Diffuse.Dto);
			m_Dto.Specular = std::move(m_Specular.Dto);
			m_Dto.Bump = std::move(m_Bump.Dto);

			Read(&m_Dto.Shinness, sizeof(float));
			Read(&m_Dto.Transparency, sizeof(float));
			Read(&m_Dto.Reflectivity, sizeof(float));
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
