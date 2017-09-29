/**
* @file		IVolume.h
* @brief	���ۏՓː}�`
* @author	S.OIKAWA
* @date		2017.04.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICastable.h"
#include"TypeComparable.h"
#include"../Common/Defines.h"
#include"../Common/Diagram/OBB.h"
#include"Detail/CacheableTransform.h"
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
	namespace Collision
	{
		namespace Detail
		{
			class ICollidee;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		/// <summary>
		/// ���ۏՓː}�`
		/// Colider�̌�����Colider���ł̏Փː}�`�ւ̃L���X�g���s��
		/// </summary>
		class IVolume :
			public Utility::ICastable,
			public Utility::TypeComparable
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			IVolume(Detail::ICollidee*);
			~IVolume() = default;

			IVolume(const IVolume&) = default;
			IVolume(IVolume&&) = default;

			IVolume& operator=(const IVolume&) = default;
			IVolume& operator=(IVolume&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// SV�𐶐�����
			/// </summary>
			virtual Common::Diagram::OBB ToSV() = 0;

			/// <summary>
			/// Transform�̔��f���s��
			/// </summary>
			virtual void ReflectionOfTransfrom(Common::Sp<Components::Transform>&) = 0;
#pragma endregion

#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_R_ONLY(m_pCollidee, pCollidee, Detail::ICollidee*);
			PROPERTY_REF(m_spTransform, spTransform,
				Common::Sp<Components::Transform>);
			PROPERTY_REF(m_Offset, Offset, Detail::CacheableTransform);
#pragma endregion
		protected:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			Detail::ICollidee*						m_pCollidee;
			Common::Sp<Components::Transform>		m_spTransform;
			Detail::CacheableTransform				m_Offset;
#pragma endregion

		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------