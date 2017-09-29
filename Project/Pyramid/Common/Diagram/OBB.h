/**
* @file		OBB.h
* @brief	有効境界箱
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Vector3.h"
#include"Nullable.h"
#include"IDiagram.h"
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		class Transform;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{
			/// <summary>
			/// 有効境界箱
			/// </summary>
			class OBB :
				public IDiagram
			{
				using AxisType = std::array<Utility::Vector3, 3>;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				OBB();
				~OBB() = default;

				OBB(const OBB&) = default;
				OBB(OBB&&) = default;

				OBB& operator=(const OBB&) = default;
				OBB& operator=(OBB&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 座標がOBB内にあるか検証する
				/// nullが帰れば中、それ以外は外
				/// </summary>
				Utility::Nullable<float> IsInside(const Utility::Vector3&);

				/// <summary>
				/// 分離軸上に投影された辺の半分の長さを演算する
				/// </summary>
				float CalculateHalfProjectLengthOnSeparatAxis(const Utility::Vector3&);

				/// <summary>
				/// 更新
				/// </summary>
				void ReflectionOfTransfrom(Common::Sp<Components::Transform>&) override;
				
				/// <summary>
				/// 拡縮
				/// </summary>
				void ScaleTo(const Utility::Vector3&) override;

				/// <summary>
				/// 移動
				/// </summary>
				void MoveTo(const Utility::Vector3&) override;

				/// <summary>
				/// 回転を行う
				/// 引数のvectorはデグリーで扱う
				/// </summary>
				void RotateTo(const Utility::Vector3&)override;

				/// <summary>
				/// 初期状態に戻す
				/// 各軸は軸並行の長さ1
				/// 領域、座標は0
				/// </summary>
				void Initialize() override;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY_REF(m_Half, Half, Utility::Vector3);
				PROPERTY_REF(m_Center, Center, Utility::Vector3);
				PROPERTY_REF(m_LocalAxis[0], LocalAxisX, Utility::Vector3);
				PROPERTY_REF(m_LocalAxis[1], LocalAxisY, Utility::Vector3);
				PROPERTY_REF(m_LocalAxis[2], LocalAxisZ, Utility::Vector3);
				PROPERTY_REF(m_LocalAxis, LocalAxis, AxisType);
#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			private:
				Utility::Vector3		m_Half;
				Utility::Vector3		m_Center;
				std::array<Utility::Vector3, 3>	m_LocalAxis;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------