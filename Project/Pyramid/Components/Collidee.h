/**
* @file		Collidee.h
* @brief	衝突判定を受ける
* @author	S.OIKAWA
* @date		2017.03.05
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Collision/IVolume.h"
#include"../Collision/Volume.h"
#include"../Collision/Detail\CollisionEventListener.h"
#include"../Collision/Detail\ICollidee.h"
#include"../Collision/IHitEvent.h"
#include"../Collision/Detail\JudgmentSameSpaceOfCollidee.h"
#include"../Collision/Detail/CollisionSystem.h"
#include"../Collision/Detail\ColliderManager.h"
#include"../Components/Component.h"
#include"../Components/Transform.h"
#include"../Components/Mesh.h"
#include"../Common/Defines.h"
#include"../Common/WorldVolume.h"
#include"../Common/Diagram/AABB.h"
#include"../Common/Diagram/Sphere.h"
#include"../Common/Diagram/OBB.h"
#include"../Utility/TypeList.h"

#include "Constant.h"
#include "../Rendering/Materials/ColorChannel.h"
#include<type_traits>
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
		/// <summary>
		/// 衝突判定を受ける
		/// 衝突図形を可変長テンプレートで指定（その際Volumeは自動追加されるのでいらない）
		/// デバック時の衝突モデルは正確ではないので注意
		/// </summary>
		template<class ...Diagrams>
		class Collidee :
			public Components::Component,
			public Collision::Detail::CollisionEventListener,
			public Collision::Detail::ICollidee
		{
		public:
			using DiagramList = 
				typename Utility::ConvertToTypeList<Diagrams...>::Result;
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			Collidee();
			~Collidee();

			Collidee(const Collidee&) = default;
			Collidee(Collidee&&) = default;

			Collidee& operator=(const Collidee&) = default;
			Collidee& operator=(Collidee&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// 初期化を行う
			/// 衝突図形の初期化を行うのでTransformを要求する
			/// </summary>
			void Init(Common::Sp<Transform>&);

			/// <summary>
			/// 衝突要求を行う
			/// 実際に衝突イベントが発生する
			/// </summary>
			void Updata() override;
			
			/// <summary>
			/// 衝突図形を取得する
				///<example>
					///<code>
					/// auto pVolume = ins.AccessOfVolumeForIndex(0);
					///</code>
				///</example>
			/// </summary>
			Collision::IVolume* AccessOfVolumeForIndex(UINT);

			/// <summary>
			/// 衝突図形を取得する
				///<example>
					///<code>
					/// auto pVolume = ins.AccessOfCastedVolumeForIndex<0>();
					///</code>
				///</example>
			/// </summary>
			template<unsigned Index>
			Collision::Volume
			<
				typename Utility::ArgsAt
				< 
					Index,
					typename Utility::Args<Diagrams...>
				>::Result
			>*
				AccessOfCastedVolumeForIndex();

			/// <summary>
			/// イベントのリレーを行う
			/// </summary>
			void OnCollisionEnter(Collision::HitResult) override;
			void OnCollisionStay(Collision::HitResult)  override;
			void OnCollisionExit(Collision::HitResult)  override;

		private:
			template<class Diagram>
			void ParseRegister();

			___DEBUG_DEFINE
			(
				void AdditionalInit();
				void AdditionalUpdataOfDebug() override;
			)

#pragma endregion

#pragma region property
		public:
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY(m_IsStatic, IsStatic, bool);

#pragma endregion

#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
		private:
			Collision::Detail::JudgmentSameSpaceOfCollidee		m_Judgment;
			Common::WorldVolume									m_OctVolume;
			bool												m_IsStatic;
#pragma endregion

		};
#include"Collidee.inl"
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------