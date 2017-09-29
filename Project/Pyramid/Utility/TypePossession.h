/**
* @file		TypePossession.h
* @brief	�^������������
* @author	S.OIKAWA
* @date		2016.09.28
*/
#pragma once

#pragma region include
	//-----------------------------------------------------------
	// include
	//-----------------------------------------------------------
#include<typeindex>
#include<vector>
#include"NullType.h"
#include"Nullable.h"
#include"TypeList.h"
#pragma endregion

#pragma region define
	//-----------------------------------------------------------
	// define
	//-----------------------------------------------------------

#pragma endregion

namespace Utility
{
	/// <summary>
	/// �^������������ .
	/// Apply���Ă��Ȃ��ꍇTypePossession�^������.
	/// </summary>
	class TypePossession
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		TypePossession();
		virtual ~TypePossession() = default;

		TypePossession(const TypePossession&) = default;
		TypePossession(TypePossession&&) = default;

		TypePossession& operator=(const TypePossession&) = default;
		TypePossession& operator=(TypePossession&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// �^����ύX����.
		/// �����ŉ��z�֐����R�[�����Ă�̂�
		/// �t�b�N�I�[�o�[���C�h������R���X�g���N�^�ŌĂ΂Ȃ��悤��.
		/// </summary>
		template<class ...Type>
		void TypeApply();

		/// <summary>
		/// �^�m��p�̃C�x���g�t�b�N.
		/// </summary>
		virtual void OnApply();
		
		/// <summary>
		/// �C���f�b�N�X�ˉe.
		/// </summary>
		Nullable<std::type_index*> AccessOfIndex(unsigned);
	
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
		std::vector<std::type_index> m_Types;
#pragma endregion
	};
#include"TypePossession.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

