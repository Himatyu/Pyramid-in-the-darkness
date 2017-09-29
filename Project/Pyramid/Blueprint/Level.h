/**
* @file		Level.h
* @brief	���x���x�[�X
* @author	S.OIKAWA
* @date		2016/07/28
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TimerClient.h"
#include"../GameObject/ObjectManager.h"
#include"../GameObject/Object.h"
#include"../Utility/Factory.h"
#include"../Utility/Nullable.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{

		/// <summary>
		/// ���x���u���[�v�����g�݂����Ȉ���
		/// </summary>
		class Level
		{
		public:
			//-----------------------------------------------------------
			// defalult
			//-----------------------------------------------------------
			Level();
			virtual ~Level();

			Level(const Level&) = default;
			Level(Level&&) = default;

			Level& operator=(const Level&) = default;
			Level& operator=(Level&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			/// <summary>
			/// �X�V.
			/// </summary>
			virtual void Updata();

			/// <summary>
			/// �`��.
			/// </summary>
			virtual void Draw();

			/// <summary>
			/// �I�u�W�F�N�g���̉�.
			/// </summary>
			template <class Type, class... Param>
			Type& Instantiate(Param&&... param);

			/// <summary>
			/// �I�u�W�F�N�g�j��.
			/// </summary>
			/// <param name="_pObj">�j��I�u�W�F�N�g</param>
			void Destory(GameObject::Object* _pObj);

			/// <summary>
			/// �^�O����.
			/// </summary>
			/// <param name="_tag">�^�O</param>
			/// <returns>���ʃ|�C���^.�Ȃ����nullptr.</returns>
			Utility::Nullable<GameObject::Object*> FindWithTag(std::string _tag);

			/// <summary>
			/// �^�O����.����.
			/// </summary>
			/// <param name="_tag">�^�O</param>
			/// <returns>���ʃx�N�g��.</returns>
			Utility::Nullable<std::vector<GameObject::Object*>> FindObjectsWithTag(std::string _tag);

			/// <summary>
			/// �^����
			/// </summary>
			template<class TY>
			Utility::Nullable<GameObject::Object*> FindWithType();
			
			/// <summary>
			/// �^�����A����
			/// </summary>
			template<class Ty>
			Utility::Nullable<std::vector<GameObject::Object*>>
				FindObjectsWithType();

			//-----------------------------------------------------------
			// property 
			//-----------------------------------------------------------
			PROPERTY_REF_R_ONLY(m_ObjectManager, ObjectManager, GameObject::ObjectManager);

		protected:
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			GameObject::ObjectManager m_ObjectManager;

		};
#include"Level.inl"
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

