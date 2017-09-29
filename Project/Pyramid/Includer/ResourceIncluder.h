/**
* @file		ResourceIncluder.h
* @brief	リソースクラス群をインクルードする
* @author	S.OIKAWA
* @date		2016.09.12
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Resource/IResource.h"
#include"../Resource/ResourceManager.h"
#include"../Resource/ResourceType.h"
#include"../Resource/Constant.h"

#include"../Resource/API/IResourceAPI.h"
#include"../Resource/API/LostResourceAPI.h"
#include"../Resource/API/Audio.h"
#include"../Resource/API/Model.h"
#include"../Resource/API/Texture.h"

#include"../Resource/Audio/IAudioFile.h"
#include"../Resource/Audio/MCIAudioFile.h"

#include"../Resource/Model/IModelFile.h"
#include"../Resource/Model/FbxFile.h"

#include"../Resource/Texture/ITextureFile.h"
#include"../Resource/Texture/DirectXTextureFile.h"
#include"../Resource/Texture/DirectXTextureFileFromInMemory.h"


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------