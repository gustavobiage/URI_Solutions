#include <stdlib.h>
#include <stdio.h>

int fib[610000];
int threeb[61];
long long unsigned int mul[61000000];
long long unsigned int tmul[61];

int N;

int contiansThree(long long unsigned n) {
	int digit;
	while (n) {
		digit = n % 10;
		if (digit == 3) {
			return 1;
		} 
		n = n / 10;
	}
	return 0;
}

void init() {
	int j = 1;
	int i = 3;
	while (j < 61) {
		fib[i] = (fib[i-1] + fib[i-2]) % 3;
		mul[i] = mul[i-1] + mul[i-2] + (fib[i-1] + fib[i-2])/3;
		if (fib[i] == 0 || contiansThree(3*mul[i] + fib[i])) {
			tmul[j] = mul[i];
			threeb[j] = fib[i];
			j++;
		}
		i++;
	}
}

int main() {
	fib[0] = 0;
	mul[0] = 0;
	fib[1] = 1;
	mul[1] = 0;
	fib[2] = 1;
	mul[2] = 0;
	init();
	while (scanf("%d ", &N) != EOF) {
		printf("%Lu\n", 3*tmul[N] + threeb[N]);
	}
	return 0;
}