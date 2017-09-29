/**
* @file		Access.h
* @brief	Dto�ƃA�N�Z�T���
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

namespace DataObject
{
	namespace DTO
	{
		/// <summary>
		/// Dto�ɑ΂���A�N�Z�T
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