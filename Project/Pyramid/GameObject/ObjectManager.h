/**
* @file		ObjectManager.h
* @brief	�I�u�W�F�N�g�Ǘ�
* @author	S.OIKAWA
* @date		2016.04.27
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include<array>
#include"SafetyIterate.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace GameObject
	{
		namespace Observers
		{
			class ObjectStateObserver;
			enum SubjectId : int
			{
				EffectiveState = 0,
				PriorityState,
				UpdataState,
				DrawState,
				SubjectMax
			};

			using ObjectObservers =
				std::array<ObjectStateObserver*, SubjectId::SubjectMax>;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace GameObject
	{
		class Object;

		/// <summary> 
		///�I�u�W�F�N�g�Ǘ��p�N���X.
		///�I�u�W�F�N�g�̊J���ӔC�͂Ȃ�.
		/// Updata,Draw���̃C�e���[�^�ύX���뜜�����̂�SafetyIterate
		/// </summary>
		class ObjectManager final
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			ObjectManager();
			~ObjectManager();

			ObjectManager(const ObjectManager&) = delete;
			ObjectManager(ObjectManager&&) = delete;

			ObjectManager& operator=(const ObjectManager&) = delete;
			ObjectManager& operator=(ObjectManager&&) = delete;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// �I�u�W�F�N�g�̓o�^.
			/// ���d�o�^���Ȃ�.
			/// </summary>
			void Register(Object* _pObj, bool _isDynamic = false);

			/// <summary>
			/// �o�^����.
			/// </summary>
			void UnRegist(Object* _pObj);

			/// <summary>
			/// �I�u�W�F�N�g�X�V.
			/// </summary>
			void CallUpdatas();

			/// <summary>
			/// �I�u�W�F�N�g�`��
			/// </summary>
			void CallPreDraw();

			___DEBUG_DEFINE
			(
				private: 
					void DebugUpdata(std::vector<Object*>);
				public:
			);

#pragma endregion

#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_REF(m_AllObjects, AllObjects, std::list<Object*>);
			PROPERTY_REF(m_DynamicObjects, DynamicObjects, std::list<Object*>);
			PROPERTY_REF(m_UpdatableObjects, UpdatableObjects, Utility::SafetyIterate<Object*>);
			PROPERTY_REF(m_DrawbleObjects, DrawbleObjects, Utility::SafetyIterate<Object*>);
			PROPERTY_REF(m_ObjectStateObservers, ObjectStateObservers, Observers::ObjectObservers);

#pragma endregion
		private:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			std::list<Object*>					m_AllObjects;
			std::list<Object*>					m_DynamicObjects;
			Utility::SafetyIterate<Object*>		m_UpdatableObjects;
			Utility::SafetyIterate<Object*>		m_DrawbleObjects;
			Observers::ObjectObservers			m_ObjectStateObservers;

#pragma endregion

		};

	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------