/**
* @file		IResource.h
* @brief	抽象リソース
* @author	S.OIKAWA
* @date		2016.08.14
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "File.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		/// <summary>
		/// 抽象リソース
		/// </summary>
		class IResource :
			public Utility::File
		{
		public:

			//-----------------------------------------------------------
			// default
			//-----------------------------------------------------------
			IResource() = default;
			virtual ~IResource() = default;

			IResource(const IResource&) = default;
			IResource(IResource&&) = default;

			IResource&operator=(const IResource&) = default;
			IResource&operator=(IResource&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			/// <summary>
			/// ファイル読み込み.
			/// </summary>
			/// <param name="_path">ファイルパス</param>
			virtual void Read(std::string _path) override {};

			/// <summary>
			/// 書き込み.
			/// </summary>
			/// <param name="_path">ファイルパス</param>
			virtual void Write(std::string _path = "") override {};

			/// <summary>
			/// 情報を破棄する.
			/// </summary>
			virtual void Discard() {};
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------