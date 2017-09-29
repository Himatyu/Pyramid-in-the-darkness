/**
* @file		Material.cpp
* @brief	レンダリングマテリアル
* @author	S.OIKAWA
* @date		2016.05.08
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Material.h"
#include"../RenderProvider.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			//-----------------------------------------------------------
			// SetDefaultMaterial
			//-----------------------------------------------------------
			void Material::SetDefaultMaterial()
			{
				auto pDevice = Rendering::Graphics::Instantiate().Device;

				D3DMATERIAL9 DeffineMaterial{ 0 };
				DeffineMaterial.Diffuse = D3DCOLORVALUE{ 255, 0, 255, 255 };
				DeffineMaterial.Emissive = DeffineMaterial.Diffuse;
				DeffineMaterial.Power = 1.0f;

				pDevice->SetMaterial(&DeffineMaterial);
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------