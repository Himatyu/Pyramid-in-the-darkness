/**
* @file		UITransform.h
* @brief	UIの座標・サイズ・回転と親子関係を持つ
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Vector2.h"
#include"Vector3.h"
#include"Manager.h"
#include<d3dx9.h>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//----------------------------------------------------------
namespace Pyramid
{
	namespace UI
	{
		class IUI;
	}
	namespace Rendering
	{
		namespace ComponentRender
		{
			class UIRender;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace UI
	{
		/// <summary>
		/// UIの座標・サイズ・回転と親子関係を持つ
		/// </summary>
		class UITransform :
			::Utility::Manager<::std::vector<IUI*>>
		{
			friend class IUI;
			friend class Rendering::ComponentRender::UIRender;
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			UITransform(IUI&);
			~UITransform() = default;

			UITransform(const UITransform&) = default;
			UITransform(UITransform&&) = default;

			UITransform& operator=(const UITransform&) = default;
			UITransform& operator=(UITransform&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// 追加
			/// </summary>
			void AddChild(IUI&);

			/// <summary>
			/// 削除
			/// 開放は行わない
			/// </summary>
			void RemoveChild(IUI&);

		private:
			/// <summary>
			/// 深度と親子関係を更新する
			/// </summary>
			void UpdataDepthAndParentOffset();

			/// <summary>
			/// レンダリング用のワールド行列を作成する
			/// </summary>
			D3DXMATRIX CalculatWorldMatrix();

#pragma endregion

#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
		public:
			PROPERTY_REF(m_Position, Position, ::Utility::Vector3);
			PROPERTY_REF(m_Size, Size, ::Utility::Vector2);
			PROPERTY_REF(m_Scale, Scale, ::Utility::Vector2);
			PROPERTY(m_RotateZ, RotateZ, float);

			PROPERTY_REF(m_ParentsPosition, ParentsPosition, ::Utility::Vector3);
			PROPERTY_REF(m_ParentsSize, ParentsSize, ::Utility::Vector2);
			PROPERTY_REF(m_ParentsScale, ParentsScale, ::Utility::Vector2);
			PROPERTY(m_ParentsRotateZ, ParentsRotateZ, float);

			PROPERTY(m_pParent, pParent, IUI*);
#pragma endregion

#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
		private:
			::Utility::Vector3		m_Position;
			::Utility::Vector2		m_Size;
			::Utility::Vector2		m_Scale;
			float					m_RotateZ = 0.0f;

			::Utility::Vector3		m_ParentsPosition;
			::Utility::Vector2		m_ParentsSize;
			::Utility::Vector2		m_ParentsScale;
			float					m_ParentsRotateZ = 0.0f;

			IUI*					m_pParent = nullptr;
			IUI&					m_Owner ;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------