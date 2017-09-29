/**
* @file		IDeserializable.h
* @brief		�������݂̃C���^�[�t�F�[�X���
* @author		S.OIKAWA
* @date		2016.10.15
*/

#pragma once

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Deserialize
	{
		/// <summary>
		/// �������݃C���^�[�t�F�[�X
		/// </summary>
		__interface IDeserializable
		{
			void Deserialize();
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------