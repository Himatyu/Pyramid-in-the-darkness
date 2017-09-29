/**
* @file		AsyncLoadLevel.inl
* @brief	”ñ“¯Šú‚ÌƒŒƒxƒ‹“Ç‚İ‚İ‚ğ’ñ‹Ÿ
* @author	S.OIKAWA
* @date		2016.10.08
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"AsyncLoadLevel.h"
#include"../Blueprint/Creators/LevelCreator.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

//-----------------------------------------------------------
// LoadRequest
//-----------------------------------------------------------
template<class Lv>
inline void AsyncLoadLevel::LoadRequest()
{
	m_IsInterruptionMutex.lock();
	m_IsInterruption = false;
	m_IsInterruptionMutex.unlock();

	auto pCreater = new Blueprint::Creators::LevelCreator<Lv>();
	std::type_index typeId = typeid(Lv);
	auto date = std::make_pair(pCreater, typeId);

	m_LevelLoadRequestListMutex.lock();
	m_LevelLoadRequestList.push_back(date);
	m_LevelLoadRequestListMutex.unlock();
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------