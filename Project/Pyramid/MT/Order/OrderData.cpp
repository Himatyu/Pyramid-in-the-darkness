/**
* @file		OrderData.cpp
* @brief	ñΩóﬂèÓïÒÇìZÇﬂÇÈ
* @author	S.OIKAWA
* @date		2016.09.24
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OrderData.h"
#include"IExecuteable.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{
		namespace Order
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			OrderData::OrderData(
				Utility::IExecuteable * _pJob,
				std::string		_group,
				u_int			_lineID
			) :
				m_pJob(_pJob),
				m_group(_group),
				m_lineID(_lineID)
			{
			}

			//-----------------------------------------------------------
			// operator==
			//-----------------------------------------------------------
			bool OrderData::operator==(const OrderData & lhs)
			{
				return (m_pJob == lhs.pJob && m_group ==
					lhs.Group && m_lineID == lhs.LineID);
			}

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
