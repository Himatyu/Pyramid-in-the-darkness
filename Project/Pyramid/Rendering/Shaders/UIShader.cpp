/**
* @file		UIShader.cpp
* @brief	UI‚ÌShader
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UIShader.h"
#include"../Rendering/RenderProvider.h"
#include"../Rendering/Materials/UIMaterial.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Rendering::Materials;
namespace Pyramid
{
	namespace Rendering
	{
		namespace Shaders
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			UIShader::UIShader(Materials::UIMaterial* _pMat,::std::string _path):
				Shader(_path),
				m_pMaterial(_pMat)
			{
				m_hProjection = m_pEffect->GetParameterByName(NULL, "matP");
				m_hWorld = m_pEffect->GetParameterByName(NULL, "matM");
				m_hUV = m_pEffect->GetParameterByName(NULL, "UV");
				m_hDiffuse = m_pEffect->GetParameterByName(NULL, "Diffuse");
				m_hTexture = m_pEffect->GetParameterByName(NULL, "Texture");

			}

			//-----------------------------------------------------------
			// SetData
			//-----------------------------------------------------------
			void UIShader::SetData()
			{
				m_pEffect->SetValue(m_hUV, m_pMaterial->pArrayUV.data(), 16);
				m_pEffect->SetValue(m_hDiffuse, m_pMaterial->pColor->Array, 16);

				if (m_pMaterial->Texture == nullptr)
				{
					return;
				}
				m_pEffect->SetTexture(
					m_hTexture,
					m_pMaterial->Texture.spResourceFile->pTexture);
			}

			//-----------------------------------------------------------
			// SetMatrix
			//-----------------------------------------------------------
			void UIShader::SetMatrix()
			{
				auto& provider = 
					Rendering::RenderProvider::Instantiate().UI;

				m_pEffect->SetMatrix(
					m_hProjection, &provider.Projection);

				m_pEffect->SetMatrix(
					m_hWorld, m_pMatrix);
			}

			//-----------------------------------------------------------
			// Begin
			//-----------------------------------------------------------
			void UIShader::Begin()
			{
				m_pEffect->Begin(NULL, 0);
				m_pEffect->BeginPass(0);
			}

			//-----------------------------------------------------------
			// Eed
			//-----------------------------------------------------------
			void UIShader::Eed()
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