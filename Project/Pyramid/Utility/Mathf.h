/**
* @file		Mathf.h
* @brief	���w�֘A�̏������܂Ƃ߂�
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
	/// ���w�֘A�̏���
	/// </summary>
	class Mathf
	{
	public:

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// �l�𐧌�����
		/// </summary>
		static float Clamp(float _target,float _min,float _max);

		/// <summary>
		/// 0~1�ɒl�𐧌�����
		/// </summary>
		static float Clamp01(float _target);

		/// <summary>
		/// ���`��Ԃ��s��
		/// </summary>
		static float Lerp(float _start,float _end,float _t);

		/// <summary>
		/// ���W�A���ϊ�
		/// </summary>
		static float ToRadian(float _degree);

		/// <summary>
		/// �f�O���ϊ�
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