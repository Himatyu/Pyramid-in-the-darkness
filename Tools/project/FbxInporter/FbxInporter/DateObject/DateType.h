/**
	  * @file		DateType.h
	  * @brief		�f�[�^�̓ǂݏ������邽�߂̕����`����
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */

#pragma once
#include"../Macro.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	/// /// <summary>
	/// �P���x������2�̒l��ێ�����.
	/// </summary>
	struct float2
	{
		PROPERTY(Value[0], x, float);
		PROPERTY(Value[1], y,float);
		float Value[2];
	};

	/// <summary>
	/// �P���x������3�̒l��ێ�����.
	/// </summary>
	struct float3
	{
		PROPERTY(Value[0], x, float);
		PROPERTY(Value[1], y, float);
		PROPERTY(Value[2], z, float);
		float Value[3];
	};

	/// <summary>
	/// �P���x������4�̒l��ێ�����.
	/// </summary>
	struct float4
	{
		PROPERTY(Value[0], x, float);
		PROPERTY(Value[1], y, float);
		PROPERTY(Value[2], z, float);
		PROPERTY(Value[3], w, float);
		float Value[4];
	};

}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
