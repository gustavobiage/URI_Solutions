#include <stdlib.h>
#include <stdio.h>

char str1[1000], str2[1000];
int v1, v2;

int getValue(int n) {
	int digit;
	int sum; int v;
	while (n > 9) {
		v = n;
		sum = 0;
		while (v) {
			digit = v % 10;
			v = v / 10;
			sum += digit;
		}
		n = sum;
	}

	return n;
}

int main() {

	while (1) {
		scanf(" %s %s ", str1, str2);

		v1 = 0;
		for (int i = 0; str1[i] != '\0'; i++) {
			v1 += (str1[i] - '0');
		}

		v2 = 0;
		for (int i = 0; str2[i] != '\0'; i++) {
			v2 += (str2[i] - '0');
		}

		if (!v1 && !v2) {
			break;
		}
		
		v1 = getValue(v1);
		v2 = getValue(v2);

		if (v1 > v2) {
			printf("1\n");
		} else if (v2 > v1) {
			printf("2\n");
		} else {
			printf("0\n");
		}
	}

	return 0;
}