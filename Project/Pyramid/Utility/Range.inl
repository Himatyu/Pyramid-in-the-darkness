/**
* @file		Range.inl
* @brief	”ÍˆÍ‚ð’è‹`‚·‚é
* @author	S.OIKAWA
* @date		2016.12.13
*/

#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Range.h"

template<class Ty>
float Range<Ty>::Epsilon = 0;

//-----------------------------------------------------------
// ctor
//-----------------------------------------------------------
template<class Ty>
inline Range<Ty>::Range(Ty _mim, Ty _max) :
	m_Min(_mim),
	m_Max(_max)
{
}

//-----------------------------------------------------------
// IsContains
//-----------------------------------------------------------
template<class Ty>
inline const bool Range<Ty>::IsContains(const Ty _val)
{
	return (m_Min <= _val && _val <= m_Max);
}

//-----------------------------------------------------------
// ==
//-----------------------------------------------------------
template<class Ty>
inline bool Utility::Range<Ty>::operator==(const Range & _range)
{
	return (Epsilon>=(_range.Min - m_Min)) && (Epsilon >= (_range.Max - m_Max));
}

//-----------------------------------------------------------
// !=
//-----------------------------------------------------------
template<class Ty>
inline bool Utility::Range<Ty>::operator!=(const Range &_range)
{
	return (Epsilon <= (_range.Min - m_Min)) || (Epsilon <= (_range.Max - m_Max));
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------