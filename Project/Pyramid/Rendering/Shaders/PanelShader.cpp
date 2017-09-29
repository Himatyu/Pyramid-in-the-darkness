/**
* @file		PanelShader.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"PanelShader.h"
#include"../Materials/PanelMaterial.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace 
{
	const std::string shaderFilePath("Assets/Shaders/Panel.bsf");
}

namespace Pyramid
{
	namespace Rendering
	{
		namespace Shaders
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			PanelShader::PanelShader(Materials::PanelMaterial * _pMat) :
				m_pMaterial(_pMat),
				Shader(shaderFilePath)
			{
				m_hDiffuse = m_pEffect->GetParameterByName(NULL, "Diffuse");
				m_hTexture = m_pEffect->GetParameterByName(NULL, "texDiffuse");
			}

			//-----------------------------------------------------------
			// Begin
			//-----------------------------------------------------------
			void PanelShader::Begin()
			{
				m_pEffect->Begin(NULL, 0);
				m_pEffect->BeginPass(0);
			}

			//-----------------------------------------------------------
			// Eed
			//-----------------------------------------------------------
			void PanelShader::Eed()
			{
				m_pEffect->EndPass();
				m_pEffect->End();
			}

			//-----------------------------------------------------------
			// PushDate
			//-----------------------------------------------------------
			void PanelShader::PushDate()
			{
				m_pEffect->SetFloatArray(m_hDiffuse,m_pMaterial->Diffuse.Array,4);
				m_pEffect->SetTexture(m_hTexture, m_pMaterial->pTexture);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------