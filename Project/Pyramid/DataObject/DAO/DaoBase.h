/**
	  * @file		DaoBase.h
	  * @brief		Entity�̐������s���x�[�X�֐����
	  * @author		S.OIKAWA
	  * @date		2016.10.23
	  */

#pragma once

	  //-----------------------------------------------------------
	  // define 
	  //-----------------------------------------------------------
namespace DataObject
{
	namespace DAO
	{
		/// <summary>
		/// Entity���쐬����x�[�X�֐��ƈ����̌^��񋟂���
		/// </summary>
		template<class Param, class Entity>
		class DaoBase
		{
		public:
			using ParamType = Param;
			virtual Entity From(ParamType param) = 0 {}
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------