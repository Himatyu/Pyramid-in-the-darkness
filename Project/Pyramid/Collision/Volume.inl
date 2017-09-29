#include "Volume.h"
/**
* @file		Volume.inl
* @brief	衝突範囲
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
/// ToSV : OBB特殊
/// </summary>
template<>
inline
Common::Diagram::OBB Volume<Common::Diagram::OBB>::ToSV()
{
	return m_BV;
}

/// <summary>
/// Transfromを反映させる
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

	//スケーリングしないオブジェクトが多い気がする
	if (Utility::Vector3::once == _sp->Scale)
	{
		return;
	}

	m_ScaledBV.ScaleTo(_sp->Scale);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------