/**
* @file		Service.h
* @brief	Entity���擾����C���^�[�t�F�[�X���
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
	/// Entity�𐶐�����C���^�[�t�F�[�X���
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