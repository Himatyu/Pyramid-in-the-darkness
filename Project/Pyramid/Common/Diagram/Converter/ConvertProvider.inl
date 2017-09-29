/**
* @file		ConvertProvider.inl
* @brief	コンバータを提供する
* @author	S.OIKAWA
* @date		2017.04.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ConvertProvider.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

//-----------------------------------------------------------
// Convert
//-----------------------------------------------------------
template<class Ty, class Result>
inline 
Utility::Nullable<Result> ConvertProvider::Convert(Ty & _ty)
{
	Utility::TypeComparable converterType;
	converterType.TypeApply<Ty, Result>();
	for (auto _ : m_Converters)
	{
		if (*_ == converterType)
		{
			auto converted = _->Convert(&_ty);
			return 
				Utility::Nullable<Result>(*(static_cast<Result*>(converted.get())));
		}
	}
	return {};
}
			
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------