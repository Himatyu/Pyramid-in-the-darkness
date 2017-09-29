/**
* @file		DirectionalLight.cpp
* @brief	並行光源を提供
* @author	S.OIKAWA
* @date		2016.11.19
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"DirectionalLight.h"
#include"Nullable.h"
#include "..\Components\DirectionalLight.h"
#include"../Rendering/Shaders/Shader.h"
#include"../Rendering/RenderProvider.h"
#include"../Rendering/Detail/RenderingContext.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		DirectionalLight::DirectionalLight()
		{
			auto& render = Rendering::RenderProvider::Instantiate().Wolrd;
			render.Context.LightList.AddRequest(this);
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		DirectionalLight::~DirectionalLight()
		{
			auto& render = Rendering::RenderProvider::Instantiate().Wolrd;
			render.Context.LightList.RemoveRequest(this);
		}

		//-----------------------------------------------------------
		// Init
		//-----------------------------------------------------------
		void DirectionalLight::Init()
		{
		}

		//-----------------------------------------------------------
		// Updata
		//-----------------------------------------------------------
		void DirectionalLight::Updata()
		{
			if (m_pTransform == nullptr)
			{
				m_pTransform = pOwner->GetComponent<Transform>();
				return;
			}

			m_Direction = m_pTransform->Rotation;
		}

		//-----------------------------------------------------------
		// SetLight
		//-----------------------------------------------------------
		void DirectionalLight::
			SetLight(Rendering::Shaders::Shader * _pShader,int _index)
		{
			//ハンドルでやりたいけど、Shader同士で共有されているので文字列指定
			auto pEff = _pShader->pEffect;
			auto aIndex = std::to_string(_index);

			auto LightColorName = std::string("LightDifuse") + aIndex;
			pEff->SetFloatArray(LightColorName.c_str() , m_Diffuse.Array, sizeof(float) * 4);
			
			auto LightDirName = std::string("LightDir") + aIndex;
			float dir[4] = { m_Direction.X,m_Direction.Y,m_Direction.Z,0 };
			pEff->SetValue(LightDirName.c_str(), dir, sizeof(float)*4);
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
