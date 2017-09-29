/**
* @file		Access.h
* @brief	Dtoとアクセサを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

namespace DataObject
{
	namespace DTO
	{
		/// <summary>
		/// Dtoに対するアクセサ
		/// </summary>
		template<class DTOType>
		class DTOAccess
		{
		public:
			PROPERTY_REF(m_Dto, Dto, DTOType);

		protected:
			DTOType			m_Dto;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------