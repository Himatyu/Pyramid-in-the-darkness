/**
* @file		TextureAnimFream.h
* @brief	テクスチャアニメーションのフレーム定義
* @author	S.OIKAWA
* @date		2016.11.23
*/
#pragma once

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Common
	{
		class TextureAnimUV;

		/// <summary>
		/// アニメーションのフレーム
		/// </summary>
		class TextureAnimFream
		{
			friend class TextureAnimUV;
		public:
			//-----------------------------------------------------------
			// defaluts
			//-----------------------------------------------------------
			TextureAnimFream();
			~TextureAnimFream();

			TextureAnimFream(const TextureAnimFream&) = default;
			TextureAnimFream(TextureAnimFream&&) = default;

			TextureAnimFream& operator=(const TextureAnimFream&) = default;
			TextureAnimFream& operator=(TextureAnimFream&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			
			/// <summary>
			/// アニメーションのパラメータを初期化する
			/// </summary>
			void InitOfParameters();

			/// <summary>
			/// フレーム更新
			/// </summary>
			void Updata();

			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
		private:
			TextureAnimUV* pOwner;
			int		uvCount = -1;
			int		uvCountMax = -1;
			float	freamTime = 0.0f;
			float	fream = 0;
			bool	isActive = false;
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------