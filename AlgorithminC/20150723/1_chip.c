#include <stdio.h>

int cache[5][100];
int back[100][5];
int chip[100][3];

#define max(a, b) ((a)>(b)?(a):(b))

// 다음 type이 주어질 때 n길이에 놓을 수 있는 최대 값
// type: 0(all), 1, 2, 3, 4
int solve(int type, int n) {
	if (n < 0) return 0;
	int res = cache[type][n];
	if (res != -1) return res;
	res = 0;
	if (type != 1 && type != 4)
		if (res < solve(1, n - 1) + chip[n][0]) {
			res = solve(1, n - 1) + chip[n][0];
			back[n][type] = 1;
		}
	if (type != 2)
		if (res < solve(2, n - 1) + chip[n][1]) {
			res = solve(2, n - 1) + chip[n][1];
			back[n][type] = 2;
		}
	if (type != 3 && type != 4)
		if (res < solve(3, n - 1) + chip[n][2]) {
			res = solve(3, n - 1) + chip[n][2];
			back[n][type] = 3;
		}
	if (type != 1 && type != 3 && type != 4)
		if (res < solve(4, n - 1) + chip[n][0] + chip[n][2]) {
			res = solve(4, n - 1) + chip[n][0] + chip[n][2];
			back[n][type] = 4;
		}
	cache[type][n] = res;
	return res;
}

// n길이의 문자판에 대해 최대 값이 주어질 때의 chip이 놓인 위치를 출력
void construct(int n) {
	int path[100];
	int next = back[n - 1][0];
	path[n] = 0;
	path[n - 1] = next;
	for (int i = n - 2; i >= 0; --i) {
		path[i] = back[i][next];
		next = back[i][next];
	}
	for (int i = 0; i < n; ++i) {
		printf("%d(%d)", path[i], cache[path[i + 1]][i]);
		if (i != n - 1) printf(" -> ");
	}
	printf("\n");
}

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		int n, i;
		scanf("%d", &n);
		memset(cache, -1, sizeof(cache));
		for (i = 0; i < n; ++i) {
			scanf("%d %d %d", &chip[i][0], &chip[i][1], &chip[i][2]);
		}
		printf("%d\n", solve(0, n-1));
		construct(n);
	}
}