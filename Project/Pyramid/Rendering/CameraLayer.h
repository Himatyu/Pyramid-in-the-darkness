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
		/// デフォルトのカメラレイヤーの列挙
		/// </summary>
		enum CameraLayerEnum : int
		{
			mainCamera = 0,
			subCamera = 1,
			cutInCamara = 2,
		};

		/// <summary>
		/// デフォルトのカメラレイヤー
		/// </summary>
		using CameraLayer =
			Utility::Layer<CameraLayerEnum, 3>;
	}
}
#pragma endregion

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------