/**
* @file		TextureAnimUV.cpp
* @brief	テクスチャアニメーションの座標計算を提供
* @author	S.OIKAWA
* @date		2016.11.23
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "TextureAnimUV.h"
#include"TextureAnimFream.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		using namespace std;
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		TextureAnimUV::TextureAnimUV():
			uvCount(-1),
			uvCountMax(-1)
		{
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		TextureAnimUV::~TextureAnimUV()
		{
		}

		//-----------------------------------------------------------
		// SetUp
		//-----------------------------------------------------------
		void TextureAnimUV::SetUp(
			int _width,
			int _height,
			float _time,
			int AnimCount)
		{
			width = _width;
			height = _height;
			uvWidth = 1.0f / _width;
			uvHeght = 1.0f / _height;
			time = _time;
			uvCountMax = (AnimCount) ? AnimCount : _width * _height;
			uvCount = 0;
			freamTime = _time / uvCountMax;

			for (int h = 0; h < _height; h++)
			{
				for (int w = 0; w < _width; w++)
				{
					UVArray.emplace_back(
						DiagonalUV{
						uvWidth * w,
						uvHeght * h,
						uvWidth * w + uvWidth ,
						uvHeght *h + uvHeght });
				}
			}

		}

		//-----------------------------------------------------------
		// AttachFream
		//-----------------------------------------------------------
		void TextureAnimUV::AttachFream(TextureAnimFream& fream)
		{
			fream.uvCount = uvCount;
			fream.uvCountMax = uvCountMax;
			fream.fream = 0;
			fream.isActive = true;
			fream.freamTime = freamTime;
			fream.pOwner = this;
		}

		//-----------------------------------------------------------
		// getUV
		//-----------------------------------------------------------
		array<float, 4> TextureAnimUV::getUV(TextureAnimFream& anim)
		{
			if (anim.uvCountMax == -1)
			{
				return array<float, 4>{0,0,1,1};
			}
			return UVArray[anim.uvCount];
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
