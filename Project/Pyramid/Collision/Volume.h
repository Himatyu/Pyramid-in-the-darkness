/**
* @file		Volume.h
* @brief	è’ìÀîÕàÕ
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Vector3.h"
#include"Nullable.h"
#include"IVolume.h"
#include"../Common/Diagram/Converter/ConvertProvider.h"
#include"../Common/Diagram/OBB.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
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
		/// è’ìÀîÕàÕ
		/// </summary>
		template<class Diagram>
		class Volume :
			public IVolume
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			Volume(Detail::ICollidee*);
			~Volume() = default;

			Volume(const Volume&) = default;
			Volume(Volume&&) = default;

			Volume& operator=(const Volume&) = default;
			Volume& operator=(Volume&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// TransfromÇîΩâfÇ≥ÇπÇÈ
			/// </summary>
			Common::Diagram::OBB ToSV() override;

			/// <summary>
			/// TransfromÇîΩâfÇ≥ÇπÇÈ
			/// </summary>
			void ReflectionOfTransfrom(Common::Sp<Components::Transform>&) override;

#pragma endregion

#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_REF(m_BV, BV, Diagram);
			PROPERTY_REF(m_ScaledBV, ScaledBV, Diagram);
#pragma endregion

#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
		protected:
			Diagram				m_BV;
			Diagram				m_ScaledBV;
#pragma endregion
		};
#include"Volume.inl"

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------