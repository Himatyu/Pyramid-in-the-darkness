/**
* @file		ScriptableObject.inl
* @brief	固定値データをもつ
* @author	S.OIKAWA
* @date		2017.5.12
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
template<class _Ty>
inline ScriptableObject<_Ty>::ScriptableObject() :
	IDataObjectFile(sizeof(_Ty),&m_Data)
{
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------