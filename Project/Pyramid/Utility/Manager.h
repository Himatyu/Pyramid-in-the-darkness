/**
* @file		Manager.h
* @brief	�R���e�i�ŊǗ�����x�[�X
* @author	S.OIKAWA
* @date		2017.03.07
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include<vector>
#include<deque>
#include<functional>
#include<type_traits>
#include"Estd.h"
#include"NullType.h"
#include"Nullable.h"
#include"IUnknown.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Utility
{
	/// <summary>
	/// �R���e�i��������������J����
	/// �@�\������g����e�Ղɂ���
	/// Add/Remove����͑S�ăC�e���[�^��j�󂷂�̂ŃC�e���[�V�������ɂ͎g���Ȃ�
	/// vector,list,deque�Ɍ��肷��(�C���^�[�t�F�[�X����̂���)
	/// </summary>
	template<class Container>
	class Manager : 
		public Unknown
	{
		static_assert(
			std::is_same<Container, std::vector<typename Container::value_type>>::value ||
			std::is_same<Container, std::deque<typename Container::value_type>>::value ||
			std::is_same<Container, std::list<typename Container::value_type>>::value,
			"use container other than vector or list or deque");	//2�o�C�g�����g���Ȃ��񂾂���
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		Manager() = default;
		virtual ~Manager() = default;

		Manager(const Manager&) = default;
		Manager(Manager&&) = default;

		Manager& operator=(const Manager&) = default;
		Manager& operator=(Manager&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// �ǉ�
		/// </summary>
		virtual void Add(typename Container::value_type);

		/// <summary>
		/// �폜
		/// �J���͍s��Ȃ�
		/// </summary>
		virtual void Remove(typename Container::value_type);

		/// <summary>
		/// �ˉe
		/// </summary>
		virtual Nullable<std::list<typename Container::value_type>>
			Select(std::function<bool(typename Container::value_type)>&);
#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_REF(m_Container, Value, Container);

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
	protected:
		Container		m_Container;

#pragma endregion
	};
#include"Manager.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------