#include "IDiagramCollider.h"
/**
* @file		IDiagramCollider.inl
* @brief	Õ“Ë‚·‚é}Œ`“¯m‚ğ‚Â
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
template<class Diagram1, class Diagram2>
inline 
IDiagramCollider<Diagram1, Diagram2>::IDiagramCollider()
{
	m_Type1 = typeid(Diagram1);
	m_Type2 = typeid(Diagram2);
}

/// <summary>
/// ÀÛ‚ÌŒ^‚ÉƒLƒƒƒXƒg‚·‚é
/// </summary>
template<class Diagram1, class Diagram2>
inline 
std::pair
<
	Volume<Diagram1>*,
	Volume<Diagram2>*
>
IDiagramCollider<Diagram1, Diagram2>::CastToVolume(
		IVolume* _pDiagram1,
		IVolume* _pDiagram2)
{
	return
		std::make_pair(
			_pDiagram1->CastTo<Volume<Diagram1>*>(),
			_pDiagram2->CastTo<Volume<Diagram2>*>());
}

/// <summary>
/// HitResult‚ğ¶¬‚·‚é
/// </summary>
template<class Diagram1, class Diagram2>
inline 
ResultPair
IDiagramCollider<Diagram1, Diagram2>::
CreateHitResultFromCastedPair(CastedPair & _pair)
{
	HitResult
		resultOf1
	{
		_pair.second->spTransform,
		_pair.second->spTransform->pOwner
	},
		resultOf2
	{
		_pair.first->spTransform,
		_pair.first->spTransform->pOwner
	};

	return 
		std::make_pair(resultOf1, resultOf2);
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------