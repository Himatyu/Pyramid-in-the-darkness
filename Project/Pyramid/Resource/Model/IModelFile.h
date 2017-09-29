/**
* @file		IModelFile.h
* @brief	モデルファイルが実装すべき機能のインターフェースを提供
* @author	S.OIKAWA
* @date		2016.11.6
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3dx9.h>
#include"../Common/Diagram/AABB.h"
#include"../IResource.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Model
		{
			/// <summary>
			/// モデルファイルが実装すべき機能と持つべき変数
			/// </summary>
			class IModelFile :
				public IResource
			{
			public:
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				IModelFile() = default;
				virtual ~IModelFile()= default;

				IModelFile(const IModelFile&) = default;
				IModelFile(IModelFile&&) = default;

				IModelFile& operator=(const IModelFile&) = default;
				IModelFile& operator=(IModelFile&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void InitializeUseDaveice() = 0;
				virtual void SetMatrix(D3DXMATRIX&) = 0;

				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_Volume, Volume, Common::Diagram::AABB);

				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			protected:
				Common::Diagram::AABB		m_Volume;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
