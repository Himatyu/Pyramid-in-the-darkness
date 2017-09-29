/**
* @file		UIIncluder.h
* @brief	UIを使用するのに必要な機能をインクルードする
* @author	S.OIKAWA
* @date		207.06.07
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../UI/Constant.h"
#include"../UI/IUI.h"
#include"../UI/UITransform.h"

//-----------------------------------------------------------
// Event
//-----------------------------------------------------------
#include"../UI/Event/UIPublishSystem.h"

//-----------------------------------------------------------
// Listener
//-----------------------------------------------------------
#include"../UI/Event/Listener/Abstract.h"
#include"../UI/Event/Listener/Holder.h"
#include"../UI/Event/Listener/IUIChangeState.h"
#include"../UI/Event/Listener/IUICursor.h"

//-----------------------------------------------------------
// Event
//-----------------------------------------------------------
#include"../UI/Event/Publisher/Abstract.h"
#include"../UI/Event/Publisher/Base.h"
#include"../UI/Event/Publisher/UIChangeState.h"
#include"../UI/Event/Publisher/UICursor.h"

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------