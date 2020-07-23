#include <stdlib.h>
#include <stdio.h>

int N, M;
int arr[100001], cmp[100001];

int main() {
	while (scanf("%d %d ", &N, &M) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d ", &cmp[i]);
		}
		int p1, p2;
		p1 = p2 = 0;
		while (p1 < N && p2 < M) {
			if (arr[p1] == cmp[p2]) {
				p1++;
				p2++;
			} else {
				p1++;
			}
		}
		if (p2 == M) {
			printf("sim\n");
		} else {
			printf("nao\n");
		}
	}
	return 0;
}