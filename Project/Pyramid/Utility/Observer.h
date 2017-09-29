/**
* @file			Observer.h
* @brief		通知イベントを提供
* @author		S.OIKAWA
* @date			2016.04.27
* @date			2016.05.26 デフォルトコピー・ムーブ追加
*/
#pragma once

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	class Subject;

	/// <summary>オブザーバベース</summary>
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
			/// <summary>イベント関数</summary>
		virtual	void OnEvent(Subject* _ChangedSubject) = 0;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------