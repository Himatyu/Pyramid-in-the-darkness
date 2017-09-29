#include "Volume.h"
/**
* @file		Volume.inl
* @brief	�Փ˔͈�
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// ctor
/// </summary>
template<class Diagram>
inline 
Volume<Diagram>::Volume(Detail::ICollidee * _pCollidee):
	IVolume(_pCollidee)
{
	TypeApply<Diagram>();
}

/// <summary>
/// ToSV
/// </summary>
template<class Diagram>
inline 
Common::Diagram::OBB Volume<Diagram>::ToSV()
{	
	auto& ins = 
		Common::Diagram::Converter::ConvertProvider::Instantiate();

	auto result = 
		ins.Convert<Diagram,Common::Diagram::OBB>(m_BV);
	return result.Value;
}

/// <summary>
/// ToSV : OBB����
/// </summary>
template<>
inline
Common::Diagram::OBB Volume<Common::Diagram::OBB>::ToSV()
{
	return m_BV;
}

/// <summary>
/// Transfrom�𔽉f������
/// </summary>
template<class Diagram>
inline
void 
Volume<Diagram>::ReflectionOfTransfrom(
	Common::Sp<Components::Transform>& _sp)
{
	m_spTransform = _sp;
	m_BV.ReflectionOfTransfrom(_sp);

	m_BV.MoveTo(m_Offset.Position + _sp->Position);
	m_BV.RotateTo(m_Offset.Rotation + _sp->Rotation);
	m_ScaledBV = m_BV;

	//�X�P�[�����O���Ȃ��I�u�W�F�N�g�������C������
	if (Utility::Vector3::once == _sp->Scale)
	{
		return;
	}

	m_ScaledBV.ScaleTo(_sp->Scale);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------