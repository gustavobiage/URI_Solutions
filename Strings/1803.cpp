#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char arr[4][85];
int N;
char first[5], last[5], number[5];
int F, L;
int v, m;

int main() {
	for (int i = 0; i < 4; i++) {
		scanf(" %s ", arr[i]);
	}
	N = strlen(arr[0]);
	for (int i = 0; i < 4; i++) {
		first[i] = arr[i][0];
		last[i] = arr[i][N-1];
	}
	first[4] = last[4] = '\0';
	sscanf(first, "%d ", &F);
	sscanf(last, "%d ", &L);
	N -= 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++) {
			number[j] = arr[j][i];
		}
		number[5] = '\0';
		sscanf(number, "%d ", &m);
		v = (F * m + L) % 257;
		printf("%c", (char)v);
	}
	printf("\n");
	return 0;
}