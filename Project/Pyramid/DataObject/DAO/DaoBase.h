/**
	  * @file		DaoBase.h
	  * @brief		Entityの生成を行うベース関数を提供
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
		/// Entityを作成するベース関数と引数の型を提供する
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