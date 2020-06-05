#include <stdlib.h>
#include <stdio.h>

int N;
long double price;
int amount;
long double bestPrice;

int main() {
	scanf("%d ", &N);
	bestPrice = 1001;
	for (int i = 0; i < N; i++) {
		scanf("%Lf %d ", &price, &amount);
		price = price / amount;
		if (price < bestPrice) {
			bestPrice = price;
		}
	}

	printf("%0.2Lf\n", bestPrice*1000);

	return 0;
}