/**
* @file		Constant.cpp
* @brief	MTÇÃíËêîÇíËã`Ç∑ÇÈ
* @author	S.OIKAWA
* @date		2016.11.28
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Constant.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		const UINT Constant::LightLimmit = 4;
		const std::string Constant::ParamNameMVP = "matMVP";
		const UINT Constant::StaticQuadPolygenCount = 2;
		const float Constant::DefaultRenderVolumeSize = 1.0f;

		const float Constant::DefaultThresholdOfHigh = 1000;


		const std::string Constant::ProgressiveMeshShaderPath =
			"Assets/Shaders/ProgressiveMesh.bsf";
		const std::string Constant::ParticleShaderPath = "Assets/Shaders/particle.bsf";
		const std::string Constant::BasicMeshShaderPath ="Assets/Shaders/BasicMesh.bsf";
		
		const std::string Constant::UIShaderPath= "Assets/Shaders/UI.bsf";


	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------