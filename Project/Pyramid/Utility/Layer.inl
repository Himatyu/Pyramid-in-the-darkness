/**
* @file		Layer.inl
* @brief	�t���O�̏d���̂����Ẵ��C���[���`
* @author	S.OIKAWA
* @date		2016.11.13
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Layer.h"
#pragma endregion

/// <summary>
/// ctor
/// </summary>
template<class Enum, int Count>
inline
Layer<Enum, Count>::Layer(std::initializer_list<Enum> _list)
{
	if (_list.size() > Count)
	{
		return;
	}

	for (auto& _ : _list)
	{
		SetFlag(true, _);
	}
}

/// <summary>
/// ���C���[����v���Ă��邩�m�F
/// </summary>
template<class Enum, int Count>
inline
bool Layer<Enum, Count>::IsMatch(const Layer & _other)
{
	std::vector<int> onlist;
	for (int i = 0; i < m_Flags.size(); i++)
	{
		if (m_Flags[i])
		{
			onlist.push_back(i);
		}
	}

	bool isMatch = true;
	for (auto& _ : onlist)
	{
		isMatch &= _other.m_Flags[_];
	}

	return isMatch;
}

/// <summary>
/// �I�[�֐�
/// </summary>
template<class Enum, int Count>
inline void Layer<Enum, Count>::SetFlag(bool)
{
	m_Index = 0;
}

/// <summary>
/// ���C���[�ɑ΂���t���O���Z�b�g����
/// </summary>
template<class Enum, int Count>
template<typename First, typename ...Rest>
inline
void Layer<Enum, Count>::
SetFlag(const bool _flag, const First & _first, const Rest && ..._rest)
{
	if (m_Index > Count)
	{
		return;
	}
	m_Flags[_first] = _flag;
	m_Index++;
	return SetFlag(_flag, _rest...);
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------