/**
* @file		WorldVolume.h
* @brief	���[���h��Ԃ̃{�����[��
* @author	S.OIKAWA
* @date		2017.01.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Common/Diagram/AABB.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	class Vector3;
}

#pragma endregion
namespace Pyramid
{
	namespace Common
	{
		/// <summary>
		/// ���[���h��Ԃ̃{�����[��
		/// ������J�����O��A�����ؓo�^�̍ۂɎg�p
		/// </summary>
		class WorldVolume
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			WorldVolume();
			WorldVolume(Common::Diagram::AABB&,Utility::Vector3*);
			~WorldVolume() = default;

			WorldVolume(const WorldVolume&) = default;
			WorldVolume(WorldVolume&&) = default;

			WorldVolume& operator=(const WorldVolume&) = default;
			WorldVolume& operator=(WorldVolume&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			Common::Diagram::AABB CalculatWorldVolume() const;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
			PROPERTY_REF(m_Volume, Volume, Common::Diagram::AABB);
			PROPERTY(m_pPosition, pPosition, Utility::Vector3*);
#pragma endregion
		private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			Common::Diagram::AABB			m_Volume;
			Utility::Vector3*		m_pPosition = nullptr;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------