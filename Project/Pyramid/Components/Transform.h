/**
* @file		Transform.h
* @brief	位置・親子情報を持つコンポーネント
* @author	S.OIKAWA
* @date		2016.05.09
* @date		2016.05.26 デフォルトコピー・ムーブ追加
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Components/Component.h"
#include"../Utility/Vector3.h"
#include"../MT/Order/TaskOrder.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace GameObject
	{
		class Object;
	}
}

namespace Pyramid
{
	namespace Components
	{
		/// <summary>
		/// 位置・親子情報を持つコンポーネント
		/// </summary>
		class Transform :
			public Component,
			private MT::Order::TaskOrder<Transform>
		{
		public:
			//-----------------------------------------------------------
			// ctor.dtor
			//-----------------------------------------------------------
			Transform();
			virtual ~Transform() = default;

			Transform(const Transform &) = default;
			Transform(Transform&&) = default;

			Transform& operator=(const Transform&) = default;
			Transform& operator=(Transform&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			/// <summary>
			/// 非同期更新.
			/// </summary>
			virtual void AsyncUpdata();

			/// <summary>
			/// 更新
			/// </summary>
			virtual void Updata() override;

			/// <summary>
			/// 初期化
			/// </summary>
			virtual void Init() override;

		private:
			void PositionUpdate(D3DXMATRIX& _mat);
			void RotateUpdate(D3DXMATRIX& _mat);
			void ScaleUpdate(D3DXMATRIX& _mat);

		public:
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_REF(m_Position, Position, Utility::Vector3);
			PROPERTY_REF(m_Rotation, Rotation, Utility::Vector3);
			PROPERTY_REF(m_Scale, Scale, Utility::Vector3);

			PROPERTY_REF_R_ONLY(m_Right, Right, Utility::Vector3);
			PROPERTY_REF_R_ONLY(m_Up, Up, Utility::Vector3);
			PROPERTY_REF_R_ONLY(m_Forward, Forward, Utility::Vector3);

			PROPERTY_REF_R_ONLY(m_Velocity, Velocity, Utility::Vector3);

			PROPERTY(m_pParent, pParent, GameObject::Object*);

			PROPERTY_REF(m_matWorld, MatWorld, D3DXMATRIX);
			PROPERTY_REF(m_matRotate, MatRotate, D3DXMATRIX);

			PROPERTY_REF(m_IsPositionInherited, IsPositionInherited, bool);
			PROPERTY_REF(m_IsRotationInherited, IsRotationInherited, bool);	
			
			PROPERTY_REF(m_IsFixingPosition, IsFixingPosition, bool);
			PROPERTY_REF(m_IsFixingRotate, IsFixingRotate, bool);
			PROPERTY_REF(m_IsFixingScale, IsFixingScale, bool);

			//-----------------------------------------------------------
			// Val
			//-----------------------------------------------------------
		private:
			D3DXMATRIX				m_matWorld;
			D3DXMATRIX				m_matRotate;

			Utility::Vector3		m_Forward;
			Utility::Vector3		m_Up;
			Utility::Vector3		m_Right;

			Utility::Vector3		m_Position;
			Utility::Vector3		m_Rotation;
			Utility::Vector3		m_Scale;

			Utility::Vector3		m_Velocity;
			Utility::Vector3		m_BeforePosition;

			Utility::Vector3		m_InheritedPosition;
			Utility::Vector3		m_InheritedRotation;
		
			GameObject::Object*		m_pParent = nullptr;

			bool					m_IsPositionInherited = true;
			bool					m_IsRotationInherited = true;

			bool					m_IsFixingPosition	= false;
			bool					m_IsFixingRotate	= false;
			bool					m_IsFixingScale		= false;

		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------