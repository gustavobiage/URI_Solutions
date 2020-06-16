#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int M, N;
int A, B;
char arr[102][102];
char output[102];
int pointer;
int Ka, Kb;

int main() {
	while (1) {
		scanf("%d %d ", &N, &M);
		if (!N && !M) {
			break;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%c ", &arr[i][j]);
			}
		}
		scanf("%d %d ", &A, &B);
		Ka = A / N;
		Kb = B / M;
		for (int i = 0; i < N; i++) {
			pointer = 0;
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < Kb; k++) {
					output[pointer++] = arr[i][j];
				}
			}
			output[pointer] = '\0';
			for (int k = 0; k < Ka; k++) {
				printf("%s\n", output);
			}
		}
		printf("\n");
	}
	return 0;
}