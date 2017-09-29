/**
* @file		ObjectStateObserver.h
* @brief	�I�u�W�F�N�g�̏�ԕύXSubject����󂯎��.
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
			/// ��Ԓʒm��M�̒��ۃN���X.
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
				/// �ύX�ʒm����A
				/// �ύX�㌟�m��O��Ƃ��Ă�̂őO��̔�r���ł��Ȃ�
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