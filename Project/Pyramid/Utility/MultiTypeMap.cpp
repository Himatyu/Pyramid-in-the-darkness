/**
* @file		MultiTypeMap.cpp
* @brief	MultiTypeMapŽÀ‘•
* @author	S.OIKAWA
* @date		2016.09.12
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"MultiTypeMap.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	MultiTypeMap::~MultiTypeMap()
	{
		for (auto _ : m_Maps)
		{
			SAFE_DELETE(_);
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------