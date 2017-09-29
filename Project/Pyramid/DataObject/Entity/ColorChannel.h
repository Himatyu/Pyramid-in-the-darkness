/**
* @file		ColorChannel.h
* @brief	�J���[�`�����l��Entity���
* @author	S.OIKAWA
* @date		2016.10.15
*/

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../DTO/DTOAccess.h"
#include"../DTO/ColorChannel.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Entity
	{
		/// <summary>
		/// F�}�e���A���Ɏg�p�����J���[�`�����l��
		/// </summary>
		class ColorChannel final :
			public DTO::DTOAccess<DTO::ColorChannel>
		{
			D3DCOLORVALUE ToColorValue() {}
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------