/**
* @file		FbxMaterial.cpp
* @brief	FBXのマテリアルデータオブジェクトを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "DOFbxMateria.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace POCO
	{ 
		namespace Serialize
		{
			FbxMaterial::FbxMaterial(std::fstream & _parentStream) :
				FileDateObjectChild(_parentStream),
				mEmissive(_parentStream),
				mAmbient(_parentStream),
				mDiffuse(_parentStream),
				mSpecular(_parentStream),
				mBump(_parentStream)
			{
			}

			FbxMaterial::~FbxMaterial()
			{
			}

			void FbxMaterial::Serialize()
			{
				mEmissive.Color	= std::move(m_Material.Emissive);
				mAmbient.Color	= std::move(m_Material.Ambient);
				mDiffuse.Color	= std::move(m_Material.Diffuse);
				mSpecular.Color	= std::move(m_Material.Specular);
				mBump.Color		= std::move(m_Material.Bump);

				mEmissive.Serialize();
				mAmbient.Serialize();
				mDiffuse.Serialize();
				mSpecular.Serialize();
				mBump.Serialize();

				Write(&m_Material.Shinness, sizeof(float));
				Write(&m_Material.Transparency, sizeof(float));
				Write(&m_Material.Reflectivity, sizeof(float));
			}
		}

		namespace Deserialize
		{
			FbxMaterial::FbxMaterial(std::fstream & _parentStream):
				FileDateObjectChild(_parentStream),
				mEmissive(_parentStream),
				mAmbient(_parentStream),
				mDiffuse(_parentStream),
				mSpecular(_parentStream),
				mBump(_parentStream)
			{
			}

			FbxMaterial::~FbxMaterial()
			{
			}

			void FbxMaterial::Deserialize()
			{
				mEmissive.Deserialize();
				mAmbient.Deserialize();
				mDiffuse.Deserialize();
				mSpecular.Deserialize();
				mBump.Deserialize();

				m_Material.Emissive = std::move(mEmissive.Color);
				m_Material.Ambient = std::move(mAmbient.Color);
				m_Material.Diffuse = std::move(mDiffuse.Color);
				m_Material.Specular = std::move(mSpecular.Color);
				m_Material.Bump = std::move(mBump.Color);

				Read(&m_Material.Shinness, sizeof(float));
				Read(&m_Material.Transparency, sizeof(float));
				Read(&m_Material.Reflectivity, sizeof(float));
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
