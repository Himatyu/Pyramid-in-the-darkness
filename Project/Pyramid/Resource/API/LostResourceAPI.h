/**
* @file		LostResourceAPI.h
* @brief	デバイスロスト時にリストアするリソース
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
			/// ロスト対応可能なリソースAPI
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
				/// リソースの開放
				/// </summary>
				virtual void OnLost() = 0;

				/// <summary>
				/// リソースの再構築
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
