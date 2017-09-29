/**
* @file		Texture.h
* @brief	�e�N�X�`��API
* @author	S.OIKAWA
* @date		2016.05.08
* @date		2016.05.26 �f�t�H���g�R�s�[�E���[�u�ǉ�
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
			/// �e�N�X�`����API
			/// sp�̃��\�[�X������
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
				/// ���X�g����.
				/// </summary>
				void OnLost() override;

				/// <summary>
				/// ���A����.
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

