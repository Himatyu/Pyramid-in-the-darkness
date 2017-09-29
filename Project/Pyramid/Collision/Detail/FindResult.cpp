/**
* @file		FindResult.cpp
* @brief	é„éQè∆Ç…ïœä∑â¬î\Ç»åüçıåãâ 
* @author	S.OIKAWA
* @date		2017.04.21
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"FindResult.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			FindResult::FindResult(
				Collider::ICollider * _pCollider,
				Common::Sp<IVolume>& _spLVolume,
				Common::Sp<IVolume>& _spRVolume):
				m_spIVolumeL(_spLVolume),
				m_spIVolumeR(_spRVolume),
				m_pCollider(_pCollider)
			{
			}

			//-----------------------------------------------------------
			// cctor
			//-----------------------------------------------------------
			FindResult::FindResult(const FindResult & _other):
				m_spIVolumeL(_other.m_spIVolumeL),
				m_spIVolumeR(_other.m_spIVolumeR),
				m_pCollider(_other.m_pCollider)
			{
			}

			//-----------------------------------------------------------
			// =
			//-----------------------------------------------------------
			FindResult & FindResult::operator=(const FindResult & _other)
			{
				m_spIVolumeL = _other.m_spIVolumeL;
				m_spIVolumeR = _other.m_spIVolumeR;
				m_pCollider = _other.m_pCollider;
				return *this;
			}

			//-----------------------------------------------------------
			// Convert
			//-----------------------------------------------------------
			FindResult::ForLog FindResult::ConvertItForRegistration()
			{
				return ForLog(m_pCollider, m_spIVolumeL, m_spIVolumeR);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------