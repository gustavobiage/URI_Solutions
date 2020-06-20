#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
char number[1001];
int zeros, ones;
int digit;

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		ones = zeros = 0;
		for (int i = 0; i < N; i++) {
			scanf(" %s ", number);
			for (int j = 0; number[j] != '\0'; j++) {
				if (j%2) {
					ones += number[j] - '0';
				} else {
					zeros += number[j] - '0';
				}
			}
			int sum = 0;
			while (ones) {
				digit = ones % 10;
				ones = ones / 10;
				sum += digit;
			}
			while (zeros) {
				digit = zeros % 10;
				zeros = zeros / 10;
				sum += digit;
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}