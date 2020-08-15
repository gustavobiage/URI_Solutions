#include <stdlib.h>
#include <stdio.h>

int m, n;
char arr[1001][1001];
int ans;

int isWater(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return 1;
	}
	return arr[x][y] == '.';
}

int main() {
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s ", arr[i]);
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#' &&
			 (isWater(i+1, j) || isWater(i-1, j) || isWater(i, j+1) || isWater(i, j-1))) {
				ans++;
				arr[i][j] = 'X';
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}