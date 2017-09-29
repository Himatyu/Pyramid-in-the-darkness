/**
* @file		CollisionIncluder.h
* @brief	Collision群をインクルードする
* @author	S.OIKAWA
* @date		2017.03.05
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Collision/CollisionDetection.h"
#include"../Collision/Constant.h"
#include"../Collision/HitResult.h"
#include"../Collision/IVolume.h"
#include"../Collision/Volume.h"

//-----------------------------------------------------------
// Detail
//-----------------------------------------------------------
#include"../Collision/Detail/CacheableTransform.h"
#include"../Collision/Detail/ColliderManager.h"
#include"../Collision/Detail/CollisionEventListener.h"
#include"../Collision/Detail/CollisionInformation.h"
#include"../Collision/Detail/CollisionProvider.h"
#include"../Collision/Detail/CollisionSystem.h"
#include"../Collision/Detail/Defines.h"
#include"../Collision/Detail/DelayEvent.h"
#include"../Collision/Detail/FindResult.h"
#include"../Collision/Detail/HitEventPublisher.h"
#include"../Collision/Detail/ICollidee.h"
#include"../Collision/Detail/JudgmentSameSpaceOfCollidee.h"
#include"../Collision/Volume.h"

//-----------------------------------------------------------
// Collider
//-----------------------------------------------------------
#include"../Collision/Detail/Collider/AABBAndAABB.h"
#include"../Collision/Detail/Collider/AABBAndOBB.h"
#include"../Collision/Detail/Collider/ICollider.h"
#include"../Collision/Detail/Collider/IDiagramCollider.h"
#include"../Collision/Detail/Collider/OBBAndOBB.h"
#include"../Collision/Detail/Collider/OBBAndSphere.h"
#include"../Collision/Detail/Collider/SphereAndAABB.h"
#include"../Collision/Detail/Collider/SphereAndSphere.h"

//-----------------------------------------------------------
// Tester
//-----------------------------------------------------------
#include"../Collision/Detail/Tester/ITester.h"
#include"../Collision/Detail/Tester/TesterOfDiscreet.h"
#include"../Collision/Detail/Tester/TesterOfSVT.h"

#pragma endregion




//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------