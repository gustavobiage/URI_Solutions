#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char U[30];
char V[30];

int counter[10];

int search(int index, int len, int ceil) {
	if (index == len) {
		int i;
		for (i = 0; V[i] == '0'; i++);
		for (; i < len; i++) {
			printf("%c", V[i]);
		}
		printf("\n");
		return 1;
	}

	int a = U[index] - '0';
	if (ceil) {
		a = 9;
	}

	for (int i = a; i >= 0; i--) {
		if (counter[i] < 2) {
			counter[i]++;
			V[index] = i + '0';
			if (search(index + 1, len, ceil || i != a)) {
				return 1;
			}
			counter[i]--;
		}
	}

	return 0;
}

int main() {

	scanf(" %s ", U);
	for (int i = 0; i < 10; i++) {
		counter[i] = 0;
	}

	search(0, strlen(U), 0);

	return 0;
}