/**
* @file		AABBToSphere.h
* @brief	AABBをSphereに変換する
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
				/// AABBToSphereコンバータ
				/// </summary>
				class AABBToSphere : 
					public IConverter
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					AABBToSphere();
					~AABBToSphere() = default;

					AABBToSphere(const AABBToSphere&) = default;
					AABBToSphere(AABBToSphere&&) = default;

					AABBToSphere& operator=(const AABBToSphere&) = default;
					AABBToSphere& operator=(AABBToSphere&&) = default;
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