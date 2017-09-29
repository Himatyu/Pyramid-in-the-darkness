/**
* @file		AABBAndOBB.h
* @brief	AABBをOBBに変換する
* @author	S.OIKAWA
* @date		2017.05.01
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IConverter.h"

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
		namespace Diagram
		{
			namespace Converter
			{
				/// <summary>
				/// AABBAndOBBコンバータ
				/// </summary>
				class AABBToOBB : 
					public IConverter
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					AABBToOBB();
					~AABBToOBB() = default;

					AABBToOBB(const AABBToOBB&) = default;
					AABBToOBB(AABBToOBB&&) = default;

					AABBToOBB& operator=(const AABBToOBB&) = default;
					AABBToOBB& operator=(AABBToOBB&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// AABBをOBBに変換する
					/// </summary>
					std::shared_ptr<IDiagram> Convert(IDiagram*)override;
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
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------