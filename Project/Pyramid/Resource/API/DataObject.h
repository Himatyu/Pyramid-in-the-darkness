/**
* @file		DataObject.h
* @brief	DataObjectAPI
* @author	S.OIKAWA
* @date		2017.05.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IResourceAPI.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Resources
	{
		namespace API
		{
			/// <summary>
			/// DataObjectAPI
			/// </summary>
			template<class _Ty>
			class DataObject final:
				public IResourceAPI<_Ty>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				DataObject() = default;
				~DataObject() = default;

				DataObject(const DataObject&) = default;
				DataObject(DataObject&&) = default;

				DataObject& operator=(const DataObject&) = default;
				DataObject& operator=(DataObject&&) = default;
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
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------