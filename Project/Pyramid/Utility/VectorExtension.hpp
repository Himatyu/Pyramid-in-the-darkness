/**
* @file		VectorExtension.hpp
* @brief	�x�N�^�[�̊g���@�\���
* @author	Oikawa
* @date		2016.02.19
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include <vector>
#include<functional>

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>�x�N�^�̈��S�폜</summary>
	///<typeparam name="Type">�x�N�^�v�f�^</typeparam>
	///<typeparam name="Pred">�폜����</typeparam>
	///<param name="_vec">�Ώۃx�N�^</param>
	///<param name="_pred">���胉���_��</param>
	///<param name="_isDestroy">��������������邩</param>
	template <class Type,class Pred>
	void VectorClean
		(
		std::vector<Type>& _vec,
		Pred _pred,
		bool _isDestroy
		)
	{
		if (0 == _vec.size()) return;
		auto  it = std::begin(_vec);

		for (; it != std::end(_vec);)
		{
			if (_pred((*it)))
			{
				if (_isDestroy)
					delete *it;

				it = _vec.erase(it);
				continue; 
			}
			it++;
		}
	} 

	/// <summary>�x�N�^</summary>
	///<typeparam name="Type">�x�N�^�v�f�^</typeparam>
	///<param name="_vec">�Ώۃx�N�^</param>
	///<param name="_action">���s�����_��</param>
	template <class Type>
	void VectorForEach
		(
		std::vector<Type>& _vec,
		std::function<void(Type _element)> _action
		)
	{
		if (0 == _vec.size())
		{
			return;
		}

		for (auto it : _vec)
		{
			_action(it);
		}
	}

	/// <summary>�����J�E���g</summary>
	///<typeparam name="Type">�x�N�^�v�f�^</typeparam>
	///<typeparam name="Pred">����</typeparam>
	///<param name="_vec">�Ώۃx�N�^</param>
	///<param name="_pred">���胉���_��</param>
	///<returns>�J�E���g</returns>
	template <class Type,class Pred>
	size_t VectorCount_if
		(
			std::vector<Type>& _vec,
			Pred _pred
		)
	{
		return std::count_if(
							std::begin(_vec), 
							std::end(_vec),
							_pred
							);
	}

	/// <summary>�d���j��</summary>
	///<typeparam ="Type">�x�N�^�v�f�^</typeparam>
	///<param ="_vec">�Ώۃx�N�^<param>
	template <class Type>
	void VectorUnique(std::vector<Type>& _vec)
	{
		std::sort(_vec.begin(), _vec.end());
		_vec.erase(std::unique(_vec.begin(), _vec.end()), _vec.end());
	}

	/// <summary>�����\�[�g</summary>
	///<typeparam ="Type">�x�N�^�v�f�^</typeparam>
	///<typeparam ="Pred">���������_</typeparam>
	///<param ="_vec">�Ώۃx�N�^</param>
	///<param ="_pred">������</param>
	template<class Type,class Pred>
	void VectorSort(
		std::vector<Type>& _vec,
		Pred _pred
		)
	{
		std::sort(_vec.begin(), _vec.end(), _pred);
	}
};

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------