/**
* @file		Texture.h
* @brief	テクスチャAPI
* @author	S.OIKAWA
* @date		2016.05.08
* @date		2016.05.26 デフォルトコピー・ムーブ追加
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#include<string>
#include"../API/LostResourceAPI.h"
#include"../Texture/DirectXTextureFile.h"
#include"../Texture/DirectXTextureFileFromInMemory.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace API
		{
			/// <summary>
			/// テクスチャのAPI
			/// spのリソースを持つ
			/// </summary>
			template<class Type>
			class Texture final :
				public LostResourceAPI<Type>
			{
			public:

				//-----------------------------------------------------------
				// default
				//-----------------------------------------------------------
				Texture() = default;
				~Texture() = default;

				Texture(const Texture&) = default;
				Texture(Texture&&) = default;

				Texture& operator=(const Texture&) = default;
				Texture& operator=(Texture&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ロスト処理.
				/// </summary>
				void OnLost() override;

				/// <summary>
				/// 復帰処理.
				/// </summary>
				void Recover() override;

				//-----------------------------------------------------------
				// operator
				//-----------------------------------------------------------
				void operator=(std::shared_ptr<Type> _sp);
			};
#include"Texture.inl"
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

