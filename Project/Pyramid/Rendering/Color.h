/**
* @file		Color.h
* @brief	�l�F�̐F����ێ�����
* @author	S.OIKAWA
* @date		2016.11.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Pyramid
{
	namespace Rendering
	{
		using ColorArray = std::array<float, 4>;
		/// <summary>
		/// �l�F�̐F����ێ�����
		/// </summary>
		class Color final
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			Color() = default;
			Color(float, float, float, float);
			~Color() = default;

			Color(const Color&) = default;
			Color(Color&&) = default;

			Color& operator=(const Color&) = default;
			Color& operator=(Color&&) = default;
#pragma endregion

#pragma region function

	//-----------------------------------------------------------
	// function
	//-----------------------------------------------------------
			//���[�h�I�����[��S�ۂ���������֐�
			static Color Transparent();
			static Color Brack();
			static Color Bule();
			static Color Cyan();
			static Color Gray();
			static Color Green();
			static Color Magenta();
			static Color Red();
			static Color White();
			static Color Yellow();
			static Color Random(bool _isOpacity = true);
			static Color Lerp(Color _a, Color _b,float _t);
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
			PROPERTY_REF(m_Color[0], B ,float);
			PROPERTY_REF(m_Color[1], G, float);
			PROPERTY_REF(m_Color[2], R, float);
			PROPERTY_REF(m_Color[3], A, float);
			PROPERTY_R_ONLY(m_Color.data(), Array, const float*);
#pragma endregion
		private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			ColorArray m_Color{1};
			 
#pragma endregion
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------