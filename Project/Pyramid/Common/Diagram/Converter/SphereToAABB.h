/**
* @file		SphereAndAABB.h
* @brief	SphereをAABBに変換する
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
				/// SphereAndAABBコンバータ
				/// </summary>
				class SphereToAABB :
					public IConverter
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					SphereToAABB();
					~SphereToAABB() = default;

					SphereToAABB(const SphereToAABB&) = default;
					SphereToAABB(SphereToAABB&&) = default;

					SphereToAABB& operator=(const SphereToAABB&) = default;
					SphereToAABB& operator=(SphereToAABB&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					/// <summary>
					/// SphereをAABBに変換する
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