/**
* @file		TypePossession.cpp
* @brief	型情報を所持する
* @author	S.OIKAWA
* @date		2016.09.28
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TypePossession.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	TypePossession::TypePossession()
	{
	}

	//-----------------------------------------------------------
	// OnApply
	//-----------------------------------------------------------
	void TypePossession::OnApply()
	{
	}

	//-----------------------------------------------------------
	// AccessOfIndex
	//-----------------------------------------------------------
	Utility::Nullable<std::type_index*>
	TypePossession::AccessOfIndex(unsigned _index)
	{
		if (!m_Types.size() || _index > m_Types.size())
		{
			return {};
		}
		return Utility::Nullable<std::type_index*>(&m_Types[_index]);
	}
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------