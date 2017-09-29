/**
* @file		MultiTypeMap.h
* @brief	�����̌^��ێ�����}�b�v
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
	/// �����̌^����������map.
	/// �C�ӌ^��o�^����.
	/// �����͕ێ����*�ێ�������������.
	/// �o�^��ނ͍ŏ����ɂ��邱��.
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
		/// �v�f�ǉ�.
		/// </summary>
		template<class Type>
		void Add(std::string _key, Type _value);

		/// <summary>
		/// �v�f�폜.
		/// </summary>
		template<class Type>
		void Remove(std::string _key);

		/// <summary>
		/// ����.
		/// </summary>
		/// <returns>�Ȃ���΃k���|</returns>
		template<class Type>
		Nullable<Type> Find(std::string _key);

		/// <summary>
		/// �g�p����^��o�^����.
		/// </summary>
		template <class Type>
		void RegisterUseType();

		/// <summary>
		/// �^���𖕏�����.
		/// </summary>
		template<class Type>
		void UnRegisterUseType();

		/// <summary>
		/// �e�^�̃}�b�v���擾����.
		/// </summary>
		template<class Type>
		SingleTypeMap<Type>& GetSingleTypeMap();

		/// <summary>
		/// �^���̏������m�F.
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
