/**
* @file		ParticleShader.cpp
* @brief	パーティクル用のシェーダ
* @author	S.OIKAWA
* @date		2016.12.1
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ParticleShader.h"
#include"../Materials/ParticleMaterial.h"
#include"../RenderProvider.h"
#include"../Viewer.h"
#include"../Constant.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Rendering
	{
		namespace Shaders
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ParticleShader::ParticleShader(Materials::ParticleMateral * _pMat):
				Shader(Constant::ParticleShaderPath),
				m_pMaterial(_pMat),
				m_pMatMVP(new D3DXMATRIX*[3])
			{
				m_hIMVP = m_pEffect->GetParameterByName(NULL, "matMVP");
				m_hUV = m_pEffect->GetParameterByName(NULL, "UV");
				m_hDiffuse = m_pEffect->GetParameterByName(NULL, "Diffuse");
				m_hTexDecal = m_pEffect->GetParameterByName(NULL, "texDecal");
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			ParticleShader::~ParticleShader()
			{
				SAFE_DELETE_ARRAY(m_pMatMVP);
			}

			//-----------------------------------------------------------
			// SetData
			//-----------------------------------------------------------
			void ParticleShader::SetData()
			{
				m_pEffect->SetValue(m_hUV, m_pMaterial->pArrayUV.data(), 16);
				m_pEffect->SetTexture(
						m_hTexDecal,
						m_pMaterial->Texture.spResourceFile->pTexture);
				m_pEffect->SetValue(m_hDiffuse, m_pMaterial->pColor->Array, 16);			
			}

			//-----------------------------------------------------------
			// SetMatrix
			//-----------------------------------------------------------
			void ParticleShader::SetMatrix()
			{
				auto& render = RenderProvider::Instantiate().Wolrd;
				auto pViewInfo = render.pCurrentViewer;

				m_pMatMVP[0] = m_pMatrix;
				m_pMatMVP[1] = &pViewInfo->View;
				m_pMatMVP[2] = &pViewInfo->Proj;
				
				m_pEffect->SetMatrixPointerArray(
					m_hIMVP,
					(const D3DXMATRIX**)m_pMatMVP, 3);
			}

			//-----------------------------------------------------------
			// Begin
			//-----------------------------------------------------------
			void ParticleShader::Begin()
			{
				m_pEffect->Begin(NULL, 0);
				m_pEffect->BeginPass(0);
			}

			//-----------------------------------------------------------
			// Eed
			//-----------------------------------------------------------
			void ParticleShader::Eed()
			{
				m_pEffect->EndPass();
				m_pEffect->End();
			}

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

