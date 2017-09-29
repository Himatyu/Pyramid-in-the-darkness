/**
* @file			Observer.h
* @brief		�ʒm�C�x���g���
* @author		S.OIKAWA
* @date			2016.04.27
* @date			2016.05.26 �f�t�H���g�R�s�[�E���[�u�ǉ�
*/
#pragma once

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	class Subject;

	/// <summary>�I�u�U�[�o�x�[�X</summary>
	class Observer
	{
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
	public:
		Observer() = default;
		virtual ~Observer() = default;

		//-----------------------------------------------------------
		// default
		//-----------------------------------------------------------
		Observer(const Observer&) = default;
		Observer(Observer&&) = default;

		Observer&operator=(const Observer&) = default;
		Observer&operator=(Observer&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
			/// <summary>�C�x���g�֐�</summary>
		virtual	void OnEvent(Subject* _ChangedSubject) = 0;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------