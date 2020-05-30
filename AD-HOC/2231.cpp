#include <stdlib.h>
#include <stdio.h>

long double arr[10001], sum;
int N, M, maximum, minimum;
int v, c;

int main() {
	c = 0;
	while (1) {
		scanf("%d %d ", &N, &M);
		if (!N && !M) {
			break;
		}
		c++;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			arr[i] = (long double) v / M;
		}
		int pointer = 0;
		sum = 0;
		for (; pointer < M; pointer++) {
			sum += arr[pointer];
		}
		maximum = minimum = (int) sum;
		for (; pointer < N; pointer++) {
			sum -= arr[pointer - M];
			sum += arr[pointer];

			if (sum < minimum) {
				minimum = (int) sum;
			}
			if (sum > maximum) {
				maximum = (int) sum;
			}
		}
		printf("Teste %d\n", c);
		printf("%d %d\n", minimum, maximum);
		printf("\n");
	}
}