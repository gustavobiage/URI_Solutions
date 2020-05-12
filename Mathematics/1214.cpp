#include <stdlib.h>
#include <stdio.h>

int C, N;
int sum, c;
double med;
int arr[1002];

int main() {

	scanf("%d ", &C);
	while (C) {
		scanf("%d ", &N);
		sum = 0;
		c = 0;
		for (int i = 0; i <N; i++) {
			scanf("%d ", &arr[i]);
			sum += arr[i];
		}
		med = (double) sum / N;
		for (int i = 0; i < N; i++) {
			if (arr[i] > med) {
				c++;
			}
		}
		printf("%0.3lf%c\n", (double) c*100 / N, '%');
		C--;
	}
	return 0;
}