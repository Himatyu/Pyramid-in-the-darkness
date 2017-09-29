/**
* @file		CacheableTransform.h
* @brief	コリジョンに使用するトランスフォームをキャッシュする
* @author	S.OIKAWA
* @date		2017.05.03
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Vector3.h"
#include"../Common/Defines.h"
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
	namespace Collision
	{
		namespace Detail
		{
			/// <summary>
			/// キャッシュ用にデータを削ったトランスフォーム
			/// トンネリング対策に使用する			
			/// </summary>
			class CacheableTransform
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				CacheableTransform(Components::Transform*);
				CacheableTransform() = default;
				~CacheableTransform() = default;

				CacheableTransform(const CacheableTransform&) = default;
				CacheableTransform(CacheableTransform&&) = default;

				CacheableTransform& operator=(Common::Sp<Components::Transform>&);
				CacheableTransform& operator=(const CacheableTransform&) = default;
				CacheableTransform& operator=(CacheableTransform&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY_REF(m_Position,	Position,	Utility::Vector3);
				PROPERTY_REF(m_Scale,		Scale,		Utility::Vector3);
				PROPERTY_REF(m_Rotate,		Rotation,	Utility::Vector3);
#pragma endregion
			private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				Utility::Vector3	m_Position;
				Utility::Vector3	m_Scale;
				Utility::Vector3	m_Rotate;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------