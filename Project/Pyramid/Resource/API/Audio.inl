/**
* @file		Audio.inl
* @brief	AudioAPI
* @author	S.OIKAWA
* @date		2016.08.25
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Audio.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

//-----------------------------------------------------------
// Play
//-----------------------------------------------------------
template<class Type>
inline void Audio<Type>::Play(int _loopCount)
{
	m_spResourceFile->Play(_loopCount);
}

//-----------------------------------------------------------
// Stop 
//-----------------------------------------------------------
template<class Type>
inline void Audio<Type>::Stop()
{
	m_spResourceFile->Stop();
}

//-----------------------------------------------------------
// Pause 
//-----------------------------------------------------------
template<class Type>
inline void Audio<Type>::Pause()
{
	m_spResourceFile->Pause();
}

//-----------------------------------------------------------
// Resume
//-----------------------------------------------------------
template<class Type>
inline void Audio<Type>::Resume()
{
	m_spResourceFile->Resume();
}

//-----------------------------------------------------------
// SetVolum 
//-----------------------------------------------------------
template<class Type>
inline void Audio<Type>::SetVolume(float _volume)
{
	m_Volume = _volume;
	m_spResourceFile->ChangeVolume();
}

//-----------------------------------------------------------
// GetVolum 
//-----------------------------------------------------------
template<class Type>
inline float Audio<Type>::GetVolume()
{
	return m_Volume;
}

//-----------------------------------------------------------
// = shared_ptr<ResourceFileType>
//-----------------------------------------------------------
template<class Type>
inline void Audio<Type>::operator=(std::shared_ptr<Type> _sp)
{
	IResourceAPI<Type>::operator=(_sp);
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------