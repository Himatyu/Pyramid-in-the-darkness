/**
* @file		Subject.h
* @brief	�Ď��҂ɒʒm�@�\���
* @author	S.OIKAWA
* @date		2016.04.27 DoxyGen
* @date		2016.05.26 �f�t�H���g�R�s�[�E���[�u�ǉ�
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	class Observer;
}

namespace Utility
{
	/// <summary>�Ď��Ώ�</summary>
	class Subject
	{
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
	public:

		Subject() = default;
		virtual ~Subject() = default;

		//-----------------------------------------------------------
		//�@default
		//-----------------------------------------------------------
		Subject(const Subject&) = default;
		Subject(Subject&&) = default;

		Subject& operator=(const Subject&) = default;
		Subject& operator=(Subject&&) = default;
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
	public:
		/// <summary>�Ď��ғo�^</summary>	
		///<param name="_obser">�o�^�Ď���</param>
		virtual void Attach(Observer* _obser);

		/// <summary>�Ď��ҍ폜</summary>
		///<param name="_obser">�폜�Ď���</param>
		virtual void Detach(Observer* _obser);

		/// <summary>�ʒm</summary>
		virtual void Notify();

		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
	private:
		std::vector<Observer*> m_Ovservers;

	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
