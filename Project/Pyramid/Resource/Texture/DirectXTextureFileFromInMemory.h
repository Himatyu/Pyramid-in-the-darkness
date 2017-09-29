/**
* @file		DirectXTextureFileFromInMemory.h
* @brief	�o�b�t�@����DirectX�̃e�N�X�`���𐶐�����@�\��
* @author	S.OIKAWA
* @date		2016.10.26
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "DirectXTextureFile.h"
#include<vector>
#include<string>
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
			/// �I���������ȃe�N�X�`������DirectX�p�̃e�N�X�`���𐶐�����
			/// </summary>
			class DirectXTextureFileFromInMemory final :
				public DirectXTextureFile
			{
			public:

				//-----------------------------------------------------------
				// default
				//-----------------------------------------------------------
				DirectXTextureFileFromInMemory(std::pair<std::string, std::vector<char>>&&);
				~DirectXTextureFileFromInMemory() = default;

				DirectXTextureFileFromInMemory(const DirectXTextureFileFromInMemory&) = default;
				DirectXTextureFileFromInMemory(DirectXTextureFileFromInMemory&&) = default;

				DirectXTextureFileFromInMemory&operator=(const DirectXTextureFileFromInMemory&) = default;
				DirectXTextureFileFromInMemory&operator=(DirectXTextureFileFromInMemory&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// �e�N�X�`���𐶐�����
				/// </summary>
				void CreateTexture();

				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				std::pair<std::string, std::vector<char>> m_Cache;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------