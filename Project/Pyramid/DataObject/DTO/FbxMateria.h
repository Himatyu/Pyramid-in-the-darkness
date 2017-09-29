/**
* @file		FbxMaterial.h
* @brief	FBX‚Ìƒ}ƒeƒŠƒAƒ‹Dto’ñ‹Ÿ
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

//-----------------------------------------------------------
// icnlude 
//-----------------------------------------------------------
#include"ColorChannel.h"
#include<vector>
#include<fstream>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace DTO
	{
		/// <summary>
		/// FbxMaterial‚ÌDTO
		/// </summary>
		class FbxMaterial final
		{
		public:
			PROPERTY_REF(m_Emissive, Emissive, ColorChannel);
			PROPERTY_REF(m_Ambient, Ambient, ColorChannel);
			PROPERTY_REF(m_Diffuse, Diffuse, ColorChannel);
			PROPERTY_REF(m_Specular, Specular, ColorChannel);
			PROPERTY_REF(m_Bump, Bump, ColorChannel);

			PROPERTY_REF(m_Shinness, Shinness, float);
			PROPERTY_REF(m_Transparency, Transparency, float);
			PROPERTY_REF(m_Reflectivity, Reflectivity, float);

		private:
			ColorChannel m_Emissive;
			ColorChannel m_Ambient;
			ColorChannel m_Diffuse;
			ColorChannel m_Specular;
			ColorChannel m_Bump;

			float m_Shinness = 1.0;
			float m_Transparency = 1.0;
			float m_Reflectivity = 0.0;
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
