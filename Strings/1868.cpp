#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <string.h>

#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

int N;
char arr[25][25];
int X, Y;

int direction;
int step, aux;
int amount;

void next() {
	if (direction == LEFT) {
		Y--;
	} else if (direction == RIGHT) {
		Y++;
	} else if (direction == UP) {
		X--;
	} else if (direction == DOWN) {
		X++;
	}
}

int main() {

	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		memset(arr, 'O', 25*25);
		X = Y = N/2;
		direction = RIGHT;
		step = 1;
		aux = step;
		amount = 2;
		arr[X][Y] = 'X';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
		printf("@\n");

		for (int i = 0; i < N*N - 1; i++) {
			if (aux == 0) {
				amount--;
				aux = step;
				direction = (direction + 1)%4;
			}

			if (amount == 0) {
				step++;
				aux = step;
				amount = 2;
			}

			arr[X][Y] = 'O';
			next();
			arr[X][Y] = 'X';
			for (int k = 0; k < N; k++) {
				for (int j = 0; j < N; j++) {
					printf("%c", arr[k][j]);
				}
				printf("\n");
			}
			printf("@\n");
			aux--;
		}

	}

	return 0;
}