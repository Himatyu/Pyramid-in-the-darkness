/**
* @file		ResourceType.h
* @brief	リソースのテンプレートをusingする
* @author	S.OIKAWA
* @date		2017.01.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"API/Audio.h"
#include"Audio/MCIAudioFile.h"

#include"API/Model.h"
#include"Model/FbxFile.h"

#include"API/Texture.h"
#include"Texture/DirectXTextureFile.h"
#include"Texture/DirectXTextureFileFromInMemory.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Resources
	{
		using AudioMCI = API::Audio<Audio::MCIAudioFile>;
		using ModelFBX = API::Model<Model::FbxFile>;
		using TextureDx = API::Texture<Texture::DirectXTextureFile>;
		using TextureDxInMem = API::Texture<Texture::DirectXTextureFileFromInMemory>;
	}
}
#pragma endregion

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------