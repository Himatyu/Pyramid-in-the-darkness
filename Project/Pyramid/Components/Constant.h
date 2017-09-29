/**
* @file		Constant.h
* @brief	Componentsの定数を定義する
* @author	S.OIKAWA
* @date		2016.11.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<windef.h>
#include<functional>
#include<string>
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Components
	{
		namespace Detail
		{
			class Particle;
		}
		class Constant final
		{
		public:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
			/// <summary>
			/// カメラ更新のラインID
			/// </summary>
			const static UINT CameraMTUpdataLineID;

			/// <summary>
			/// トランスフォーム更新のラインID
			/// </summary>
			const static UINT TransformMTUpdataLineID;

			/// <summary>
			/// パーティクル更新のラインID
			/// </summary>
			const static UINT ParticleMTUpdataLineID;

			/// <summary>
			/// パーティクルの描画優先度
			/// </summary>
			const static UINT ParticleMTRenderingPriority;

			/// <summary>
			/// シェーダに渡すDifuseのパラメタ名
			/// </summary>
			const static std::string LightDifuseParameter;

			/// <summary>
			/// シェーダに渡すDirectのパラメタ名
			/// </summary>
			const static std::string LightDirectParameter;

			/// <summary>
			/// パーティクルで使用する重力
			/// </summary>
			const static Utility::Vector3 ParticleGravity;

			/// <summary>
			/// 標準の追加初期化
			/// </summary>
			const static std::function<void(Detail::Particle&)> DefaultAdditionalInitialize;

			/// <summary>
			/// 標準の追加更新
			/// </summary>
			const static std::function<void(Detail::Particle&)> DefaultAdditionalUpdata;

			/// <summary>
			/// デバック時に使用する見た目衝突モデルの色
			/// </summary>
			const static std::array<std::array<float,4>, 12> EmissiveOfDebugCollisinVolume;

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------