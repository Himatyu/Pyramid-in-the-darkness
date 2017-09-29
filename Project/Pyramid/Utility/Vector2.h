/**
* @file		Vector2.h
* @brief	2Dベクタ
* @author	S.OIKAWA
* @date		2017.02.12
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
	/// 2Dベクタ
	/// </summary>
	class Vector2
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		Vector2();
		Vector2(float,float);

		~Vector2() = default;

		Vector2(const Vector2&) = default;
		Vector2(Vector2&&) = default;

		Vector2& operator=(const Vector2&) = default;
		Vector2& operator=(Vector2&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		/// <summary>
		/// 要素をセットする
		/// </summary>
		void Set(float _x, float _y);

		/// <summary>
		/// 長さを取得する
		/// </summary>
		float GetLength() const;

		/// <summary>
		/// 未二乗な長さを取得
		/// </summary>
		float GetLengthSquared() const;

		/// <summary>
		/// 長さを1にする
		/// </summary>
		void Normalize();

		/// <summary>
		/// ランダムなベクトルを取得
		/// </summary>
		static Vector2 Random();

		/// <summary>
		/// 指定範囲のランダムなベクトルを取得
		/// </summary>
		static Vector2 Random(float _Min, float _Max);

		/// <summary>
		/// 円状なランダムな点
		/// </summary>
		static Vector2 OnCircleRandom();

		/// <summary>
		/// 内積
		/// </summary>
		static float Dot(const Vector2& _lhv, const Vector2& _rhv);

		/// <summary>
		/// 外積
		/// </summary>
		static float Cross(const Vector2& _lhv, const Vector2& _rhv);

#pragma endregion
		//-----------------------------------------------------------
		// operator
		//-----------------------------------------------------------
		Vector2& operator += (const Vector2& _v);
		Vector2& operator += (float _v);
		Vector2& operator -= (const Vector2& _v);
		Vector2& operator -= (float _v);
		Vector2& operator *= (const Vector2& _v);
		Vector2& operator *= (float _v);
		Vector2& operator /= (const Vector2& _v);
		Vector2& operator /= (float _v);

		friend Vector2 operator + (const Vector2& _v1, const Vector2& _v2);
		friend Vector2 operator + (const Vector2& _v1, float _v2);
		friend Vector2 operator + (float _v1, const Vector2& _v2);
		friend Vector2 operator - (const Vector2& _v1, const Vector2& _v2);
		friend Vector2 operator - (const Vector2& _v1, float _v2);
		friend Vector2 operator - (float _v1, const Vector2& _v2);
		friend Vector2 operator * (const Vector2& _v1, const Vector2& _v2);
		friend Vector2 operator * (const Vector2& _v1, float _v2);
		friend Vector2 operator * (float _v1, const Vector2& _v2);
		friend Vector2 operator / (const Vector2& _v1, const Vector2& _v2);
		friend Vector2 operator / (const Vector2& _v1, float _v2);
		friend Vector2 operator / (float _v1, const Vector2& _v2);

		friend Vector2 operator - (const Vector2& _v1);

		bool operator == (const Vector2& _v) const;
		bool operator != (const Vector2& _v) const;

	public:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
		static const Vector2 zero;	  //Vector2(0, 0,)
		static const Vector2 once;	  //Vector2(1, 1,)
		static const Vector2 left;	  //Vector2(-1, 0)
		static const Vector2 rigth;	  //Vector2(1, 0,)
		static const Vector2 up;	  //Vector2(0, 1,)
		static const Vector2 down;	  //Vector2(0, -1,)
		
		float		X;
		float		Y;
#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------