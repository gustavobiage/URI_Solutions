#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
char A[1002];
char B[1002];

int compare(int lenA, int lenB) {
	if (lenA < lenB) {
		return 0;
	}
	int j;
	for (int i = lenA - lenB; i < lenA; i++) {
		j = i - (lenA - lenB);
		// printf("%d(%c) %d(%c)\n", i, A[i], j, B[j]);
		if (A[i] != B[j]) {
			return 0;
		}
	}

	return 1;
}

int main() {

	scanf("%d ", &N);

	int lenA, lenB;
	int res;
	for (int i = 0; i < N; i++) {
		scanf(" %s %s ", A, B);
		lenA = strlen(A);
		lenB = strlen(B);

		res = compare(lenA, lenB);
		if (res) {
			printf("encaixa\n");
		} else {
			printf("nao encaixa\n");
		}
	}

	return 0;
}