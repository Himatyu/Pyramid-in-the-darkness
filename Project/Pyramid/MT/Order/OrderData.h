/**
* @file		OrderData.h
* @brief	ñΩóﬂèÓïÒÇìZÇﬂÇÈ
* @author	S.OIKAWA
* @date		2016.09.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>
#include"IExecuteable.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{
		namespace Order
		{
#pragma endregion

			/// <summary>
			/// ñΩóﬂèÓïÒÇìZÇﬂÇÈ
			/// </summary>
			class OrderData final
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				OrderData() = default;
				OrderData(Utility::IExecuteable*, std::string, u_int);
				~OrderData() = default;

				OrderData(const OrderData&) = default;
				OrderData(OrderData&&) = default;

				OrderData& operator=(const OrderData&) = default;
				OrderData& operator=(OrderData&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ìØàÍî‰är
				/// </summary>
				bool operator==(const OrderData& lhs);
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY(m_pJob, pJob, Utility::IExecuteable*);
				PROPERTY(m_group, Group, std::string);
				PROPERTY(m_lineID, LineID, u_int);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				Utility::IExecuteable*		m_pJob;
				std::string					m_group;
				u_int						m_lineID;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------