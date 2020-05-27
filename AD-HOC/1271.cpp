#include <stdlib.h>
#include <stdio.h>


int N, R, Q;
int arr[50001];
int pos[50001];
int a, b;

void swap(int a, int b) {
	int v1 = arr[a];
	int v2 = arr[b];
	arr[a] = v2;
	arr[b] = v1;
	pos[v1] = b;
	pos[v2] = a;
}

int main() {
	int c = 0;

	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		c++;

		for (int i = 1; i <= N; i++) {
			arr[i] = i;
			pos[i] = i;
		}

		scanf("%d ", &R);
		for (int i = 0; i < R; i++) {
			scanf("%d %d ", &a, &b);
			for (int j = 0; j <= (b-a)/2; j++) {
				swap(a+j, b-j);
			}
			// for (int i = 1; i <= N; i++) {
			// 	printf("%d ", arr[i]);
			// }
			// printf("\n");
		}

		printf("Genome %d\n", c);
		scanf("%d ", &Q);
		for (int i = 0; i < Q; i++) {
			scanf("%d ", &a);
			printf("%d\n", pos[a]);
		}
	}
	return 0;
}