#include "pch.h"
#include "Timer.h"

void Timer::Init()
{
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency)); // ���ļ� ���ϱ�
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount)); // CPU Ŭ���� ����
}

void Timer::Update() // �ð� ������Ʈ
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency); // �ð��� ���ϴ� ����
	_prevCount = currentCount;

	_frameCount++;
	_frameTime += _deltaTime; // �� �����Ӹ��� �ð����� �����Ѵ� 

	if (_frameTime >= 1.f) // 1�ʸ��� ���۾��� ����
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime); 

		_frameTime = 0.f; 
		_frameCount = 0;
	}
}