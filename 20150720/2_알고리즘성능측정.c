// 2_�˰��򼺴�����.c
// �˰���
// �־��� ������ �ذ��ϱ� ���� �� ���ǵ� ���۵��� ���� ����

// ����->�λ�
// 1. ����, 2. ����, 3. �ڵ���, 4. ������, 5.�ȱ�
// ����� ������ �־��� ȯ��(�ð��� ���)�� ���� ������ ����� ã�ƾ� �Ѵ�.

// �˰����� ���� ����
// ���α׷��� ���� �ð��� ����
// 1. time.h�� clock() �Լ� �̿�
// Clock Tick : �ֱ������� �߻��ϴ� Ư���� ���ͷ�Ʈ�� �ý��� ����� ���� �ð�.
// ���� ���μ����� �������� �󸶳� �������� Clock Tick������ �� �� �ִ�.
// clock() : ms����, ���������� �ʴ�.
#if 1
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