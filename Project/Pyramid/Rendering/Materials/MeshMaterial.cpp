/**
* @file
* @brief
* @author
* @date
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "MeshMaterial.h"
#include"../Rendering/Graphics.h"
#include"../RenderProvider.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace std;
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			MeshMaterial::MeshMaterial(std::string _OpaquePath, std::string _TransparentPath):
				m_OpaqueShader(this, _OpaquePath),
				m_TransparentShader(this, _TransparentPath),
				m_pActiveShader(nullptr),
				m_Transparency(1.0)
			{
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			MeshMaterial::~MeshMaterial()
			{
			}

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			MeshMaterial::MeshMaterial(const MeshMaterial & _other):
				m_OpaqueShader(this, _other.m_OpaqueShader.FilePath),
				m_TransparentShader(this, _other.m_TransparentShader.FilePath),
				m_Emissive(_other.m_Emissive),
				m_Ambient(_other.m_Ambient),
				m_Diffuse(_other.m_Diffuse),
				m_Specular(_other.m_Specular),
				m_Bump(_other.m_Bump),
				m_Shinness(_other.m_Shinness),
				m_Transparency(_other.m_Transparency),
				m_Reflectivity(_other.m_Reflectivity),
				m_pActiveShader(nullptr)
			{
			}

			//-----------------------------------------------------------
			// SetMateral
			//-----------------------------------------------------------
			void MeshMaterial::SetMateral()
			{
				m_pActiveShader =
					(std::abs(1-m_Transparency)<0.001f) ? &m_OpaqueShader : &m_TransparentShader;
				m_pActiveShader->SetColorFromMaterial();
				m_pActiveShader->SetTextureFromMaterial();
				m_pActiveShader->SetMatrix();
				m_pActiveShader->SetLight();
				m_pActiveShader->Begin();
			}

			//-----------------------------------------------------------
			// RiseMateral
			//-----------------------------------------------------------
			void MeshMaterial::RiseMateral()
			{
				m_pActiveShader->Eed();
			}

			//-----------------------------------------------------------
			// SetMatrix
			//-----------------------------------------------------------
			void MeshMaterial::SetMatrix(D3DXMATRIX & _mat)
			{
				m_OpaqueShader.pMatrix = &_mat;
				m_TransparentShader.pMatrix = &_mat;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------