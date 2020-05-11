#include <stdlib.h>
#include <stdio.h>
	
int N;
int sum;
int med;
int arr[10005];

int main() {

	while (scanf("%d ", &N) != EOF) {
		sum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
			sum += arr[i];
		}

		if (sum % N) {
			printf("-1\n");
		} else {
			med = sum / N;
			sum = 0;
			for (int i = 0; i < N; i++) {
				if (arr[i] > med) {
					sum += arr[i] - med;
				} else {
					sum += med - arr[i];
				}
			}
			printf("%d\n", sum / 2 + 1);
		}	
	}
	return 0;
}