#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define INF 20000000

int N;
double arr[200];
double med;
double sum;
double min;

int main() {

	while (scanf("%d ", &N) != EOF) {

		for (int i = 0; i < N; i++) {
			scanf("%lf ", &arr[i]);
		}

		min = INF;
		for (int i = 0; i < N; i++) {
			sum = 0;
			for (int j = 0; j < N; j++) {
				sum += abs(arr[i] - arr[j]);
			}
			if (sum < min) {
				min = sum;
			}
		}

		printf("%0.2lf\n", min);
	}

	return 0;
}