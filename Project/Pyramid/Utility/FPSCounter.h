/**
* @file		FPSCounter.h
* @brief	FPS計測を提供
* @author	S.OIKAWA
* @date		2016.05.11
*/
#pragma once
#pragma comment(lib, "winmm.lib")
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include <windows.h>
#include <mmsystem.h>
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	/// <summary>
	/// FPS計測クラス
	/// </summary>
	class FPSCounter
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
		FPSCounter();
		virtual ~FPSCounter() = default;

		//-----------------------------------------------------------
		// default
		//-----------------------------------------------------------
		FPSCounter(const FPSCounter&) = default;
		FPSCounter(FPSCounter&&) = default;

		FPSCounter& operator=(const FPSCounter&) = default;
		FPSCounter& operator=(FPSCounter&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		double GetFps();

	private:
		double GetFreamDistanceTime();
		double UpdataFPS(double _destance);

		void SetSampleCount(const int _val);
		int GetSampleCount() { return m_SampleCount; }
		__declspec(property(get = GetSampleCount, put = SetSampleCount)) int SampleCount;
		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
	private:
		std::list<double>	m_SampleFps;
		LARGE_INTEGER		m_Conter;
		LONGLONG			m_LogTime;
		double				m_Fps;
		double				m_CommonSum;
		double				m_Freq;
		int					m_SampleCount;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
