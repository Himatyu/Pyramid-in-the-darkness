/**
* @file		singleton.h
* @brief	mozc���V���O���g��
* @author	S.OIKAWA
* @date		2016.05.30
*/

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<vector>
namespace Utility
{
	//-----------------------------------------------------------
	// define 
	//-----------------------------------------------------------
	/// <summary>
	/// �V���O���g���J���N���X
	/// </summary>
	class SingletonFinalizer
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor 
		//-----------------------------------------------------------
		SingletonFinalizer() = default;
		~SingletonFinalizer() = default;

		SingletonFinalizer(const SingletonFinalizer&) = default;
		SingletonFinalizer(SingletonFinalizer&&) = default;

		SingletonFinalizer&operator=(const SingletonFinalizer&) = default;
		SingletonFinalizer&operator=(SingletonFinalizer&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		using FinalizerFunc = void(*)();
		static void AddFinalizer(FinalizerFunc _func);
		static void Finalize();
	private:
		//-----------------------------------------------------------
		// Val 
		//-----------------------------------------------------------
		static std::vector<FinalizerFunc> m_Finalizers;

	};


	/// <summary>
	/// �V���O���g���e���v���[�g
	/// </summary>
	template <class Type>
	class Singleton
	{
		//-----------------------------------------------------------
		// ctor.dtor 
		//-----------------------------------------------------------
	protected:
		Singleton() = default;
		~Singleton() = default;

		Singleton(const Singleton&) = default;
		Singleton(Singleton&&) = default;

		Singleton& operator=(const Singleton&) = default;
		Singleton& operator=(Singleton&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
	public:
		/// <summary>
		/// ���̂𐶐�.
		/// </summary>
		/// <returns>���̎Q��</returns>
		static Type& Instantiate();

	private:
		static void Create();

		static void Destroy();

		//-----------------------------------------------------------
		//  Val
		//-----------------------------------------------------------
		static std::once_flag	m_InitFlag;
		static Type*			m_pInstance;
	};
#include"singleton.inl"
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------