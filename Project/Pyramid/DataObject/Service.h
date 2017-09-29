/**
* @file		Service.h
* @brief	Entityを取得するインターフェースを提供
* @author	S.OIKAWA
* @date		2016.10.23
*/

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"singleton.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	/// <summary>
	/// Entityを生成するインターフェースを提供
	/// </summary>
	template<class Entity, class Dao>
	class Service final :
		public ::Utility::Singleton<Service<Entity,Dao>>
	{
	public:
		Entity Create(typename Dao::ParamType param);

	private:
		Dao m_Dao;
	};
#include"Service.inl"
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------