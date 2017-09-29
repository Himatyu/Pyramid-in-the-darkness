/**
* @file		MeshMaterial.h
* @brief	メッシュのレンダリングに必要な情報を持つ
* @author	S.OIKAWA
* @date		2016.11.22
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include<string>
#include "Material.h"
#include"../Shaders/MeshShader.h"
#include"ColorChannel.h"
//-----------------------------------------------------------
// define			
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		class Transform;
	}

	namespace Rendering
	{
		namespace Materials
		{
			/// <summary>
			/// メッシュのレンダリングに必要な情報を持つ
			/// </summary>
			class MeshMaterial final :
				public Material
			{
			public:
				//-----------------------------------------------------------
				// ctor,dtor
				//-----------------------------------------------------------
				MeshMaterial(std::string _OpaquePath, std::string _TransparentPath);
				virtual ~MeshMaterial();

				MeshMaterial(const MeshMaterial&);
				MeshMaterial(MeshMaterial&&) = default;

				MeshMaterial&operator=(const MeshMaterial&) = default;
				MeshMaterial&operator=(MeshMaterial&&) = default;
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void SetMateral() override;
				virtual void RiseMateral() override;
				virtual void SetMatrix(D3DXMATRIX&) override;
				
				//-----------------------------------------------------------
				// propertys
				//-----------------------------------------------------------
				PROPERTY_REF(m_Emissive, Emissive, ColorChannel);
				PROPERTY_REF(m_Ambient, Ambient, ColorChannel);
				PROPERTY_REF(m_Diffuse, Diffuse, ColorChannel);
				PROPERTY_REF(m_Specular, Specular, ColorChannel);
				PROPERTY_REF(m_Bump, Bump, ColorChannel);

				PROPERTY_REF(m_Shinness, Shinness, float);
				PROPERTY_REF(m_Transparency, Transparency, float);
				PROPERTY_REF(m_Reflectivity, Reflectivity, float);

				PROPERTY_REF(m_OpaqueShader, Shader, Shaders::MeshShader);
				
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				ColorChannel m_Emissive;
				ColorChannel m_Ambient;
				ColorChannel m_Diffuse;
				ColorChannel m_Specular;
				ColorChannel m_Bump;

				float m_Shinness = 1.0;
				float m_Transparency = 1.0;
				float m_Reflectivity = 0.0;

				Shaders::MeshShader m_OpaqueShader;
				Shaders::MeshShader m_TransparentShader;
				Shaders::MeshShader* m_pActiveShader;
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
