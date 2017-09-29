/**
* @file		Layer.h
* @brief	フラグの重合体をしてのレイヤーを定義
* @author	S.OIKAWA
* @date		2016.11.13
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<array>
#include<initializer_list>
#pragma endregion

namespace Utility
{
	/// <summary>
	/// フラグの重合体.
	/// レイヤーと数はEnumで定義する.
	/// </summary>
	template<class Enum, int Count>
	class Layer
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		Layer() = default;
		Layer(std::initializer_list<Enum>);
		~Layer() = default;

		Layer(const Layer&) = default;
		Layer(Layer&&) = default;

		Layer& operator=(const Layer&) = default;
		Layer& operator=(Layer&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		/// <summary>
		/// SetFlag
		/// </summary>
		template<typename First, typename... Rest>
		void SetFlag(const bool _flag, const First& _first, const Rest&&... _rest);

		/// <summary>
		/// IsMatch
		/// </summary>
		bool IsMatch(const Layer& _other);
	private:
		void SetFlag(bool);
#pragma endregion

	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		std::array<bool, Count> m_Flags{ false };
		int						m_Index;

#pragma endregion
	};
#include"Layer.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------