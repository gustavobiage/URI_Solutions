#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int arr[100005];
int index;
int p, a, b;
int N, G;

int cmp(const void * a, const void * b) {
	int v1 = *((int *) a);
	int v2 = *((int *) b);
	return v1 - v2;
}

int main() {

	while (scanf("%d %d ", &N, &G) != EOF) {
		index = 0;
		p = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &a, &b);

			if (a - b <= 0) {
				arr[index++] = (a-b)*-1;
			} else {
				p += 3;
			}
		}

		qsort(arr, index, sizeof(int), cmp);

		for (int i = 0; i < index; i++) {
			if (G > 0) {
				a = fmin(arr[i] + 1, G);
				G = G - a;
				arr[i] -= a;
			}

			if (arr[i] == 0) {
				p++;
			} else if(arr[i] < 0) {
				p += 3;
			}
		}

		printf("%d\n", p);
	}
	return 0;
}