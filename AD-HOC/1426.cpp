#include <stdlib.h>
#include <stdio.h>

int arr[19][19];
int T;

int main() {
	scanf("%d ", &T);
	while (T--) {
		for (int i = 1; i <= 9; i+=2) {
			for (int j = 1; j <= i; j+=2) {
				scanf("%d ", &arr[i][j]);
			}
		}
		for (int i = 1; i < 9; i+=2) {
			for (int j = 1; j <= i; j+=2) {
				int v = arr[i+2][j] + arr[i+2][j+2];
				arr[i+2][j+1] = (arr[i][j] - v)/2;
			}
		}
		for (int i = 2; i < 9; i+=2) {
			for (int j = 1; j <= i; j++) {
				arr[i][j] = arr[i+1][j] + arr[i+1][j+1];
			}
		}
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= i; j++) {
				if (j != 1) {
					printf(" %d", arr[i][j]);
				} else {
					printf("%d", arr[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}