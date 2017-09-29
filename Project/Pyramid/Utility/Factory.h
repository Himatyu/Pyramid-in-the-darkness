/**
* @file		Factory.h
* @brief	�I�u�W�F�N�g�A�R���|�[�l���g�x�[�X
* @author	S.OIKAWA
* @date		2016/2/19
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<map>
#include<string>
#include<typeindex>
#include"singleton.h"
#include"Creator.h"
#include"Exception.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	/// <summary>
	/// �I�u�W�F�N�g�E�R���|�[�l���g�̃t�@�N�g��
	/// �I�u�W�F�N�g�E�R���|�[�l���g�̎q��������
	/// </summary>
	/// <typeparam name="Base">�����^</typeparam>
	template<class Base>
	class Factory :
		public Singleton<Factory<Base>>
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------

		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		Factory() = default;

		/// <summary>
		/// �R�s�[�R���X�g���N�^:�폜
		/// </summary>
		Factory(const Factory&) = delete;

		/// <summary>
		/// ���[�u�R���X�g���N�^�F�폜
		/// </summary>
		Factory(Factory&&) = delete;

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~Factory();

		//-----------------------------------------------------------
		// operators
		//-----------------------------------------------------------

		/// <summary>
		/// �R�s�[�֎~
		/// </summary>
		Factory& operator = (const Factory&) = delete;

		/// <summary>
		/// ���[�u�֎~
		/// </summary>
		Factory& operator = (Factory&&) = delete;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>����</summary>
		///<returns>���������Child�|�C���^.���s��nullptr</returns>
		///<typeparam name="Child">�����^</typeparam>
		/// <remarks>
		/// Child�^�𐶐�����N���G�C�^�[��o�^���Ă��邱�ƁB
		/// Child��Base�̌p����ł���
		/// </remarks>
		template <class Child>
		Child Create();

		/// <summary>����</summary>
		///<param name = "_type">�����^</param>
		///<remarks>
		/// �قڃR�s�[�p�B
		/// �`����n���Γo�^���Ă���N���G�C�^�[�Ő���
		/// </remarks>
		Base Create(std::type_index _type);

		/// <summary>�N���G�C�^�[�o�^</summary>
		///<param name="_pCreator">�N���G�C�^�[�|�C���^</param>
		///<typeparam name="Type">�����^</typeparam>
		///<returns>�o�^������true ���s��false</returns>
		template <class CreaterType>
		bool Register();

		/// <summary>�N���G�C�^�[���������Ă邩</summary>
		///<param name = "_type">�����^</param>
		///<returns>�o�^�ς�:true ���o�^:false</returns>
		bool HasType(std::type_index _type);

		/// <summary>
		/// �N���G�C�^�[���������Ă邩
		/// </summary>
		/// <typeparam name="Type">�����^</typeparam>
		template <class Type>
		bool HasType();

		/// <summary>Map���󂩊m�F</summary>
		///<returns>��:true �v�f����:false</returns>
		bool IsEmpty();

		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
	private:
		/// <summary>
		/// �����֐��}�b�v
		/// </summary>
		using CreatorMap = std::map<std::type_index, Creator<Base>*>;
		CreatorMap m_CreatorMap;

	};

#include"Factory.inl"
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------