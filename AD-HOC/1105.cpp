#include <stdlib.h>
#include <stdio.h>

int B, N;
int arr[50];
int C, D, V;

int main() {

	while (1) {
		scanf("%d %d ", &B, &N);
		if (!B && !N) {
			break;
		}

		for (int i = 1; i <= B; i++) {
			scanf("%d ", &arr[i]);
		}


		int res = 1;
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d ", &D, &C, &V);
			arr[C] += V;
			arr[D] -= V;
		}

		for (int i = 1; i <= B; i++) {
			if (arr[i] < 0) {
				printf("N\n");
				goto CONTINUE;
			}
		}

		if (0) {
			CONTINUE:;
			continue;
		}
		printf("S\n");
	}

	return 0;
}