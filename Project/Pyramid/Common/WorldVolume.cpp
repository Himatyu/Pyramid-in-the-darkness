/**
* @file		WorldVolume.cpp
* @brief	ワールド空間のボリューム
* @author	S.OIKAWA
* @date		2017.01.12
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"WorldVolume.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		WorldVolume::WorldVolume():
			m_Volume{Utility::Vector3::once*-1,Utility::Vector3::once}
		{
		}

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		WorldVolume::WorldVolume(
			Common::Diagram::AABB& _aabb, Utility::Vector3 * _pPosition):
			m_Volume(_aabb),
			m_pPosition(_pPosition)
		{
		}

		//-----------------------------------------------------------
		// CalculatWorldVolume
		//-----------------------------------------------------------
		Common::Diagram::AABB WorldVolume::CalculatWorldVolume() const
		{
			return m_Volume + *m_pPosition;
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------