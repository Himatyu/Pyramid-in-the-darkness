/**
* @file		ObjectStateSubject.h
* @brief	オブジェクトの状態（有効・描画）をObserverに通知.
* @author	S.OIKAWA
* @date		2016.09.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace GameObject
	{
		class Object;
		namespace Observers
		{
			class ObjectStateObserver;
		}
	}
}

#pragma endregion
namespace Pyramid
{
	namespace GameObject
	{
		namespace Observers
		{
			/// <summary>
			/// オブジェクトの状態を通知.
			/// </summary>
			class ObjectStateSubject final
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ObjectStateSubject() = default;
				~ObjectStateSubject() = default;

				ObjectStateSubject(const ObjectStateSubject&) = default;
				ObjectStateSubject(ObjectStateSubject&&) = default;

				ObjectStateSubject& operator=(const ObjectStateSubject&) = default;
				ObjectStateSubject& operator=(ObjectStateSubject&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 監視者登録
				/// </summary>	
				void Attach(ObjectStateObserver* _obser);

				/// <summary>
				/// 監視者削除
				/// </summary>
				void Detach(ObjectStateObserver* _obser);

				/// <summary>
				/// 通知
				/// </summary>
				void Notify();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_pOwner, pOwner, Object*);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::vector<ObjectStateObserver*>	m_Observers;
				Object*								m_pOwner;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------