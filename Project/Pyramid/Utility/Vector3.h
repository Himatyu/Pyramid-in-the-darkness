/**
* @file		Vector3.h
* @brief	 �x�N�^
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
			/// �v�f�Z�b�g
			/// </summary>
			/// <param name="_x">X</param>
			/// <param name="_y">Y</param>
			/// <param name="_z">Z</param>
		void Set(float _x, float _y, float _z);

		/// <summary>
		/// �v�f�Z�b�g
		/// </summary>
		/// <param name="_vec">�x�N�g��</param>
		void Set(D3DXVECTOR3 _vec);

		/// <summary>
		/// �����擾
		/// </summary>
		/// <returns>����</returns>
		float GetLength() const;

		/// <summary>
		/// �����擾
		/// </summary>
		/// <returns>����</returns>
		float GetLengthSquared() const;

		/// <summary>
		/// �C���f�b�N�X�A�N�Z�X
		/// </summary>
		float AccessByIndex(int) const;

		/// <summary>
		/// �P�ʃx�N�g����
		/// </summary>
		Vector3 Normalize();

		/// <summary>
		/// �P�ʃx�N�g������
		/// </summary>
		Vector3 GetNormalize();

		/// <summary>
		/// D3DXVECTOR3��
		/// </summary>
		/// <returns>�R���o�[�g��</returns>
		D3DXVECTOR3 ToDirectX()const;

		/// <summary>
		/// �X�J���[�l�̕���
		/// </summary>
		/// <returns>����</returns>
		float AveScalar();

		/// <summary>
		/// �}�g���b�N�X�ŉ�]
		/// </summary>
		/// <param name="_vec">�Ώۃx�N�g��</param>
		/// <param name="_mat">�Ώۍs��</param>
		/// <returns>��]��</returns>
		static Vector3 Rotate(const Vector3& _vec, const D3DXMATRIX& _mat);

		/// <summary>
		/// �����_���x�N�g���擾
		/// </summary>
		/// <returns>�x�N�g��</returns>
		static Vector3 Random();

		/// <summary>
		/// �w��͈͂̃x�N�g��
		/// </summary>
		/// <param name="_Min">�ŏ�</param>
		/// <param name="_Max">�ő�</param>
		/// <returns>�����_���x�N�g��</returns>
		static Vector3 Random(float _Min, float _Max);

		/// <summary>
		/// ���ʏ�̃����_���_
		/// </summary>
		/// <returns></returns>
		static Vector3 OnSphereRandom();

		/// <summary>
		/// ����
		/// </summary>
		/// <returns>���ϒl</returns>
		static float Dot(const Vector3& _lhv, const Vector3& _rhv);

		/// <summary>
		/// �O��
		/// </summary>
		/// <returns>�x�N�g��</returns>
		static Vector3 Cross(const Vector3& _lhv, const Vector3& _rhv);

		/// <summary>
		/// �^�x�N�g���ɒ��s����x�N�g����Ԃ�
		/// �O�����V���~�b�g�̒��������g���̂�Cross�Ƃ����f�R�d��
		/// </summary>
		/// <returns>���K���ςݒ��s�x�N�g���덷����</returns>
		static std::pair<Vector3, Vector3> RCross(const Vector3& );

		/// <summary>
		/// ���ˉe�x�N�g��
		/// _lhv������_rhv���ˉe����
		/// </summary>
		static Vector3 OrthogonalProjection(const Vector3& _lhv, const Vector3& _rhv);

		/// <summary>
		/// ��_�Ԃ̒��S�����߂�
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
		static const float	Epsilon;  //Default��

	private:

		float m_X;
		float m_Y;
		float m_Z;
	};
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

