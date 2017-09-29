/**
* @file		Subject.h
* @brief	監視者に通知機能を提供
* @author	S.OIKAWA
* @date		2016.04.27 DoxyGen
* @date		2016.05.26 デフォルトコピー・ムーブ追加
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
	/// <summary>監視対象</summary>
	class Subject
	{
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
	public:

		Subject() = default;
		virtual ~Subject() = default;

		//-----------------------------------------------------------
		//　default
		//-----------------------------------------------------------
		Subject(const Subject&) = default;
		Subject(Subject&&) = default;

		Subject& operator=(const Subject&) = default;
		Subject& operator=(Subject&&) = default;
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
	public:
		/// <summary>監視者登録</summary>	
		///<param name="_obser">登録監視者</param>
		virtual void Attach(Observer* _obser);

		/// <summary>監視者削除</summary>
		///<param name="_obser">削除監視者</param>
		virtual void Detach(Observer* _obser);

		/// <summary>通知</summary>
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
