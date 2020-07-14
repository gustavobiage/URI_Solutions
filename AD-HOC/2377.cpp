#include <stdlib.h>
#include <stdio.h>

int L, D;
int K, P;

int main() {
	scanf("%d %d ", &L, &D);
	scanf("%d %d ", &K, &P);
	int amnt = L / D;
	int price = L*K + amnt*P;
	printf("%d\n", price);
	return 0;
}