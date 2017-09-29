/**
* @file		CameraLayer.h
* @brief
* @author
* @date
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Utility/Layer.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Rendering
	{
		/// <summary>
		/// �f�t�H���g�̃J�������C���[�̗�
		/// </summary>
		enum CameraLayerEnum : int
		{
			mainCamera = 0,
			subCamera = 1,
			cutInCamara = 2,
		};

		/// <summary>
		/// �f�t�H���g�̃J�������C���[
		/// </summary>
		using CameraLayer =
			Utility::Layer<CameraLayerEnum, 3>;
	}
}
#pragma endregion

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------