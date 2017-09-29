/**
* @file		Constant.cpp
* @brief	ComponentsÇÃíËêîÇíËã`Ç∑ÇÈ
* @author	S.OIKAWA
* @date		2016.11.28
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Constant.h"
#include"Detail\Particle.h"
#include"Detail\Particle.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		const UINT Constant::CameraMTUpdataLineID = 1;
		const UINT Constant::TransformMTUpdataLineID = 2;
		const UINT Constant::ParticleMTUpdataLineID = 3;

		const std::string Constant::LightDifuseParameter = "LightDifuse";
		const std::string Constant::LightDirectParameter = "LightDir";

		const Utility::Vector3 Constant::ParticleGravity =
			Utility::Vector3(0.0f, -0.98f, 0.0f);

		const std::function<void(Detail::Particle&)>
			Constant::DefaultAdditionalInitialize = [](Detail::Particle& _)
		{

		};

		const std::function<void(Detail::Particle&)>
			Constant::DefaultAdditionalUpdata = [](Detail::Particle& _)
		{

		};

		const std::array<std::array<float, 4>, 12>
			Constant::EmissiveOfDebugCollisinVolume =
		{
			std::array<float, 4>{ 0.25f	,0.0f	,0.0f	,0.0f },
			std::array<float, 4>{ 0.0f	,0.25f	,0.0f	,0.0f },
			std::array<float, 4>{ 0.0f	,0.0f	,0.25f	,0.0f },

			std::array<float, 4>{ 0.5f	,0.0f	,0.0f	,0.0f },
			std::array<float, 4>{ 0.0f	,0.5f	,0.0f	,0.0f },
			std::array<float, 4>{ 0.0f	,0.0f	,0.5f	,0.0f },

			std::array<float, 4>{ 0.75f	,0.0f	,0.0f	,0.0f },
			std::array<float, 4>{ 0.0f	,0.75f	,0.0f	,0.0f },
			std::array<float, 4>{ 0.0f	,0.0f	,0.75f	,0.0f },

			std::array<float, 4>{ 1.0f	,0.0f	,0.0f	,0.0f },
			std::array<float, 4>{ 0.0f	,1.0f	,0.0f	,0.0f },
			std::array<float, 4>{ 0.0f	,0.0f	,1.0f	,0.0f }

		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------