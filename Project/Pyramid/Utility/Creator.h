/**
* @file		Creator.h
* @brief	������^�̐����֐����
* @author	S.OIKAWA
* @date		2016.02.19
*/
#pragma once

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	///�N���G�C�^�[�x�[�X
	/// </summary>
	template<class Type>
	class Creator
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
		Creator() = default;
		virtual ~Creator() = default;

		//-----------------------------------------------------------
		// default 
		//-----------------------------------------------------------
		Creator(const Creator&) = default;
		Creator(Creator&&) = default;

		Creator&operator=(const Creator&) = default;
		Creator&operator=(Creator&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		/// <summary>
		/// �N���G�C�g�֐�
		/// </summary>
		/// <returns>�����^</returns>
		virtual Type Create() = 0;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
