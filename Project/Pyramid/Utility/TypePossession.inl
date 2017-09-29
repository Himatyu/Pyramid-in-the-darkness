/**
* @file		TypePossession.inl
* @brief	å^èÓïÒÇèäéùÇ∑ÇÈ
* @author	S.OIKAWA
* @date		2016.09.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TypePossession.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace 
{
	template<class ...ArgsParams>
	struct Parser
	{
		using TL = 
			typename Utility::ConvertToTypeList<ArgsParams...>::Result;
		static constexpr int Size = sizeof...(ArgsParams);

		static void Run(std::vector<std::type_index>& _vector)
		{
			Run<TL>( _vector);
		};

	private:
		template<class Ty>
		static void Run(
			std::vector<std::type_index>& _vector)
		{
			_vector.push_back(typeid(Ty::Head));
			Run<Ty::Tail>(_vector);
		};

		template<>
		static void Run<Utility::NullType>(
			std::vector<std::type_index>& _vector)
		{
		};
		
	};
};

//-----------------------------------------------------------
// TypeApply
//-----------------------------------------------------------
template<class ...Type>
inline void TypePossession::TypeApply()
{	
	Parser<Type...>::Run(m_Types);
	OnApply();
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------