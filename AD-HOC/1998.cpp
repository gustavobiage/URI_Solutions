#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

int N;
int arr[502];
int sum;
int res;

int main() {
	while (1) {
		scanf("%d ", &N);
		if (N == -1) {
			break;
		}

		for (int i = 0; i <N; i++) {
			scanf("%d ", &arr[i]);
		}

		sum = 0;
		res = 1;
		for (int i = N-1; i >= 0; i--) {
			if ((arr[i] + sum) % (i+1) == 0) {
				// Pass
			} else {
				res = 0;
				goto PRT;
			}
			sum += (arr[i] + sum) / (i+1);
		}

		PRT:
		if (res) {
			printf("S\n");
		} else {
			printf("N\n");
		}

	}
	return 0;
}