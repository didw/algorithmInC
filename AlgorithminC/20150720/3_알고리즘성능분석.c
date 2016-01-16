// 3_알고리즘성능분석.c
// 알고리즘의 성능 표기법
// 1. 공간 복잡도 : 알고리즘을 실행하여 종료할 때까지 필요한 메모리 크기
// 2. 시간 복잡도 : 알고리즘을 실행하여 필요한 시간

// 명령어의 실행 횟수 = 2n+4, 시간복잡도 = O(n)
// 명령어의 실행 횟수를 고려하여 알고리즘의 시간 복잡도를 계산한다.
// 예제1. 시간 복잡도
float Sum(float a[], int n)
{
	float s = 0.0;				// 1
	int i;						// 1
	for (i = 0; i < n; i++)		// n+1 (0~n-1)
		s += a[i];				// n
	printf("%d\n", n);			// 9? 10? 11
	return s;					// 1
}

// 예제2. 시간 복잡도
// 명령어의 실행 횟수 = 2n+2, 시간복잡도 = O(n)
float RSum(float a[], int n)
{
	if (n <= 0)					// 1
		return 0.0;				// 1
	else
		return RSum(a, n - 1) + a[n];	// T(RSum(n-1))
}

// T(RSum(0))	= 2;
// T(RSum(n))	= 2 + T(RSum(n-1))
//				= 2 + 2 + T(RSum(n-2))
//				= 2 + 2 + 2 + T(RSum(n-3))
//				...
//				= 2*n + T(RSum(0))
//				= 2*n + 2
// 공간 복잡도
// 변수 저장하기 위한 공간
// 순환 스택을 사용하기 위한 공간

// 교재 p.6의 공간 복잡도를 계산해 보세요.
// 예제1. 공간 복잡도 = 0
// 사용한 변수 : a, b, c
// 사용한 변수 a, b, c는 문제를 해결하기 위한 변수가 아니기 때문에
// 공간 복잡도와는 무관하다.
float abc(float a, float b, float c)
{
	return (a + b + b*c + (a + b - c) / (a + b) + 4.0);
}

// 예제2. 공간 복잡도 = n + 4
// 사용한 변수 : a[], n, s, i
// a[]를 저장하기 위한 공간 + 변수 n, s, i를 위한 공간 =>n+3
float Sum(float a[], int n)
{
	float s = 0.0;
	int i;
	for (i = 0; i <= n; i++)
		s += a[i];
	return s;
}

// 예제3. 공간 복잡도 = 3(n+1)
// 사용한 변수 : a[], n
// 재귀함수 내에서 a[n], n, 순환 참조시 필요한 복귀 주소를 위한 공간 => 3
// 실제 공간 복잡도 계산
// depth of recursion * (a[n], n, 복귀를 위한 주소) => (n+1) * 3
float RSum(float a[], int n)
{
	if (n <= 0)
		return 0.0;
	else
		return RSum(a, n - 1) + a[n];
}