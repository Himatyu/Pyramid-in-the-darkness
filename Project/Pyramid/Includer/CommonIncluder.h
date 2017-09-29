/**
* @file		CommonIncluder.h
* @brief	共通機能のインクルーダー
* @author	S.OIKAWA
* @date		2017.01.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Common/Constant.h"
#include"../Common/Defines.h"

#include"../Common/TextureAnimFream.h"
#include"../Common/TextureAnimUV.h"
#include"../Common/Timer.h"
#include"../Common/TimerServer.h"
#include"../Common/WorldSpaceDivider.h"
#include"../Common/WorldVolume.h"

//-----------------------------------------------------------
// SpaceDivide
//-----------------------------------------------------------
#include"../Common/SpaceDivide/Cell.h"
#include"../Common/SpaceDivide/Octree.h"
#include"../Common/SpaceDivide/OctreeRegistrableObject.h"

//-----------------------------------------------------------
// Diagram
//-----------------------------------------------------------
#include"../Common/Diagram/AABB.h"
#include"../Common/Diagram/Constant.h"
#include"../Common/Diagram/Plane.h"
#include"../Common/Diagram/OBB.h"
#include"../Common/Diagram/Sphere.h"

#include"../Common/Diagram/Converter/AABBToOBB.h"
#include"../Common/Diagram/Converter/AABBToSphere.h"
#include"../Common/Diagram/Converter/ConvertProvider.h"
#include"../Common/Diagram/Converter/IConverter.h"
#include"../Common/Diagram/Converter/OBBToAABB.h"
#include"../Common/Diagram/Converter/OBBToSphere.h"
#include"../Common/Diagram/Converter/SphereToAABB.h"
#include"../Common/Diagram/Converter/SphereToOBB.h"

//-----------------------------------------------------------
// InputDevice
//-----------------------------------------------------------
#include"../Common/InputDevice/Constant.h"
#include"../Common/InputDevice/DeviceManager.h"
#include"../Common/InputDevice/Key.h"
#include"../Common/InputDevice/Mouse.h"

//-----------------------------------------------------------
// Policy
//-----------------------------------------------------------
#include"../Common/Policy/DirectXCreate.h"
#include"../Common/Policy/DirectXDelete.h"
#include"../Common/Policy/NonCreate.h"
#include"../Common/Policy/NonDelete.h"
#include"../Common/Policy/StdCreate.h"
#include"../Common/Policy/StdDelete.h"

#pragma endregion

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------