/**
* @file		Mathf.h
* @brief	数学関連の処理をまとめる
* @author	S.OIKAWA
* @date		201.02.13
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Utility
{
	/// <summary>
	/// 数学関連の処理
	/// </summary>
	class Mathf
	{
	public:

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// 値を制限する
		/// </summary>
		static float Clamp(float _target,float _min,float _max);

		/// <summary>
		/// 0~1に値を制限する
		/// </summary>
		static float Clamp01(float _target);

		/// <summary>
		/// 線形補間を行う
		/// </summary>
		static float Lerp(float _start,float _end,float _t);

		/// <summary>
		/// ラジアン変換
		/// </summary>
		static float ToRadian(float _degree);

		/// <summary>
		/// デグリ変換
		/// </summary>
		static float ToDegree(float _radian);

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
		static const float	PI ;
#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------