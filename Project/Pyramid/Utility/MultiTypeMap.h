/**
* @file		MultiTypeMap.h
* @brief	•¡”‚ÌŒ^‚ğ•Û‚·‚éƒ}ƒbƒv
* @author	S.OIKAWA
* @date		2016.09.07
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include<algorithm>
#include"SingleTypeMap.h"
#include"HavingChildType.h"
#include"TypeList.h"
#include"NullType.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion

namespace Utility
{
	/// <summary>
	/// •¡”‚ÌŒ^‚ğŠ‚·‚émap.
	/// ”CˆÓŒ^‚ğ“o˜^‚·‚é.
	/// ŒŸõ‚Í•Ûí—Ş*•ÛŒÂ”‚ğö‘‚·‚é.
	/// “o˜^í—Ş‚ÍÅ¬ŒÀ‚É‚·‚é‚±‚Æ.
	/// </summary>
	class MultiTypeMap
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		MultiTypeMap() = default;
		~MultiTypeMap();

		MultiTypeMap(const MultiTypeMap&) = default;
		MultiTypeMap(MultiTypeMap&&) = default;

		MultiTypeMap& operator=(const MultiTypeMap&) = default;
		MultiTypeMap& operator=(MultiTypeMap&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// —v‘f’Ç‰Á.
		/// </summary>
		template<class Type>
		void Add(std::string _key, Type _value);

		/// <summary>
		/// —v‘fíœ.
		/// </summary>
		template<class Type>
		void Remove(std::string _key);

		/// <summary>
		/// ŒŸõ.
		/// </summary>
		/// <returns>‚È‚¯‚ê‚Îƒkƒ‹ƒ|</returns>
		template<class Type>
		Nullable<Type> Find(std::string _key);

		/// <summary>
		/// g—p‚·‚éŒ^‚ğ“o˜^‚·‚é.
		/// </summary>
		template <class Type>
		void RegisterUseType();

		/// <summary>
		/// Œ^î•ñ‚ğ–•Á‚·‚é.
		/// </summary>
		template<class Type>
		void UnRegisterUseType();

		/// <summary>
		/// ŠeŒ^‚Ìƒ}ƒbƒv‚ğæ“¾‚·‚é.
		/// </summary>
		template<class Type>
		SingleTypeMap<Type>& GetSingleTypeMap();

		/// <summary>
		/// Œ^î•ñ‚ÌŠ‚ğŠm”F.
		/// </summary>
		template<class Type>
		bool HasType();

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
		std::vector<HavingChildType*> m_Maps;
#pragma endregion
	};
#include"MultiTypeMap.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
