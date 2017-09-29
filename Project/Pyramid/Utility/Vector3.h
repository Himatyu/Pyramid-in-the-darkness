/**
* @file		Vector3.h
* @brief	 ベクタ
* @author	S.OIKAWA
* @date		2016.05.08
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3dx9.h>
#include<utility>
#include"IStringConvertible.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	class Vector3 :
		public IStringConvertible<Vector3>
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
		Vector3();
		Vector3(float _x, float _y, float _z);
		Vector3(const D3DXVECTOR3& _vec);
		~Vector3();

		//-----------------------------------------------------------
		// operator
		//-----------------------------------------------------------
		Vector3& operator += (const Vector3& _v);
		Vector3& operator += (float _v);
		Vector3& operator -= (const Vector3& _v);
		Vector3& operator -= (float _v);
		Vector3& operator *= (const Vector3& _v);
		Vector3& operator *= (float _v);
		Vector3& operator /= (const Vector3& _v);
		Vector3& operator /= (float _v);

		friend Vector3 operator + (const Vector3& _v1, const Vector3& _v2);
		friend Vector3 operator + (const Vector3& _v1, float _v2);
		friend Vector3 operator + (float _v1, const Vector3& _v2);
		friend Vector3 operator - (const Vector3& _v1, const Vector3& _v2);
		friend Vector3 operator - (const Vector3& _v1, float _v2);
		friend Vector3 operator - (float _v1, const Vector3& _v2);
		friend Vector3 operator * (const Vector3& _v1, const Vector3& _v2);
		friend Vector3 operator * (const Vector3& _v1, float _v2);
		friend Vector3 operator * (float _v1, const Vector3& _v2);
		friend Vector3 operator / (const Vector3& _v1, const Vector3& _v2);
		friend Vector3 operator / (const Vector3& _v1, float _v2);
		friend Vector3 operator / (float _v1, const Vector3& _v2);

		friend Vector3 operator - (const Vector3& _v1);

		bool operator == (const Vector3& _v) const;
		bool operator != (const Vector3& _v) const;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
			/// <summary>
			/// 要素セット
			/// </summary>
			/// <param name="_x">X</param>
			/// <param name="_y">Y</param>
			/// <param name="_z">Z</param>
		void Set(float _x, float _y, float _z);

		/// <summary>
		/// 要素セット
		/// </summary>
		/// <param name="_vec">ベクトル</param>
		void Set(D3DXVECTOR3 _vec);

		/// <summary>
		/// 長さ取得
		/// </summary>
		/// <returns>長さ</returns>
		float GetLength() const;

		/// <summary>
		/// 長さ取得
		/// </summary>
		/// <returns>長さ</returns>
		float GetLengthSquared() const;

		/// <summary>
		/// インデックスアクセス
		/// </summary>
		float AccessByIndex(int) const;

		/// <summary>
		/// 単位ベクトル化
		/// </summary>
		Vector3 Normalize();

		/// <summary>
		/// 単位ベクトル生成
		/// </summary>
		Vector3 GetNormalize();

		/// <summary>
		/// D3DXVECTOR3化
		/// </summary>
		/// <returns>コンバート後</returns>
		D3DXVECTOR3 ToDirectX()const;

		/// <summary>
		/// スカラー値の平均
		/// </summary>
		/// <returns>平均</returns>
		float AveScalar();

		/// <summary>
		/// マトリックスで回転
		/// </summary>
		/// <param name="_vec">対象ベクトル</param>
		/// <param name="_mat">対象行列</param>
		/// <returns>回転後</returns>
		static Vector3 Rotate(const Vector3& _vec, const D3DXMATRIX& _mat);

		/// <summary>
		/// ランダムベクトル取得
		/// </summary>
		/// <returns>ベクトル</returns>
		static Vector3 Random();

		/// <summary>
		/// 指定範囲のベクトル
		/// </summary>
		/// <param name="_Min">最小</param>
		/// <param name="_Max">最大</param>
		/// <returns>ランダムベクトル</returns>
		static Vector3 Random(float _Min, float _Max);

		/// <summary>
		/// 球面上のランダム点
		/// </summary>
		/// <returns></returns>
		static Vector3 OnSphereRandom();

		/// <summary>
		/// 内積
		/// </summary>
		/// <returns>内積値</returns>
		static float Dot(const Vector3& _lhv, const Vector3& _rhv);

		/// <summary>
		/// 外積
		/// </summary>
		/// <returns>ベクトル</returns>
		static Vector3 Cross(const Vector3& _lhv, const Vector3& _rhv);

		/// <summary>
		/// 与ベクトルに直行するベクトルを返す
		/// グラムシュミットの直交化を使うのでCrossとかより断然重い
		/// </summary>
		/// <returns>正規化済み直行ベクトル誤差あり</returns>
		static std::pair<Vector3, Vector3> RCross(const Vector3& );

		/// <summary>
		/// 正射影ベクトル
		/// _lhvを元に_rhvを射影する
		/// </summary>
		static Vector3 OrthogonalProjection(const Vector3& _lhv, const Vector3& _rhv);

		/// <summary>
		/// 二点間の中心を求める
		/// </summary>
		static Vector3 CenterOf(const Vector3& _lhv, const Vector3& _rhv);

		//-----------------------------------------------------------
		//PROPERTY
		//-----------------------------------------------------------
		PROPERTY(m_X, X, float);
		PROPERTY(m_Y, Y, float);
		PROPERTY(m_Z, Z, float);

		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
		static const Vector3 zero;	  //Vector3(0, 0, 0)
		static const Vector3 once;	  //Vector3(1, 1, 1)
		static const Vector3 back;	  //Vector3(0, 0, -1)
		static const Vector3 forward; //Vector3(0, 0, 1)
		static const Vector3 left;	  //Vector3(-1, 0, 0)
		static const Vector3 rigth;	  //Vector3(1, 0, 0)
		static const Vector3 up;	  //Vector3(0, 1, 0)
		static const Vector3 down;	  //Vector3(0, -1, 0)
		static const float	Epsilon;  //Defaultで

	private:

		float m_X;
		float m_Y;
		float m_Z;
	};
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

