// 2_�˰��򼺴�����.c
// �˰���
// �־��� ������ �ذ��ϱ� ���� �� ���ǵ� ���۵��� ���� ����

// ����->�λ�
// 1. ����, 2. ����, 3. �ڵ���, 4. ������, 5.�ȱ�
// ����� ������ �־��� ȯ��(�ð��� ���)�� ���� ������ ����� ã�ƾ� �Ѵ�.

// �˰����� ���� ����
// ���α׷��� ���� �ð��� ����

// 3. debugging�� @CLK ���
// breakpoint : f9
// 1. breakpoint�� ���, f5�� ���� ��, ����� ��� ����
// 2. @CLK�� �Է��ϰ�, value�� 0���� �ʱ�ȭ ��Ų��.
// 3. continue�� �ϸ� �ش� ����� ����ð��� microsecond ������ Ȯ�� �� �� �� �ִ�.

// ����� ����̱� ������ �߰� �۾��� ������ ��Ȯ�� ����ð��� �˾Ƴ� ���� ������
// ��������� ���� �۾��鿡 ���� ���� �ð��� ���� �� �� �ִ�.

#if 1
#include <stdio.h>
#include <Windows.h>

void foo()
{
	Sleep(3);
}

int main()
{
	foo();
}
#endif

// 2. Win32API�� ����ؼ� ���� ����
// Windows���� �����ϴ� ��Ȯ�� Ÿ�̸�
// cpu�ӵ��� �������� timer�� �ʴ� counter ���� �����Ѵ�.
// system���� �����ϴ� ���� timer ���
#if 0
#include <stdio.h>
#include <Windows.h>

void foo()
{
	Sleep(3000);
}

int main()
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER begin;
	LARGE_INTEGER end;

	INT64 elapsed = 0;

	// ���ļ�(�ʴ� ������)�� �˾Ƴ��� �Լ�
	QueryPerformanceFrequency(&frequency);	
	QueryPerformanceCounter(&begin);
	foo();
	QueryPerformanceCounter(&end);

	// microsecond ������ ����
	elapsed = end.QuadPart - begin.QuadPart;

	printf("%lf\n", (double)elapsed / frequency.QuadPart);
}
#endif

// 1. time.h�� clock() �Լ� �̿�
// Clock Tick : �ֱ������� �߻��ϴ� Ư���� ���ͷ�Ʈ�� �ý��� ����� ���� �ð�.
// ���� ���μ����� �������� �󸶳� �������� Clock Tick������ �� �� �ִ�.
// clock() : ms����, ���������� �ʴ�.
#if 0
#include <stdio.h>
#include <time.h>
#include <Windows.h>

void foo()
{
	Sleep(3);	// ms����
}

int main()
{
	int start, end;
	start = clock();
	foo();
	end = clock();

	// CLOCKS_PER_SEC : �ʴ� Ŭ�� ��
	printf("%lf sec\n", (double)(end - start) / CLOCKS_PER_SEC);
}
#endif