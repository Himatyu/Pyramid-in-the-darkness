/**
* @file		FPSCounter.cpp
* @brief	FPS計測の実装
* @author	S.OIKAWA
* @date		2016.05.11
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "FPSCounter.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	FPSCounter::FPSCounter() :
		m_SampleCount(100),
		m_CommonSum(0),
		m_Freq(0)
	{
		if (QueryPerformanceCounter(&m_Conter) != 0)
		{
			m_LogTime = m_Conter.QuadPart;
			LARGE_INTEGER Freq;
			QueryPerformanceFrequency(&Freq);		//生成時の時間取得
			m_Freq = static_cast<double>(Freq.QuadPart);
		}
		else
		{
			___D_LOG("FPSタイマーが使用できません");
		}
		m_SampleFps.resize(m_SampleCount, 0.0f);
		GetFps();
	}

	//-----------------------------------------------------------
	// GetFps
	//-----------------------------------------------------------
	double FPSCounter::GetFps()
	{
		double dest = GetFreamDistanceTime();

		if (!dest)
		{
			return 0;
		}

		return UpdataFPS(dest);
	}

	//-----------------------------------------------------------
	// GetFreamDistanceTime
	//-----------------------------------------------------------
	double FPSCounter::GetFreamDistanceTime()
	{
		QueryPerformanceCounter(&m_Conter);                     // 現在の時刻を取得し、
		LONGLONG LongDef = m_Conter.QuadPart - m_LogTime;		// 差分カウント数を算出する。
		double dDef = (double)LongDef;                          // 倍精度浮動小数点に変換
		m_LogTime = m_Conter.QuadPart;							// 現在の時刻を保持
		return dDef * 1000 / m_Freq;                            // 差分時間をミリ秒単位で返す
	}

	//-----------------------------------------------------------
	// UpdataFPS
	//-----------------------------------------------------------
	double FPSCounter::UpdataFPS(double _destance)
	{
		m_SampleFps.pop_front();

		double fps;
		double avaDes = (m_CommonSum + _destance) / m_SampleCount;

		if (avaDes != 0)
		{
			fps = 1000.0 / avaDes;
		}
		m_CommonSum += _destance - *m_SampleFps.begin();

		m_SampleFps.emplace_back(_destance);
		return fps;
	}

	//-----------------------------------------------------------
	// SetSampleCount
	//-----------------------------------------------------------
	void FPSCounter::SetSampleCount(const int _val)
	{
		m_SampleCount = _val;
		m_SampleFps.resize(_val, 0.0f);
		m_CommonSum = 0;
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------