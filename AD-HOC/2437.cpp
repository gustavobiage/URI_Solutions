#include <stdlib.h>
#include <stdio.h>

int X1, Y1, X2, Y2;

int main() {
	scanf("%d %d %d %d ", &X1, &Y1, &X2, &Y2);
	int res = abs(X1 - X2) + abs(Y1 - Y2);
	printf("%d\n", res);
	return 0;
}