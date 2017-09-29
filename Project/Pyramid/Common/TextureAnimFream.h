/**
* @file		TextureAnimFream.h
* @brief	�e�N�X�`���A�j���[�V�����̃t���[����`
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
		/// �A�j���[�V�����̃t���[��
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
			/// �A�j���[�V�����̃p�����[�^������������
			/// </summary>
			void InitOfParameters();

			/// <summary>
			/// �t���[���X�V
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