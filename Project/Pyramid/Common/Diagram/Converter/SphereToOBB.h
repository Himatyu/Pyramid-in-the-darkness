/**
* @file		SphereToOBB.h
* @brief	SphereをOBBに変換する
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
				/// SphereToOBBコンバータ
				/// </summary>
				class SphereToOBB :
					public IConverter
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					SphereToOBB();
					~SphereToOBB() = default;

					SphereToOBB(const SphereToOBB&) = default;
					SphereToOBB(SphereToOBB&&) = default;

					SphereToOBB& operator=(const SphereToOBB&) = default;
					SphereToOBB& operator=(SphereToOBB&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					/// <summary>
					/// SphereをOBBに変換する
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