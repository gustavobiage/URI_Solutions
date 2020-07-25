#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

double arr[5];
double sum;

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%lf ", &arr[i]);
	}
	std::sort(arr, arr+5);
	sum = 0;
	for (int i = 1; i < 4; i++) {
		sum += arr[i];
	}
	printf("%0.1lf\n", sum);
	return 0;
}