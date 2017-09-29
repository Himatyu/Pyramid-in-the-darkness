/**
* @file		LostResourceAPI.h
* @brief	�f�o�C�X���X�g���Ƀ��X�g�A���郊�\�[�X
* @author	S.OIKAWA
* @date		2016.05.07
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IResourceAPI.h"
#include<typeinfo>
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
			/// ���X�g�Ή��\�ȃ��\�[�XAPI
			/// </summary>
			template<class ResourceFile>
			class LostResourceAPI :
				public IResourceAPI<ResourceFile>
			{
			public:
				//-----------------------------------------------------------
				// default
				//-----------------------------------------------------------
				LostResourceAPI() = default;
				virtual ~LostResourceAPI() = default;

				LostResourceAPI(const LostResourceAPI&) = default;
				LostResourceAPI(LostResourceAPI&&) = default;

				LostResourceAPI& operator=(const LostResourceAPI&) = default;
				LostResourceAPI& operator=(LostResourceAPI&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ���\�[�X�̊J��
				/// </summary>
				virtual void OnLost() = 0;

				/// <summary>
				/// ���\�[�X�̍č\�z
				/// </summary>
				virtual void Recover() = 0;

			protected:
				template<class Type>
				bool ResourceIsType();
			};
#include"LostResourceAPI.inl"
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
