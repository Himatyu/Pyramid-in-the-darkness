/**
* @file		TextureAnimUV.h
* @brief	テクスチャアニメーションの座標計算を提供
* @author	S.OIKAWA
* @date		2016.11.23
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<array>

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		class TextureAnimFream;
		using DiagonalUV = std::array<float, 4>;
		/// <summary>
		/// テクスチャアニメーションの座標計算
		/// </summary>
		class TextureAnimUV
		{
			friend class TextureAnimFream;
		public:
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			TextureAnimUV();
			virtual ~TextureAnimUV();

			TextureAnimUV(const TextureAnimUV&) = default;
			TextureAnimUV(TextureAnimUV&&) = default;

			TextureAnimUV& operator=(const TextureAnimUV&) = default;
			TextureAnimUV& operator=(TextureAnimUV&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			void SetUp(
				int _width = 1,
				int _height = 1,
				float _time = 0,
				int AnimCount = 0);

			void AttachFream(TextureAnimFream& fream);

			std::array<float, 4> getUV(TextureAnimFream& anim);

			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
		private:
			int width = 1;
			int height = 1;
			float uvWidth = 1.0f;
			float uvHeght = 1.0f;
			float time = 0.0f;
			float freamTime = 0.0f;
			float fream = 0;
			int uvCount = -1;
			int uvCountMax = -1;
			bool isLoop = true;
			std::array<float, 8> uvArray;
			std::vector<DiagonalUV> UVArray;

		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------