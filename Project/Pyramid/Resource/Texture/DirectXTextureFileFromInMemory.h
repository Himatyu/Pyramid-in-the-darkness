/**
* @file		DirectXTextureFileFromInMemory.h
* @brief	バッファからDirectXのテクスチャを生成する機能提供
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
			/// オンメモリなテクスチャからDirectX用のテクスチャを生成する
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
				/// テクスチャを生成する
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