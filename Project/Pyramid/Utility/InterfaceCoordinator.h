/**
* @file		InterfaceCoordinator.h
* @brief	インターフェースをまとめる
* @author	S.OIKAWA
* @date		2017.03.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Utility
{
	/// <summary>
	/// インターフェースの具体クラスの組み合わせをまとめる
	/// </summary>
	template<class Interface, class ...TyList>
	class InterfaceCoordinator :
		public TyList...
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		InterfaceCoordinator(TyList ...args);
		~InterfaceCoordinator() = default;

		InterfaceCoordinator(const InterfaceCoordinator&) = default;
		InterfaceCoordinator(InterfaceCoordinator&&) = default;

		InterfaceCoordinator& operator=(const InterfaceCoordinator&) = default;
		InterfaceCoordinator& operator=(InterfaceCoordinator&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
	private:
		template<class Ty>
		void Parse(int _index, Ty _ty);

		template<class Ty, class ...Tail>
		void Parse(int _index, Ty _ty, Tail... tail);
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion
	protected:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
		std::array<Interface*, sizeof...(TyList)>	m_InterfaceList;
#pragma endregion
	};
#include"InterfaceCoordinator.inl"


}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------