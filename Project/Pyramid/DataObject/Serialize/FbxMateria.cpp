/**
* @file		FbxMaterial.cpp
* @brief	FBXのマテリアルシリアライズ
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
	namespace Serialize
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
		// Serialize
		//-----------------------------------------------------------
		void FbxMaterial::Serialize()
		{
			m_Emissive.Dto	= std::move(m_Dto.Emissive);
			m_Ambient.Dto	= std::move(m_Dto.Ambient);
			m_Diffuse.Dto	= std::move(m_Dto.Diffuse);
			m_Specular.Dto	= std::move(m_Dto.Specular);
			m_Bump.Dto		= std::move(m_Dto.Bump);

			m_Emissive.Serialize();
			m_Ambient.Serialize();
			m_Diffuse.Serialize();
			m_Specular.Serialize();
			m_Bump.Serialize();

			Write(&m_Dto.Shinness, sizeof(float));
			Write(&m_Dto.Transparency, sizeof(float));
			Write(&m_Dto.Reflectivity, sizeof(float));
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
