#include <stdio.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

typedef struct _WORK {
	int id, deadline, pay;
} WORK;

int getmaxdeadline(WORK work[100], int n) {
	int i, maxdl = 0;
	for (i = 0; i < n; ++i) {
		maxdl = max(maxdl, work[i].deadline);
	}
	return maxdl;
}

// n���� work���� ������ �ִ�ȭ �϶�
int solve(WORK work[100], int n) {
	// max deadline
	int res = 0;
	int max_deadline = getmaxdeadline(work, n);
	while (max_deadline) {
		// deadline �̳��� �� �� �ִ� work�߿� pay�� �ִ��� ���� ã�´�.
		int i, cand, maxpay = 0;
		for (i = 0; i < n; ++i) {
			if (max_deadline <= work[i].deadline && maxpay < work[i].pay) {
				maxpay = work[i].pay;
				cand = i;
			}
		}
		res += work[cand].pay;
		work[cand].pay = 0;
		max_deadline--;
	}
	return res;
}

int main() {
	int n, i;
	WORK work[100];
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d %d %d", &work[i].id, &work[i].deadline, &work[i].pay);
	}
	printf("%d\n", solve(work, n));
}
