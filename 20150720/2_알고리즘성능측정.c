// 2_알고리즘성능측정.c
// 알고리즘
// 주어진 문제를 해결하기 위한 잘 정의된 동작들의 유한 집합

// 서울->부산
// 1. 기차, 2. 버스, 3. 자동차, 4. 자전거, 5.걷기
// 방법은 많지만 주어진 환경(시간과 비용)에 따라 최적의 방법을 찾아야 한다.

// 알고리즘의 성능 측정
// 프로그램의 수행 시간을 측정
// Win32API를 사용해서 성능 측정
// Windows에서 제공하는 정확한 타이머

#if 1
#include <stdio.h>
#include <Windows.h>

void foo()
{
	Sleep(300);
}

int main()
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER begin;
	LARGE_INTEGER end;

	INT64 elapsed = 0;

	// 주파수(초당 진동수)를 알아내는 함수
	QueryPerformanceFrequency(&frequency);	
	QueryPerformanceCounter(&begin);
	foo();
	QueryPerformanceCounter(&end);

	// millisecond 단위로 측정
	elapsed = end.QuadPart - begin.QuadPart;

	printf("%lf\n", (double)elapsed / frequency.QuadPart);
}
#endif

// 1. time.h의 clock() 함수 이용
// Clock Tick : 주기적으로 발생하는 특별한 인터럽트로 시스템 운용의 기준 시간.
// 현재 프로세스가 실행한지 얼마나 지났는지 Clock Tick단위로 알 수 있다.
// clock() : ms단위, 정밀하지는 않다.
#if 0
#include <stdio.h>
#include <time.h>
#include <Windows.h>

void foo()
{
	Sleep(3);	// ms단위
}

int main()
{
	int start, end;
	start = clock();
	foo();
	end = clock();

	// CLOCKS_PER_SEC : 초당 클럭 수
	printf("%lf sec\n", (double)(end - start) / CLOCKS_PER_SEC);
}
#endif