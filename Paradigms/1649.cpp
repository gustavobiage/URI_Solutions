#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, M, R, C;
int arr[101*101];
int cmp[101*101];
char v;
int ans;

int search() {
	int ans = 0;
	int diff = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cmp[i*M+j] != arr[i*M+j]) {
				if (i+R-1 < N && j+C-1 < M) {
					for (int k = i; k < i+R; k++) {
						for (int l = j; l < j + C; l++) {
							arr[k*M+l] = (arr[k*M+l]+1) % 2;
						}
					}
					ans++;
				} else {
					diff = 1;
				}
			}
		}
	}

	if (!diff) {
		return ans;
	}
	return -1;
}

int main() {
	while (1) {
		scanf("%d %d %d %d ", &N, &M, &R, &C);
		if (!N && !M && !R && !C) {
			break;
		}
		memset(arr, 0, sizeof(int)*N*M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%c", &v);
				cmp[i*M+j] = v-'0';
				arr[i*M+j] = 0;
			}
			scanf("%*c");
		}
		printf("%d\n", search());
	}
	return 0;
}