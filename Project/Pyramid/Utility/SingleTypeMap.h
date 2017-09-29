/**
* @file		SingleTypeMap.h
* @brief	�}���`�^�C�vMap�����̃}�b�v
* @author	S.OIKAWA
* @date		2016.09.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<unordered_map>
#include<string>
#include"HavingChildType.h"
#include"Nullable.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Utility
{
	template<class Type>
	class SingleTypeMap final
		:public HavingChildType
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		SingleTypeMap();
		~SingleTypeMap();

		SingleTypeMap(const SingleTypeMap&) = default;
		SingleTypeMap(SingleTypeMap&&) = default;

		SingleTypeMap& operator=(const SingleTypeMap&) = default;
		SingleTypeMap& operator=(SingleTypeMap&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// �v�f�ǉ�.
		/// </summary>
		void Add(std::string _key, Type _value);

		/// <summary>
		/// �v�f�폜.
		/// </summary>
		void Remove(std::string _key);

		/// <summary>
		/// ����.
		/// </summary>
		Nullable<Type> Find(std::string _key);
#pragma endregion

	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		std::unordered_map<std::string, Type> m_Map;

#pragma endregion
	};
#include"SingleTypeMap.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
