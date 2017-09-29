/**
* @file		IDiagramCollider.h
* @brief	���ې}�`�Փ˃N���X
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
				/// ���ې}�`�Փ˃N���X
				/// Collider���s���L���X�g�Ȃǂ��`
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
					/// ���ۂ̌^�ɃL���X�g����
					/// </summary>
					std::pair
						<
						Volume<Diagram1>*,
						Volume<Diagram2>*
						> CastToVolume(IVolume*, IVolume*);

					/// <summary>
					/// HitResult���쐬����
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