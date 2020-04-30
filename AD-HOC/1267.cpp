#include <stdlib.h>
#include <stdio.h>

int arr[500];
int v;
int N, D;
int main() {

	while (1) {

		scanf("%d %d ", &N, &D);
		
		if (N == 0 && D == 0) {
			break;
		}

		for (int i = 0; i < N; i++) {
			arr[i] = 1;
		}

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d ", &v);
				arr[j] = arr[j] && v;
			}
		}

		int yes = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] == 1) {
				yes = 1;
			}
		}

		if (yes) {
			printf("yes\n");
		} else {
			printf("no\n");
		}

	}
	return 0;
}