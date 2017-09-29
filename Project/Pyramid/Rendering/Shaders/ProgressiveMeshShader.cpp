/**
* @file		ProgressiveMeshShader.cpp
* @brief	低レベル用のモデルを代替するビルボードのシェーダー
* @author	S.OIKAWA
* @date		2017.02.05
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ProgressiveMeshShader.h"
#include"../Constant.h"
#include"../RenderProvider.h"
#include"../Viewer.h"
#include"../Materials/ProgressiveMeshMaterial.h"
#pragma endregion

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
			ProgressiveMeshShader::ProgressiveMeshShader(
				Materials::ProgressiveMeshMaterial * _pMaterial):
				m_pMaterial(_pMaterial),
				Shader(Constant::ProgressiveMeshShaderPath),
				m_pMatMVP(new D3DXMATRIX*[4])
			{
				m_hIMVP = m_pEffect->GetParameterByName(NULL, "matIMVP");
				m_hUV = m_pEffect->GetParameterByName(NULL, "UV");
				m_hDiffuse = m_pEffect->GetParameterByName(NULL, "Diffuse");
				m_hTexDecal = m_pEffect->GetParameterByName(NULL, "texDecal");
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			ProgressiveMeshShader::~ProgressiveMeshShader()
			{
				SAFE_DELETE_ARRAY(m_pMatMVP);
			}

			//-----------------------------------------------------------
			// SetData
			//-----------------------------------------------------------
			void ProgressiveMeshShader::SetData()
			{
				m_pEffect->SetValue(m_hUV, m_pMaterial->ArrayUV.data(), 16);
				m_pEffect->SetTexture(
					m_hTexDecal,
					m_pMaterial->Texture.spResourceFile->pTexture);
				m_pEffect->SetValue(m_hDiffuse, m_pMaterial->OverlapColor.Array, 16);
			}

			//-----------------------------------------------------------
			// SetMatrix
			//-----------------------------------------------------------
			void ProgressiveMeshShader::SetMatrix()
			{
				auto& render = RenderProvider::Instantiate().Wolrd;
				auto pViewInfo = render.pCurrentViewer;

				D3DXMATRIX inv;
				D3DXMatrixInverse(&inv, 0, &pViewInfo->View);
				inv._41 = inv._42 = inv._43 = 0.0f;

				m_pMatMVP[0] = &inv;
				m_pMatMVP[1] = m_pMatrix;
				m_pMatMVP[2] = &pViewInfo->View;
				m_pMatMVP[3] = &pViewInfo->Proj;

				m_pEffect->SetMatrixPointerArray(
					m_hIMVP,
					(const D3DXMATRIX**)m_pMatMVP, 4);
			}

			//-----------------------------------------------------------
			// Begin
			//-----------------------------------------------------------
			void ProgressiveMeshShader::Begin()
			{
				m_pEffect->Begin(NULL, 0);
				m_pEffect->BeginPass(0);
			}

			//-----------------------------------------------------------
			// Eed
			//-----------------------------------------------------------
			void ProgressiveMeshShader::Eed()
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