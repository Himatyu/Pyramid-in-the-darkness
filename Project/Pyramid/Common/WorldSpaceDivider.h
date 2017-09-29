/**
* @file		WorldSpaceDivider.h
* @brief	ÉQÅ[ÉÄì‡ÇÃóBàÍãÛä‘Çï™äÑÇ∑ÇÈ
* @author	S.OIKAWA
* @date		2017.01.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SpaceDivide\Octree.h"
#include"singleton.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion


namespace Pyramid
{
	namespace Common
	{
		/// <summary>
		/// ÉQÅ[ÉÄì‡ÇÃóBàÍãÛä‘Çï™äÑÇ∑ÇÈ
		/// </summary>
		class WorldSpaceDivider :
			public SpaceDivide::Octree,
			public Utility::Singleton<WorldSpaceDivider>
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			WorldSpaceDivider() = default;
			~WorldSpaceDivider() = default;

			WorldSpaceDivider(const WorldSpaceDivider&) = default;
			WorldSpaceDivider(WorldSpaceDivider&&) = default;

			WorldSpaceDivider& operator=(const WorldSpaceDivider&) = default;
			WorldSpaceDivider& operator=(WorldSpaceDivider&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------