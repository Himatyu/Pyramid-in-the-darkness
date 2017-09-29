/**
* @file		ComponentStateObserver.cpp
* @brief	�R���|�[�l���g�̏�Ԃ��Ď�����
* @author	S.OIKAWA
* @date		2016.09.20
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentStateObserver.h"
#include"../GameObject/Object.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		namespace Observers
		{

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ComponentStateObserver::
				ComponentStateObserver(GameObject::Object& _pObj) :
				m_pOwner(&_pObj)
			{
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
