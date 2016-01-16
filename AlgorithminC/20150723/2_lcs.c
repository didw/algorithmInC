#include <stdio.h>
#include <string.h>

#define max(a, b) ((a)>(b)?(a):(b))

int cache[100][100];
char a[100], b[100];

// 두 문자열의 위치가 i, j일 때 공통 부분의 최대 길이
// 재귀적 방법
int solve(int i, int j) {
	if (i < 0 || j < 0) return 0;
	int res = cache[i][j];
	if (res != -1) return res;
	res = 0;
	if (a[i] == b[j]) res = solve(i - 1, j - 1) + 1;
	res = max(res, solve(i - 1, j));
	res = max(res, solve(i, j-1));
	cache[i][j] = res;
	return res;
}

// 
int solve2(int aa, int bb) {
	int i, j;
	for (i = 0; i <= aa; ++i)
		cache[i][0] = 0;
	for (i = 0; i <= bb; ++i)
		cache[0][i] = 0;
	for (i = 1; i <= aa; ++i) {
		for (j = 1; j <= bb; ++j) {
			int res = cache[i][j];
			if (a[i-1] == b[j-1])
				res = cache[i - 1][j - 1] + 1;
			res = max(res, cache[i][j - 1]);
			res = max(res, cache[i - 1][j]);
			cache[i][j] = res;
		}
	}
	return cache[aa][bb];
}

void construct() {
	int i = strlen(a) - 1;
	int j = strlen(b) - 1;
	char res[100] = { 0 };
	int idx = 0;
	while (i >= 0 && j >= 0) {
		if (cache[i][j] > cache[i - 1][j - 1] &&
			cache[i][j] > cache[i - 1][j] &&
			cache[i][j] > cache[i][j - 1]) {
			res[idx++] = a[i];
			i--; j--;
		}
		else if (cache[i][j] == cache[i][j - 1])
			j--;
		else if (cache[i][j] == cache[i - 1][j])
			i--;
	}
	for (i = strlen(res) - 1; i >= 0; --i)
		printf("%c", res[i]);
	printf("\n");
}

int main() {
	int c;
	scanf("%d\n", &c);
	while (c--) {
		gets(a);
		gets(b);
		memset(cache, -1, sizeof(cache));
		int lena = strlen(a);
		int lenb = strlen(b);
		printf("%d\n", solve(lena - 1, lenb - 1));
		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve2(lena, lenb));
		construct();
	}
}