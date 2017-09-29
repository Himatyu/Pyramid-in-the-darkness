/**
* @file		DateType.h
* @brief		データの読み書きするための方を定義する
* @author		S.OIKAWA
* @date		2016.10.15
*/

#pragma once

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	/// <summary>
	/// 単精度少数を2つの値を保持する.
	/// </summary>
	struct float2
	{
		PROPERTY(Value[0], x, float);
		PROPERTY(Value[1], y,float);
		float Value[2];
	};

	/// <summary>
	/// 単精度少数を3つの値を保持する.
	/// </summary>
	struct float3
	{
		PROPERTY(Value[0], x, float);
		PROPERTY(Value[1], y, float);
		PROPERTY(Value[2], z, float);
		float Value[3];
	};

	/// <summary>
	/// 単精度少数を4つの値を保持する.
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
