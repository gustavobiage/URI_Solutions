#include <stdlib.h>
#include <stdio.h>

int arr[101][101];
int n;
int bx, ex, by, ey;
int ans;

int main() {
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d ", &bx, &ex, &by, &ey);
		for (int i = bx; i < ex; i++) {
			for (int j = by; j < ey; j++) {
				arr[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			ans += arr[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}