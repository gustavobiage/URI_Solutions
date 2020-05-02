#include <stdlib.h>
#include <stdio.h>

int N;
int C, D, P;
int pos, wrong;
int f;

int main() {
	int arr[1009];

	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}

		for (int i = 0; i <= N; i++) {
			arr[i] = -1;
		}

		wrong = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &C, &P);
			D = i + 1;
			pos = D+P;
			if (pos >= 1 && pos <= N && arr[pos] == -1) {
				arr[pos] = C;
			} else {
				wrong = 1;
			}
		}

		if (wrong) {
			printf("-1\n");
		} else {
			f = 1;
			for (int i = 0; i < N; i++) {
				if (f) {
					printf("%d", arr[i+1]);
					f = 0;
				} else {
					printf(" %d", arr[i+1]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}