/**
* @file		IConverter.h
* @brief	抽象コンバータ
* @author	S.OIKAWA
* @date		2017.04.29
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICastable.h"
#include"TypeComparable.h"
#include<memory>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{
			class IDiagram;
		}
	}
}
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
				/// 抽象コンバータ
				/// </summary>
				class IConverter : 
					public Utility::ICastable,
					public Utility::TypeComparable
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					IConverter() = default;
					~IConverter() = default;

					IConverter(const IConverter&) = default;
					IConverter(IConverter&&) = default;

					IConverter& operator=(const IConverter&) = default;
					IConverter& operator=(IConverter&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					/// <summary>
					/// キャストするのでポインタ
					/// </summary>
					virtual std::shared_ptr<IDiagram> Convert(IDiagram*) = 0;
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