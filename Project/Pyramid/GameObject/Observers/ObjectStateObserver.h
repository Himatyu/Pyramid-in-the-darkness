/**
* @file		ObjectStateObserver.h
* @brief	オブジェクトの状態変更Subjectから受け取る.
* @author	S.OIKAWA
* @date		2016.09.19
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
namespace Pyramid
{
	namespace GameObject
	{
		class ObjectManager;

		namespace Observers
		{
			class ObjectStateSubject;
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
			/// 状態通知受信の抽象クラス.
			/// </summary>
			class ObjectStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ObjectStateObserver(ObjectManager& _mgr);
				~ObjectStateObserver() = default;

				ObjectStateObserver(const ObjectStateObserver&) = default;
				ObjectStateObserver(ObjectStateObserver&&) = default;

				ObjectStateObserver& operator=(const ObjectStateObserver&) = default;
				ObjectStateObserver& operator=(ObjectStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 変更通知する、
				/// 変更後検知を前提としてるので前後の比較ができない
				/// </summary>
				/// <param name="_ChangedSubject"></param>
				virtual	void OnEvent(ObjectStateSubject* _ChangedSubject) = 0;

#pragma endregion

#pragma region value
			protected:
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				ObjectManager& m_ObjectManager;
#pragma endregion
			};

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------