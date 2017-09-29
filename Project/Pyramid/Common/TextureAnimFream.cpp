/**
* @file		TextureAnimFream.cpp
* @brief	テクスチャアニメーションのフレーム定義
* @author	S.OIKAWA
* @date		2016.11.23
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "TextureAnimFream.h"
#include"TextureAnimUV.h"
#include"TimerServer.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		TextureAnimFream::TextureAnimFream():
			uvCount(-1)
		{
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		TextureAnimFream::~TextureAnimFream()
		{
		}

		//-----------------------------------------------------------
		// Updata
		//-----------------------------------------------------------
		void TextureAnimFream::Updata()
		{
			if (!isActive)
			{
				return;
			}
			fream += TimerServer::DeltaTime;

			if (freamTime < fream)
			{
				fream = 0.0f;
				uvCount++;
				if (uvCount >= uvCountMax)
				{//LoopProc
					if (pOwner->isLoop)
					{
						uvCount = 0;
					}
					else
					{
						isActive = false;
						uvCount = -1;
					}

				}
			}
		}

		//-----------------------------------------------------------
		// Init
		//-----------------------------------------------------------
		void TextureAnimFream::InitOfParameters()
		{
			uvCount = 0;
			uvCountMax = 0;
			freamTime = 0.0f;
			fream = 0;
			isActive = false;
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------