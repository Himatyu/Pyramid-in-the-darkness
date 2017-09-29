/**
* @file		StaticValue.h
* @brief	�ÓI�ϐ��ŊJ���������w�肵�����I�u�W�F�N�Ɏg�p����
* @author	S.OIKAWA
* @date		2016.11.14
*/

#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	/// �ÓI�ϐ��̊J��
	/// </summary>
	class StaticValueFinalizer
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor 
		//-----------------------------------------------------------
		StaticValueFinalizer() = default;
		~StaticValueFinalizer() = default;

		StaticValueFinalizer(const StaticValueFinalizer&) = default;
		StaticValueFinalizer(StaticValueFinalizer&&) = default;

		StaticValueFinalizer& operator=(const StaticValueFinalizer&) = default;
		StaticValueFinalizer& operator=(StaticValueFinalizer&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		using FinalizerFunc = void(*)();

		/// <summary>
		/// �J���֐���o�^
		/// </summary>
		static void AddFinalizer(FinalizerFunc _func);

		/// <summary>
		/// �J�������s
		/// </summary>
		static void Finalize();

	private:
		//-----------------------------------------------------------
		// Val 
		//-----------------------------------------------------------
		static std::vector<FinalizerFunc> m_Finalizers;

	};

	/// <summary>
	/// �ÓI�ϐ��ŊJ���������w�肵�����I�u�W�F�N�Ɏg�p����
	/// </summary>
	template<class Ty>
	class StaticValue
	{
	public:
		//-----------------------------------------------------------
		// defaullts 
		//-----------------------------------------------------------
		StaticValue();
		~StaticValue() = default;

		StaticValue(const StaticValue&) = default;
		StaticValue(StaticValue&&) = default;

		StaticValue&operator=(const StaticValue&) = default;
		StaticValue&operator=(StaticValue&&) = default;

		//-----------------------------------------------------------
		// operator
		//-----------------------------------------------------------
		operator Ty();
		Ty& operator = (Ty);
		Ty& operator->();
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
	private:
		static void Destroy();

		//-----------------------------------------------------------
		// var
		//-----------------------------------------------------------
		static Ty*	m_pInstance;
	};
#include"StaticValue.inl"
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

