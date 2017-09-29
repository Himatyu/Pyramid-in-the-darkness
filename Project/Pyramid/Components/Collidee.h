/**
* @file		Collidee.h
* @brief	�Փ˔�����󂯂�
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
		/// �Փ˔�����󂯂�
		/// �Փː}�`���ϒ��e���v���[�g�Ŏw��i���̍�Volume�͎����ǉ������̂ł���Ȃ��j
		/// �f�o�b�N���̏Փ˃��f���͐��m�ł͂Ȃ��̂Œ���
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
			/// ���������s��
			/// �Փː}�`�̏��������s���̂�Transform��v������
			/// </summary>
			void Init(Common::Sp<Transform>&);

			/// <summary>
			/// �Փ˗v�����s��
			/// ���ۂɏՓ˃C�x���g����������
			/// </summary>
			void Updata() override;
			
			/// <summary>
			/// �Փː}�`���擾����
				///<example>
					///<code>
					/// auto pVolume = ins.AccessOfVolumeForIndex(0);
					///</code>
				///</example>
			/// </summary>
			Collision::IVolume* AccessOfVolumeForIndex(UINT);

			/// <summary>
			/// �Փː}�`���擾����
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
			/// �C�x���g�̃����[���s��
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