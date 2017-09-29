/**
* @file		DirectionalLight.h
* @brief	並行光源を提供
* @author	S.OIKAWA
* @date		2016.11.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Component.h"
#include"Vector3.h"
#include"Nullable.h"
#include"Detail\ILight.h"
#include"../Rendering/Color.h"
#include"../Rendering/Shaders/Shader.h"
#include"../GameObject/Detail/ComponentsPossession.h"
#include<memory>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Shaders
		{
			class Shader;
		}
	}
}
#pragma endregion
namespace Pyramid
{
	namespace Components
	{
		/// <summary>
		/// 並行光源を提供
		/// </summary>
		class DirectionalLight final:
			public Component,
			public Detail::ILight
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			DirectionalLight();
			~DirectionalLight();

			DirectionalLight(const DirectionalLight&) = default;
			DirectionalLight(DirectionalLight&&) = default;

			DirectionalLight& operator=(const DirectionalLight&) = default;
			DirectionalLight& operator=(DirectionalLight&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			void Init() override;

			/// <summary>
			/// 更新.
			/// </summary>
			virtual void Updata() override;

			/// <summary>
			///	ライト情報を転送する
			/// </summary>
			void SetLight(Rendering::Shaders::Shader*,int) override;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
			PROPERTY_REF(m_Diffuse, Diffuse, Rendering::Color);
			PROPERTY_REF(m_Specular, Specular, Rendering::Color);
#pragma endregion
		private:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			Rendering::Color					m_Diffuse;
			Rendering::Color					m_Specular;
			Utility::Vector3					m_Direction;
			GameObject::NullableSp<Transform>	m_pTransform;
#pragma endregion
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------