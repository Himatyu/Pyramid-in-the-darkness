/**
* @file		ObjectStateSubject.h
* @brief	�I�u�W�F�N�g�̏�ԁi�L���E�`��j��Observer�ɒʒm.
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
			/// �I�u�W�F�N�g�̏�Ԃ�ʒm.
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
				/// �Ď��ғo�^
				/// </summary>	
				void Attach(ObjectStateObserver* _obser);

				/// <summary>
				/// �Ď��ҍ폜
				/// </summary>
				void Detach(ObjectStateObserver* _obser);

				/// <summary>
				/// �ʒm
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