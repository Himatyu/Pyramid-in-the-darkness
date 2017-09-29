/**
* @file		ObjectStateObserver.cpp
* @brief	ObjectStateObserverŽÀ‘•
* @author	S.OIKAWA
* @date		2016.09.19
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectStateObserver.h"
#include"../ObjectManager.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace GameObject
	{
		namespace Observers
		{

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ObjectStateObserver::
				ObjectStateObserver(ObjectManager& _mgr) :
				m_ObjectManager(_mgr)
			{
			}

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

