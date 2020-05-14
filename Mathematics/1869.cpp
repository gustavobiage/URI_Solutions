#include <stdlib.h>
#include <stdio.h>

#define LLU long long unsigned

LLU N;
int reverse[100];

const char * alf = "0123456789ABCDEFGHIJKLMNOPQRSTUV";

void eval(LLU n) {
	int index = 0;
	int digit;
	while (n) {
		digit = n % 32;
		n = n / 32;
		reverse[index++] = digit;
	}

	for (int i = index-1; i >= 0; i--) {
		printf("%c", alf[reverse[i]]);
	}
	printf("\n");
}

int main() {

	while (1) {
		scanf("%Lu ", &N);
		if (!N) {
			break;
		}

		eval(N);
	}

	printf("0\n");
	
	return 0;
}