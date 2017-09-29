/**
* @file		LightingPublisher.cpp
* @brief	ライト情報をデバイスにプッシュする
* @author	S.OIKAWA
* @date		2016.11.20
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"LightingPublisher.h"
#include"../Shaders/Shader.h"
#include"../RenderProvider.h"
#include"../Constant.h"
#include<algorithm>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// SetLights
			//-----------------------------------------------------------
			void LightingPublisher::SetLights(Shaders::Shader* _pShader)
			{
				auto& render = RenderProvider::Instantiate();
				auto& lightList = render.Wolrd.Context.LightList;
				lightList.Apply();
				
				int lightCount = min( Constant::LightLimmit , lightList.Vector.size() );
				for (int i = 0; i < lightCount; i++)
				{
					lightList.Vector[i]->SetLight(_pShader,i);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------