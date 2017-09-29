/*
* @file		Shader.cpp
* @brief	シェーダ管理を管理する
* @author	S.OIKAWA
* @date		2016.11.2
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Shader.h"
#include"../Components/Transform.h"
#include"../Rendering/Graphics.h"
#include"../RenderProvider.h"
#include"../Constant.h"
#include<string>
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
			Shader::Shader(std::string filePath):
				m_FilePath(filePath)
			{
				auto pDevice = Graphics::Instantiate().Device;
				LPD3DXBUFFER pErr = NULL;
				if (FAILED(D3DXCreateEffectFromFile(pDevice, filePath.c_str(), NULL, NULL,
					true, NULL, &m_pEffect, &pErr)))
				{
					___THROW_EXCEPTION_POINT(
						::Utility::Exception,
						"コンパイル済みシェーダからEffectの作成に失敗 \n "+
						std::string((LPCTSTR)pErr->GetBufferPointer()));
				}

				m_hMVP = m_pEffect->GetParameterByName(NULL, Constant::ParamNameMVP.c_str());

			}

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Shader::Shader(const Shader & _other):
				Shader(_other.m_FilePath)
			{
				m_pMatrix = _other.m_pMatrix;
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			Shader::~Shader()
			{
				SAFE_RELEASE(m_pEffect);
			}


			//-----------------------------------------------------------
			// SetMatrix
			//-----------------------------------------------------------
			void Shader::SetMatrix()
			{
				auto& render = RenderProvider::Instantiate().Wolrd;
				auto pViewInfo = render.pCurrentViewer; 

				D3DXMATRIX pMatMVP[3];
				pMatMVP[0] = *m_pMatrix;
				pMatMVP[1] = pViewInfo->View;
				pMatMVP[2] = pViewInfo->Proj;

				m_pEffect->SetMatrixArray(m_hMVP, pMatMVP, 3);
			}

			//-----------------------------------------------------------
			// SetLight
			//-----------------------------------------------------------
			void Shader::SetLight()
			{
				RenderProvider::Instantiate().Wolrd.SetLights(this);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------