/**
* @file		ICollidee.h
* @brief	抽象衝突対象クラス
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<map>
#include<vector>
#include<memory>
#include"ColliderManager.h"
#include"CacheableTransform.h"
#include"CollisionInformation.h"
#include"../Components/Transform.h"
#include"../CollisionDetection.h"
#include"../HitResult.h"
#include"ICastable.h"
#include"TypeComparable.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		class IVolume;
		namespace Detail
		{
			class HitEventPublisher;
			class CollisionProvider;
			using CollisionPartners = 
				std::map<ICollidee*, CollisionInformation>;
			namespace Collider
			{
				class ICollider;
			}

			namespace Tester
			{
				class TesterOfDiscreet;
				class TesterOfSVT;
			}
		}
	}
	namespace GameObject
	{
		class Object;
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
			/// 抽象衝突対象クラス
			/// イベントの発生に必要なパラメータを持つ
			/// </summary>
			class ICollidee : 
				public IHitEvent
			{
				friend class HitEventPublisher;
				friend class CollisionProvider;
				friend class Tester::TesterOfDiscreet;
				friend class Tester::TesterOfSVT;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ICollidee() = default;
				~ICollidee() = default;

				ICollidee(const ICollidee&) = default;
				ICollidee(ICollidee&&) = default;

				ICollidee& operator=(const ICollidee&) = default;
				ICollidee& operator=(ICollidee&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				///	トランスフォームの更新・キャッシュ
				/// </summary>
				void UpdateTransform(Common::Sp<Components::Transform>&);
				
#pragma endregion
				
#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_IsPreparatdForEventPublish, IsPreparatdForEventPublish, bool);
				PROPERTY_REF(m_IsPublishedEventOfExit, IsPublishedEventOfExit, bool);
				PROPERTY_REF(m_CollisionDetection, Precision, CollisionDetection);
				PROPERTY_REF_R_ONLY(m_BVList, BVList, std::vector< Common::Sp<IVolume>>);
				PROPERTY_REF_R_ONLY(m_spTransform,
					spTransform, Common::Sp<Components::Transform>);
				PROPERTY_REF_R_ONLY(m_DataOfTheCollisionPartners,
					Partners, CollisionPartners);
#pragma endregion
			protected:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				bool m_IsPreparatdForEventPublish				= false;
				bool m_IsPublishedEventOfExit					= false;
				CollisionDetection								m_CollisionDetection;
				CollisionPartners								m_DataOfTheCollisionPartners;
				Common::Sp<Components::Transform>				m_spTransform;
				std::vector< Common::Sp<IVolume>>				m_BVList;//arrayだとtemplateクラスになるから
				CacheableTransform								m_CacheOfThisFream;
				CacheableTransform								m_CacheOfPrevFream;
#pragma endregion
			};

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------