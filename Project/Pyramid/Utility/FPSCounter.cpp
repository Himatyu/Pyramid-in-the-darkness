/**
* @file		FPSCounter.cpp
* @brief	FPS�v���̎���
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
			QueryPerformanceFrequency(&Freq);		//�������̎��Ԏ擾
			m_Freq = static_cast<double>(Freq.QuadPart);
		}
		else
		{
			___D_LOG("FPS�^�C�}�[���g�p�ł��܂���");
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
		QueryPerformanceCounter(&m_Conter);                     // ���݂̎������擾���A
		LONGLONG LongDef = m_Conter.QuadPart - m_LogTime;		// �����J�E���g�����Z�o����B
		double dDef = (double)LongDef;                          // �{���x���������_�ɕϊ�
		m_LogTime = m_Conter.QuadPart;							// ���݂̎�����ێ�
		return dDef * 1000 / m_Freq;                            // �������Ԃ��~���b�P�ʂŕԂ�
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