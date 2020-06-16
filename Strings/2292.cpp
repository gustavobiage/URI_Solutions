#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LLU long long unsigned

int N, P;
LLU K;
LLU arr[61];
char line[500], v;
int pointer;

int main() {
	scanf("%d ", &N);
	while (N) {
		fgets(line, 500, stdin);
		P = 0;
		memset(arr, 0, sizeof(LLU)*61);
		for (int i = 0;; i++) {
			if (line[i] == ' ') {
				line[i] = '\0';
				pointer = i+1;
				break;
			}
			P++;
		}
		int index = 0;
		while (sscanf(&line[index], "%c ", &v) != EOF) {
			if (v == 'X') {
				arr[index] = 0;
			} else if (v == 'O') {
				arr[index] = 1;
			}
			index++;
		}

		sscanf(&line[pointer], "%Lu ", &K);

		for (int i = 0; i < P; i++) {
			arr[i] += K;
			K = arr[i] / 2;
			if (arr[i] & 1) {
				printf("O");
			} else {
				printf("X");
			}
		}
		printf("\n");
		
		N--;
	}
	return 0;
}