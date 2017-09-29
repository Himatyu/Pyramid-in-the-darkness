/**
* @file		Material.h
* @brief	レンダリングマテリアル
* @author	S.OIKAWA
* @date		2016.05.08
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3dx9.h>
#include<d3d9.h>
#include"../Utility/Macro.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			/// <summary>
			/// レンダリングマテリアル
			/// ホントはインターフェースがいいけど、
			/// デフォルトあるからクラスにした
			/// </summary>
			class Material
			{
			public:
				//-----------------------------------------------------------
				// default
				//-----------------------------------------------------------
				Material() = default;
				virtual ~Material() = default;

				Material(const Material&) = default;
				Material(Material&&) = default;

				Material& operator=(const Material&) = default;
				Material& operator=(Material&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void SetMateral() {}
				virtual void RiseMateral() {}
				virtual void SetMatrix(D3DXMATRIX&) {}

				static void SetDefaultMaterial();
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
