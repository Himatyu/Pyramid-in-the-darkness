/**
* @file		MeshShader.cpp
* @brief	fbxモデルを描画するシェーダ管理
* @author	S.OIKAWA
* @date		2016.11.2
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"MeshShader.h"
#include"../Materials/ColorChannel.h"
#include"../Materials/MeshMaterial.h"
#include"../Constant.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace 
{
	constexpr size_t offsetColorCount = 4;
	constexpr size_t offsetByteByColor = sizeof(float) * offsetColorCount;
	enum  offsetByChunk : size_t
	{
		Emissive	= 0,
		Ambient		= 1 * offsetColorCount,
		Diffuse		= 2 * offsetColorCount,
		Specular	= 3 * offsetColorCount,
		Bump		= 4 * offsetColorCount,

		Shinness	= 5 * offsetColorCount ,
		Transparency= 5 * offsetColorCount + 1,
		Reflectivity= 5 * offsetColorCount + 2,

	};

	void CopyByFourChunk(
		std::array<float, 23>& _dst, 
		Pyramid::Rendering::Materials::ColorChannel& _src,
		offsetByChunk _offset
	)
	{
		std::memcpy(_dst.data()+ _offset, _src.Value.data(), offsetByteByColor);
	}

	void CopyByFourFloat(
		std::array<float, 23>& _dst,
		float& _src,
		offsetByChunk _offset
	)
	{
		std::memcpy(_dst.data() + _offset, &_src, sizeof(float));
	}
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
			MeshShader::MeshShader(
				Materials::MeshMaterial* _pMaterial, std::string _path):
				Shader(_path),
				m_pMaterial(_pMaterial)
			{
				InitHandele();
			}


			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			MeshShader::MeshShader(const MeshShader & _other):
				Shader(m_FilePath),
				m_pMaterial(_other.m_pMaterial)
			{
				InitHandele();
			}
			
			//-----------------------------------------------------------
			// SetColorFromMaterial
			//-----------------------------------------------------------
			void MeshShader::SetColorFromMaterial()
			{
				CopyByFourChunk(m_ColorChunk, m_pMaterial->Emissive, offsetByChunk::Emissive);
				CopyByFourChunk(m_ColorChunk, m_pMaterial->Ambient, offsetByChunk::Ambient);
				CopyByFourChunk(m_ColorChunk, m_pMaterial->Diffuse, offsetByChunk::Diffuse);
				CopyByFourChunk(m_ColorChunk, m_pMaterial->Specular, offsetByChunk::Specular);
				CopyByFourChunk(m_ColorChunk, m_pMaterial->Bump, offsetByChunk::Bump);

				CopyByFourFloat(m_ColorChunk, m_pMaterial->Shinness, offsetByChunk::Shinness);
				CopyByFourFloat(m_ColorChunk, m_pMaterial->Transparency, offsetByChunk::Transparency);
				CopyByFourFloat(m_ColorChunk, m_pMaterial->Reflectivity, offsetByChunk::Reflectivity);

				m_pEffect->SetFloatArray(m_hColorChunk, m_ColorChunk.data(), 23);

			}

			//-----------------------------------------------------------
			// SetTextureFromMaterial
			//-----------------------------------------------------------
			void MeshShader::SetTextureFromMaterial()
			{
				auto pEmissiveTex = m_pMaterial->Emissive.GetTexture(
					m_pMaterial->Emissive.UseTextureIndex);
				m_pEffect->SetTexture(m_hTexEmissive, pEmissiveTex);

				auto pDiffuseTex = m_pMaterial->Diffuse.GetTexture(
					m_pMaterial->Diffuse.UseTextureIndex);					
				m_pEffect->SetTexture(m_hTexDiffuse, pDiffuseTex);

				auto pSpecularTex = m_pMaterial->Specular.GetTexture(
					m_pMaterial->Specular.UseTextureIndex);
				m_pEffect->SetTexture(m_hTexSpecular, pSpecularTex);

				auto pBumpTex = m_pMaterial->Bump.GetTexture(
					m_pMaterial->Bump.UseTextureIndex);
				m_pEffect->SetTexture(m_hTexBump, pBumpTex);
			}

			//-----------------------------------------------------------
			// Begin
			//-----------------------------------------------------------
			void MeshShader::Begin()
			{
				m_pEffect->Begin(NULL, 0);
				m_pEffect->BeginPass(0);
			}

			//-----------------------------------------------------------
			// End
			//-----------------------------------------------------------
			void MeshShader::Eed()
			{
				m_pEffect->EndPass();
				m_pEffect->End();
			}


			//-----------------------------------------------------------
			// InitHandele
			//-----------------------------------------------------------
			void MeshShader::InitHandele()
			{
				m_hColorChunk = m_pEffect->GetParameterByName(NULL, "ColorChunk");
				m_hTexDiffuse = m_pEffect->GetParameterByName(NULL, "texDiffuse");
				m_hTexEmissive = m_pEffect->GetParameterByName(NULL, "texEmissive");
				m_hTexSpecular = m_pEffect->GetParameterByName(NULL, "texSpecular");
				m_hTexBump = m_pEffect->GetParameterByName(NULL, "texBump");
			}
		}
	}
}

///-----------------------------------------------------------
// EOF
//-----------------------------------------------------------