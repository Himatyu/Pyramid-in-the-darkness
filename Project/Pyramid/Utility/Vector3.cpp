/**
* @file			Vector3.cpp	
* @brief		Vector3実装
* @author		S.OIKAWA
* @date			2016.05.09
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<math.h>
#include<random>
#include "Vector3.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace std;
namespace Utility
{
	const Vector3 Vector3::zero = Vector3(0, 0, 0);
	const Vector3 Vector3::once = Vector3(1, 1, 1);
	const Vector3 Vector3::back = Vector3(0, 0, -1);
	const Vector3 Vector3::forward = Vector3(0, 0, 1);
	const Vector3 Vector3::left = Vector3(-1, 0, 0);
	const Vector3 Vector3::rigth = Vector3(1, 0, 0);
	const Vector3 Vector3::up = Vector3(0, 1, 0);
	const Vector3 Vector3::down = Vector3(0, -1, 0);
	const float	Vector3::Epsilon = 0.0001f;

	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	Vector3::Vector3() :
		m_X(0),
		m_Y(0),
		m_Z(0)
	{
	}

	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	Vector3::Vector3(float _x, float _y, float _z) :
		m_X(_x),
		m_Y(_y),
		m_Z(_z)
	{

	}

	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	Vector3::Vector3(const D3DXVECTOR3& _vec) :
		m_X(_vec.x),
		m_Y(_vec.y),
		m_Z(_vec.z)
	{

	}

	//-----------------------------------------------------------
	// dtor
	//-----------------------------------------------------------
	Vector3::~Vector3()
	{
	}

	//-----------------------------------------------------------
	// +=
	//-----------------------------------------------------------
	Vector3& Vector3::operator += (const Vector3& _v)
	{
		m_X += _v.m_X;
		m_Y += _v.m_Y;
		m_Z += _v.m_Z;
		return (*this);
	}

	//-----------------------------------------------------------
	// +=
	//-----------------------------------------------------------
	Vector3& Vector3::operator += (float _v)
	{
		m_X += _v;
		m_Y += _v;
		m_Z += _v;
		return (*this);
	}

	//-----------------------------------------------------------
	// -=
	//-----------------------------------------------------------
	Vector3& Vector3::operator -= (const Vector3& _v)
	{
		m_X -= _v.m_X;
		m_Y -= _v.m_Y;
		m_Z -= _v.m_Z;
		return (*this);
	}

	//-----------------------------------------------------------
	// -=
	//-----------------------------------------------------------
	Vector3& Vector3::operator -= (float _v)
	{
		m_X -= _v;
		m_Y -= _v;
		m_Z -= _v;
		return (*this);
	}

	//-----------------------------------------------------------
	// *=
	//-----------------------------------------------------------
	Vector3& Vector3::operator *= (const Vector3& _v)
	{
		m_X *= _v.m_X;
		m_Y *= _v.m_Y;
		m_Z *= _v.m_Z;
		return (*this);
	}

	//-----------------------------------------------------------
	// *=
	//-----------------------------------------------------------
	Vector3& Vector3::operator *= (float _v)
	{
		m_X *= _v;
		m_Y *= _v;
		m_Z *= _v;
		return (*this);
	}

	//-----------------------------------------------------------
	// /=
	//-----------------------------------------------------------
	Vector3& Vector3::operator /= (const Vector3& _v)
	{
		m_X /= _v.m_X;
		m_Y /= _v.m_Y;
		m_Z /= _v.m_Z;
		return (*this);
	}

	//-----------------------------------------------------------
	// /=
	//-----------------------------------------------------------
	Vector3& Vector3::operator /= (float _v)
	{
		_v = 1.0f / _v;
		m_X *= _v;
		m_Y *= _v;
		m_Z *= _v;
		return (*this);
	}
	
	//-----------------------------------------------------------
	// +
	//-----------------------------------------------------------
	Vector3 operator + (const Vector3& _v1, const Vector3& _v2)
	{
		return Vector3(
			_v1.m_X + _v2.m_X,
			_v1.m_Y + _v2.m_Y,
			_v1.m_Z + _v2.m_Z);
	}

	//-----------------------------------------------------------
	// +
	//-----------------------------------------------------------
	Vector3 operator + (const Vector3& _v1, float _v2)
	{
		return Vector3(
			_v1.m_X + _v2,
			_v1.m_Y + _v2,
			_v1.m_Z + _v2);
	}

	//-----------------------------------------------------------
	// +
	//-----------------------------------------------------------
	Vector3 operator + (float _v1, const Vector3& _v2)
	{
		return Vector3(
			_v1 + _v2.m_X,
			_v1 + _v2.m_Y,
			_v1 + _v2.m_Z);
	}

	//-----------------------------------------------------------
	// -
	//-----------------------------------------------------------
	Vector3 operator - (const Vector3& _v1, const Vector3& _v2)
	{
		return Vector3(
			_v1.m_X - _v2.m_X,
			_v1.m_Y - _v2.m_Y,
			_v1.m_Z - _v2.m_Z);
	}

	//-----------------------------------------------------------
	// -
	//-----------------------------------------------------------
	Vector3 operator - (const Vector3& _v1, float _v2)
	{
		return Vector3(
			_v1.m_X - _v2,
			_v1.m_Y - _v2,
			_v1.m_Z - _v2);
	}

	//-----------------------------------------------------------
	// -
	//-----------------------------------------------------------
	Vector3 operator - (float _v1, const Vector3& _v2)
	{
		return Vector3(
			_v1 - _v2.m_X,
			_v1 - _v2.m_Y,
			_v1 - _v2.m_Z);
	}

	//-----------------------------------------------------------
	// *
	//-----------------------------------------------------------
	Vector3 operator * (const Vector3& _v1, const Vector3& _v2)
	{
		return Vector3(
			_v1.m_X * _v2.m_X,
			_v1.m_Y * _v2.m_Y,
			_v1.m_Z * _v2.m_Z);
	}

	//-----------------------------------------------------------
	// *
	//-----------------------------------------------------------
	Vector3 operator * (const Vector3& _v1, float _v2)
	{
		return Vector3(
			_v1.m_X * _v2,
			_v1.m_Y * _v2,
			_v1.m_Z * _v2);
	}

	//-----------------------------------------------------------
	// *
	//-----------------------------------------------------------
	Vector3 operator * (float _v1, const Vector3& _v2)
	{
		return Vector3(
			_v1 * _v2.m_X,
			_v1 * _v2.m_Y,
			_v1 * _v2.m_Z);
	}

	//-----------------------------------------------------------
	// /
	//-----------------------------------------------------------
	Vector3 operator / (const Vector3& _v1, const Vector3& _v2)
	{
		return Vector3(
			_v1.m_X / _v2.m_X,
			_v1.m_Y / _v2.m_Y,
			_v1.m_Z / _v2.m_Z);
	}

	//-----------------------------------------------------------
	// /
	//-----------------------------------------------------------
	Vector3 operator / (const Vector3& _v1, float _v2)
	{
		return Vector3(
			_v1.m_X / _v2,
			_v1.m_Y / _v2,
			_v1.m_Z / _v2);
	}

	//-----------------------------------------------------------
	// /
	//-----------------------------------------------------------
	Vector3 operator / (float _v1, const Vector3& _v2)
	{
		return Vector3(
			_v1 / _v2.m_X,
			_v1 / _v2.m_Y,
			_v1 / _v2.m_Z);
	}


	//-----------------------------------------------------------
	// -
	//-----------------------------------------------------------
	Vector3 operator - (const Vector3& _v1)
	{
		return Vector3(
			-_v1.m_X,
			-_v1.m_Y,
			-_v1.m_Z);
	}

	//-----------------------------------------------------------
	// ==
	//-----------------------------------------------------------
	bool Vector3::operator == (const Vector3& _v) const
	{
		return (
			std::abs(m_X - _v.m_X)<Epsilon && 
			std::abs(m_Y - _v.m_Y)<Epsilon &&
			std::abs(m_Z - _v.m_Z)<Epsilon);
	}

	//-----------------------------------------------------------
	// !=
	//-----------------------------------------------------------
	bool Vector3::operator != (const Vector3& _v) const
	{
		return (
			std::abs(m_X - _v.m_X)>Epsilon ||
			std::abs(m_Y - _v.m_Y)>Epsilon ||
			std::abs(m_Z - _v.m_Z)>Epsilon);
	}

	//-----------------------------------------------------------
	// Set
	//-----------------------------------------------------------
	void Vector3::Set(float _x, float _y, float _z)
	{
		m_X = _x;
		m_Y = _y;
		m_Z = _z;
	}

	//-----------------------------------------------------------
	// Set
	//-----------------------------------------------------------
	void Vector3::Set(D3DXVECTOR3 _vec)
	{
		m_X = _vec.x;
		m_Y = _vec.y;
		m_Z = _vec.z;
	}

	//-----------------------------------------------------------
	// GetLength
	//-----------------------------------------------------------
	float Vector3::GetLength() const
	{
		return sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z);
	}


	//-----------------------------------------------------------
	// GetLengthSquared
	//-----------------------------------------------------------
	float Vector3::GetLengthSquared() const
	{
		return m_X * m_X + m_Y * m_Y + m_Z * m_Z;
	}

	//-----------------------------------------------------------
	// AccessByIndex
	//-----------------------------------------------------------
	float Vector3::AccessByIndex(int _index) const
	{
		if (_index >= 3)
		{
			___D_LOG("AccessByIndexにおける不正インデックスアクセス");
			return 0;
		}

		switch (_index)
		{
		case 0:
			return m_X;

		case 1:
			return m_Y;

		case 2:
			return m_Z;
		};
	}

	//-----------------------------------------------------------
	// Normalize
	//-----------------------------------------------------------
	Vector3 Vector3::Normalize()
	{
		float t = sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z);
		m_X /= t;
		m_Y /= t;
		m_Z /= t;
		return *this;
	}


	//-----------------------------------------------------------
	// GetNormalize
	//-----------------------------------------------------------
	Vector3 Vector3::GetNormalize()
	{
		Vector3 result(*this);
		return result.Normalize();
	}

	//-----------------------------------------------------------
	// Dot
	//-----------------------------------------------------------
	float Vector3::Dot(const Vector3& _lhv, const Vector3& _rhv)
	{
		return (_lhv.m_X * _rhv.m_X + _lhv.m_Y * _rhv.m_Y + _lhv.m_Z * _rhv.m_Z);
	}

	//-----------------------------------------------------------
	// Cross
	//-----------------------------------------------------------
	Vector3 Vector3::Cross(const Vector3& _lhv, const Vector3& _rhv)
	{
		return Vector3(
			(_lhv.m_Y * _rhv.m_Z) - (_lhv.m_Z * _rhv.m_Y),
			(_lhv.m_Z * _rhv.m_X) - (_lhv.m_X * _rhv.m_Z),
			(_lhv.m_X * _rhv.m_Y) - (_lhv.m_Y * _rhv.m_X));
	}


	//-----------------------------------------------------------
	// RCross
	//-----------------------------------------------------------
	std::pair<Vector3, Vector3> 
		Vector3::RCross(const Vector3 & _vec)
	{
		//一次独立なベクトルの生成 a2,a3は並行以外の適当
		auto a1 = _vec;
		auto a2 = Utility::Vector3(_vec.X + 0.1f, _vec.Y+0.2f, _vec.Z+0.3f);
		auto a3 = Utility::Vector3(_vec.X +0.3f, _vec.Y+0.2f, _vec.Z + 0.1f);

		//正規直交基底として生成するので正規化する
		auto v1 = a1.Normalize();
		auto v2 = (a2 - (Vector3::Dot(a2, v1)*v1)).Normalize();
		auto v3 = (
					a3 
					- (Vector3::Dot(a3, v1)*v1) 
					- (Vector3::Dot(a3, v2)*v2)
					).Normalize();

		return std::pair<Vector3, Vector3>(v2, v3);
	}

	//-----------------------------------------------------------
	// OrthogonalProjection
	//-----------------------------------------------------------
	Vector3 Vector3::OrthogonalProjection(
		const Vector3 & _lhv, const Vector3 & _rhv)
	{
		auto length = _lhv.GetLength();
		return (Dot(_lhv, _rhv)/(length*length))*_lhv;
	}
	
	//-----------------------------------------------------------
	// OrthogonalProjection
	//-----------------------------------------------------------
	Vector3 Vector3::CenterOf(const Vector3 & _lhv, const Vector3 & _rhv)
	{
		return (_lhv + (_rhv - _lhv) / 2);
	}

	//-----------------------------------------------------------
	//ToDirectX
	//-----------------------------------------------------------
	D3DXVECTOR3 Vector3::ToDirectX()const
	{
		return D3DXVECTOR3(m_X, m_Y, m_Z);
	}

	//-----------------------------------------------------------
	//Rotation
	//-----------------------------------------------------------
	Vector3 Vector3::Rotate(const Vector3& _vec, const D3DXMATRIX& _mat)
	{
		return Vector3(
			(((_vec.m_X * _mat._11) + (_vec.m_Y * _mat._21)) + (_vec.m_Z * _mat._31)) ,
			(((_vec.m_X * _mat._12) + (_vec.m_Y * _mat._22)) + (_vec.m_Z * _mat._32)) ,
			(((_vec.m_X * _mat._13) + (_vec.m_Y * _mat._23)) + (_vec.m_Z * _mat._33)) 
			);
	}

	//-----------------------------------------------------------
	// AveScalar
	//-----------------------------------------------------------
	float Vector3::AveScalar()
	{
		return (m_X + m_Y + m_Z) / 3.0f;
	}

	//-----------------------------------------------------------
	// Random
	//-----------------------------------------------------------
	Vector3 Vector3::Random()
	{
		random_device rd;
		mt19937 mt(rd());
		return Vector3(mt(), mt(), mt());
	}

	//-----------------------------------------------------------
	// Random
	//-----------------------------------------------------------
	Vector3 Vector3::Random(float _Min, float _Max)
	{
		random_device rd;
		mt19937 mt(rd());

		uniform_real_distribution<float> fRand(_Min, _Max);
		return Vector3(fRand(mt), fRand(mt), fRand(mt));
	}
	
	//-----------------------------------------------------------
	// OnSphereRandom
	//-----------------------------------------------------------
	Vector3 Vector3::OnSphereRandom()
	{
		random_device rd;
		mt19937 mt(rd());
		uniform_real_distribution<float> fRand(-3.14f, 3.14f);
		float x = fRand(mt);
		float y = fRand(mt);

		return Vector3(
			sin(x)*cos(y),
			sin(x)*sin(y),
			cos(x)
			);
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
