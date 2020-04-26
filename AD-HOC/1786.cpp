#include <stdlib.h>
#include <stdio.h>

char a[12];
char b1, b2;
int sum;

int main() {
	while (scanf(" %s ", a) != EOF) {
		sum = 0;
		for (int i = 0; i < 9; i++) {
			sum += (a[i] - '0') * (i+1);
		}
		b1 = sum % 11;
		b1 = b1 % 10;
		b1 += '0';

		sum = 0;
		for (int i = 0; i < 9; i++) {
			sum += (a[i] - '0') * (10 - i - 1);
		}
		b2 = sum % 11;
		b2 = b2 % 10;
		b2 += '0';

		for (int i = 0; i < 9; i++) {
			if (i != 0 && i % 3 == 0) {
				printf(".");
			}
			printf("%c", a[i]);
		}

		printf("-%c%c\n", b1, b2);
	}

	return 0;
}