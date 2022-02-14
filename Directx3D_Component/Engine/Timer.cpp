#include "pch.h"
#include "Timer.h"

void Timer::Init()
{
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency)); // 주파수 구하기
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount)); // CPU 클럭과 관련
}

void Timer::Update() // 시간 업데이트
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency); // 시간차 구하는 공식
	_prevCount = currentCount;

	_frameCount++;
	_frameTime += _deltaTime; // 매 프레임마다 시간차를 누적한다 

	if (_frameTime >= 1.f) // 1초마다 이작업을 시행
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime); 

		_frameTime = 0.f; 
		_frameCount = 0;
	}
}