/**
* @file		ITextureFile.h
* @brief	�e�N�X�`���t�@�C���ɕK�v�ȃC���^�[�t�F�[�X���`
* @author	S.OIKAWA
* @date		2016.08.14
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "../IResource.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Texture
		{
			/// <summary>
			/// �e�N�X�`���t�@�C��API.
			/// </summary>
			class ITextureFile :
				public IResource
			{
			public:

				//-----------------------------------------------------------
				// defaults 
				//-----------------------------------------------------------

				ITextureFile() = default;
				virtual ~ITextureFile() = default;

				ITextureFile(const ITextureFile&) = default;
				ITextureFile(ITextureFile&&) = default;

				ITextureFile&operator=(const ITextureFile&) = default;
				ITextureFile&operator=(ITextureFile&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
			};
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------