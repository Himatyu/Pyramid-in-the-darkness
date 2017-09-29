/**
* @file		Executer.h
* @brief	�^�X�N��ێ����āA���s�@�\���
* @author	S.OIKAWA
* @date		2016.09.21
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<functional>
#include"IExecuteable.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion
namespace Utility
{
	/// <summary
	/// �^�X�N��ێ����āA���s�@�\���
	/// </summary>
	template<class Type>
	class Executer :
		public IExecuteable
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		Executer() = default;
		~Executer();

		Executer(const Executer&) = default;
		Executer(Executer&&) = default;

		Executer& operator=(const Executer&) = delete;
		Executer& operator=(Executer&&) = delete;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// �W���u�o�^.
		/// ���łɓo�^�ς݂Ȃ�㏑������.
		/// </summary>
		template<class Func>
		void Register(Func && _func, Type* _this);

		/// <summary>
		/// �W���u���s.
		/// </summary>
		void Execution() override;

#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------

#pragma endregion

	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		using FuncObject = std::_Binder<std::_Unforced, void(Type::*)(), Type*>;
		FuncObject* m_pFuncObj = nullptr;
#pragma endregion
	};
#include"Executer.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

