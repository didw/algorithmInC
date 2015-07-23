#include <stdio.h>
#include <string.h>

#define max(a, b) ((a)>(b)?(a):(b))

int cache[100][100];
char a[100], b[100];

// 두 문자열의 위치가 i, j일 때 공통 부분의 최대 길이
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
		construct();
	}
}