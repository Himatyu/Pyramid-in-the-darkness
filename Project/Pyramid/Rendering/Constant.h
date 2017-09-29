/**
* @file		Constant.h
* @brief	RenderingÇÃíËêîÇíËã`Ç∑ÇÈ
* @author	S.OIKAWA
* @date		2016.11.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<windef.h>
#include<string>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		class Constant final
		{
		public:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
			static const UINT LightLimmit;
			static const std::string ParamNameMVP;
			static const UINT StaticQuadPolygenCount;
			static const float DefaultRenderVolumeSize;

			static const float DefaultThresholdOfHigh;

			static const std::string ProgressiveMeshShaderPath;
			static const std::string ParticleShaderPath;
			static const std::string BasicMeshShaderPath;
			static const std::string UIShaderPath;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------