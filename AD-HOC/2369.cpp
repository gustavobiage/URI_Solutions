#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int arr[] = {30-10, 100-30, 10000};
int w[] = {1, 2, 5};
int len = 3;

int N, n;
int price;

int main() {
	scanf("%d ", &N);
	price = 7;
	N -= fmin(N, 10);
	for (int i = 0; i < len && N; i++) {
		n = fmin(N, arr[i]);
		N -= n;
		price += n*w[i];
	}
	printf("%d\n", price);
	return 0;
}