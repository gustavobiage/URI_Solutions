#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LLD long long int
#define MOD 1000000007

char line[1002];
LLD mul, sum;
int len;

int main() {
	while (scanf(" %s ", line) != EOF) {
		len = strlen(line);
		mul = 1;
		sum = 0;
		for (int i = len-1; i >= 0; i--) {
			sum += ((line[i] - 'A') * mul) % MOD;
			mul = (mul * 26) % MOD;
		}
		printf("%Ld\n", sum % MOD);
	}
	return 0;
}