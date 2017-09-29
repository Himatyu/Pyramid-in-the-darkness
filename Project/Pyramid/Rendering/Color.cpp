/**
* @file		Color.cpp
* @brief	�l�F�̐F����ێ�����
* @author	S.OIKAWA
* @date		2016.11.19
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Color.h"
#include"Mathf.h"
#include<random>
#pragma endregion
using namespace std;

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Color::Color(float _r, float _g, float _b, float _a) :
			m_Color({ _r,_b,_g,_a })
		{
		}

		//-----------------------------------------------------------
		// Brack
		//-----------------------------------------------------------
		Color Color::Brack()
		{
			return Color(0,0,0,1);
		}

		//-----------------------------------------------------------
		//�@Transparent
		//-----------------------------------------------------------
		Color Color::Transparent()
		{
			return Color(0,0,0,0);
		}

		//-----------------------------------------------------------
		// Bule
		//-----------------------------------------------------------
		Color Color::Bule()
		{
			return Color(0,0,1,1);
		}

		//-----------------------------------------------------------
		// Cyan
		//-----------------------------------------------------------
		Color Color::Cyan()
		{
			return Color(0,1,1,1);
		}

		//-----------------------------------------------------------
		// Gray
		//-----------------------------------------------------------
		Color Color::Gray()
		{
			return Color(0.5,0.5,0.5,1);
		}

		//-----------------------------------------------------------
		// Green
		//-----------------------------------------------------------
		Color Color::Green()
		{
			return Color(0,1,0,1);
		}

		//-----------------------------------------------------------
		// Magenta
		//-----------------------------------------------------------
		Color Color::Magenta()
		{
			return Color(1,0,1,1);
		}

		//-----------------------------------------------------------
		// Red
		//-----------------------------------------------------------
		Color Color::Red()
		{
			return Color(1,0,0,1);
		}

		//-----------------------------------------------------------
		// White
		//-----------------------------------------------------------
		Color Color::White()
		{
			return Color(1,1,1,1);
		}

		//-----------------------------------------------------------
		// Yellow
		//-----------------------------------------------------------
		Color Color::Yellow()
		{
			return Color(1.0f,0.92f,0.016f,1.0f);
		}

		//-----------------------------------------------------------
		// Random
		//-----------------------------------------------------------
		Color Color::Random(bool _isOpacity)
		{
			random_device rd;
			mt19937 mt(rd());

			uniform_real_distribution<float> fRand(0.0, 1.0);
			return Color(
				fRand(mt),
				fRand(mt), 
				fRand(mt), 
				_isOpacity ? 1.0f: fRand(mt));
		}

		//-----------------------------------------------------------
		// Lerp
		//-----------------------------------------------------------
		Color Color::Lerp(Color _a, Color _b, float _t)
		{
			return Color(
				Utility::Mathf::Lerp(_a.R, _b.R, _t),
				Utility::Mathf::Lerp(_a.G, _b.G, _t), 
				Utility::Mathf::Lerp(_a.B, _b.B, _t),
				Utility::Mathf::Lerp(_a.A, _b.A, _t));
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------