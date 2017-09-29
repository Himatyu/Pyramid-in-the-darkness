/**
* @file		AABB.h
* @brief	AABB
* @author	S.OIKAWA
* @date		2016.12.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Vector3.h"
#include"Nullable.h"
#include"IDiagram.h"
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
			/// 3DのAABB
			/// </summary>
			class AABB :
				public IDiagram
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				AABB();
				AABB(const Utility::Vector3& _Min, const Utility::Vector3& _Max);
				~AABB() = default;

				AABB(const AABB&) = default;
				AABB(AABB&&) = default;

				AABB& operator=(const AABB&) = default;
				AABB& operator=(AABB&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				Utility::Vector3 GetNearByNormal(const Utility::Vector3&);
				Utility::Vector3 GetFarByNormal(const Utility::Vector3&);

				/// <summary>
				/// 中心座標更新
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
				/// 内外判定
				/// 値を持っていれば外
				/// 持っていなければ内
				/// </summary>
				Utility::Nullable<float> IsInside(const Utility::Vector3&);

				/// <summary>
				/// 中心座標を演算する
				/// </summary>
				Utility::Vector3 CalculateOfCenter();

				/// <summary>
				/// 初期状態に戻す
				/// 領域(-1-1-1~1,1,1)
				/// </summary>
				void Initialize() override;


				AABB operator+(const Utility::Vector3&)const;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_Min, Min, Utility::Vector3);
				PROPERTY_REF(m_Max, Max, Utility::Vector3);

				PROPERTY_CR_R_ONLY(m_Min, Min, Utility::Vector3);
				PROPERTY_CR_R_ONLY(m_Max, Max, Utility::Vector3);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				Utility::Vector3	m_Min;
				Utility::Vector3	m_Max;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------