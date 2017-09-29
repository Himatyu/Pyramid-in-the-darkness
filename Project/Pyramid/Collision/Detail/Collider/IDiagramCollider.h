/**
* @file		IDiagramCollider.h
* @brief	抽象図形衝突クラス
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICollider.h"
#include"../Defines.h"
#include"../ICollidee.h"
#include"../Collision/Volume.h"
#include"../Components/Transform.h"
#include<typeindex>
#include<utility>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			namespace Collider
			{
				/// <summary>
				/// 抽象図形衝突クラス
				/// Colliderが行うキャストなどを定義
				/// </summary>
				template<class Diagram1, class Diagram2>
				class IDiagramCollider :
					public ICollider
				{
				public:

					template<class Ty1, class Ty2>
					using CollideePair = std::pair<Ty1, Ty2>;
					
					using CastedPair = std::pair
						<
						Volume<Diagram1>*,
						Volume<Diagram2>*
						>;
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					IDiagramCollider();
					virtual ~IDiagramCollider() = default;

					IDiagramCollider(const IDiagramCollider&) = default;
					IDiagramCollider(IDiagramCollider&&) = default;

					IDiagramCollider& operator=(const IDiagramCollider&) = default;
					IDiagramCollider& operator=(IDiagramCollider&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// 実際の型にキャストする
					/// </summary>
					std::pair
						<
						Volume<Diagram1>*,
						Volume<Diagram2>*
						> CastToVolume(IVolume*, IVolume*);

					/// <summary>
					/// HitResultを作成する
					/// </summary>
					ResultPair CreateHitResultFromCastedPair(CastedPair&);
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
				};
#include"IDiagramCollider.inl"
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------