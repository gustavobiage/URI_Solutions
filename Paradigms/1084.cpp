#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int N, D, M;
char number[100009];
int DP[10][100009];
char used[100009];
int index, value;

void search(int index) {
	if (index == N) {
		return;
	}

	int pointer = 9;
	int i;
	while (M && pointer >= 0) {
		i = DP[pointer][index];
		if (i != -1 && !used[i]) {
			used[i] = 1;
			M--;
			number[i] = pointer + '0';
			search(i+1);
		}
		pointer--;
	}
}

int main() {
	while (1) {
		scanf("%d %d ", &N, &D);
		if (!N && !D) {
			break;
		}
		M = N - D;
		scanf(" %s ", number);
		for (int i = 0; i < 10; i++) {
			DP[i][N] = -1;
		}

		for (int i = N-1; i >= 0; i--) {
			used[i] = 0;
			for (int j = 0; j < 10; j++) {
				DP[j][i] = DP[j][i+1];
			}
			DP[number[i]-'0'][i] = i;
		}

		for (int i = 0; i < N; i++) {
			number[i] = 10;
		}

		search(0);

		for (int i = 0; number[i] != '\0'; i++) {
			if (number[i] != 10) {
				printf("%c", number[i]);
			}
		}
		printf("\n");
	}
	return 0;
}