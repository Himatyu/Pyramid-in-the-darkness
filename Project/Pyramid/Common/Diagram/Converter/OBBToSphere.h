/**
* @file		OBBAndSphere.h
* @brief	OBBをAABBに変換する
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
				/// OBBAndSphereコンバータ
				/// </summary>
				class OBBToSphere :
					public IConverter
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					OBBToSphere();
					~OBBToSphere() = default;

					OBBToSphere(const OBBToSphere&) = default;
					OBBToSphere(OBBToSphere&&) = default;

					OBBToSphere& operator=(const OBBToSphere&) = default;
					OBBToSphere& operator=(OBBToSphere&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					/// <summary>
					/// OBBをSphereに変換する
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