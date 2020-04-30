#include <stdlib.h>
#include <stdio.h>

int C;
int a, b, c;
char opr;
int res;

int operate(int a, int b, char op) {
	if (op == '+') {
		return a + b;
	} else if (op == '-') {
		return a - b;
	} else if (op == 'x') {
		return a * b;
	}
	return -3;
}

int main() {

	scanf("%d ", &C);
	for (int i = 0; i < C; i++) {
		scanf("%d %c %d %*c %d ", &a, &opr, &b, &c);
		res = operate(a, b, opr);
		printf("E");
		for (int i = 0; i < abs(res - c); i++) {
			printf("r");
		}
		printf("ou!\n");
	}
	return 0;
}