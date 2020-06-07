#include <stdlib.h>
#include <stdio.h>

long long unsigned N;

int arr[1000000];

int main () {

	scanf("%Lu ", &N);
	long long unsigned sum = 0;
	long long unsigned all = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
		sum += i+1;
		all += arr[i];
	}
	
	if ((all - sum) % N == 0) {
		int base = (all - sum) / N;
		sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] > base + i + 1) {
				sum += arr[i] - (base + i + 1);
			}
		}

		printf("%Lu\n", sum);
	} else {
		printf("-1\n");
	}
	return 0;
}