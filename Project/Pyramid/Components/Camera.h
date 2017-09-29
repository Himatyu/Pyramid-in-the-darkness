/**
* @file		Camera.h
* @brief	カメラ
* @author	S.OIKAWA
* @date		2016.05.26
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<d3dx9.h>
#include<memory>
#include"../Components/Component.h"
#include"../Rendering/Viewer.h"
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
		class Transform;

		/// <summary>
		/// カメラ.
		/// </summary>
		class Camera :
			public Rendering::Viewer,
			public Component,
			private MT::Order::TaskOrder<Camera>
		{
		public:
			//-----------------------------------------------------------
			// ctor.dtor 
			//-----------------------------------------------------------
			Camera();
			virtual ~Camera();

			Camera(const  Camera&) = default;
			Camera(Camera&&) = default;

			Camera& operator=(const Camera&) = default;
			Camera& operator=(Camera&&) = default;

			//-----------------------------------------------------------
			// function 
			//-----------------------------------------------------------
			void AsyncUpdata();
			virtual	void Updata()		override;

			virtual void Init()	override;

			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------

			PROPERTY(m_LockTarget, LockAt, std::shared_ptr<Transform>);

			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
		protected:


			std::shared_ptr<Transform>	m_LockTarget = nullptr;	//視点ロックターゲット
			std::shared_ptr<Transform>	m_spObjectTransform = nullptr;
		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
