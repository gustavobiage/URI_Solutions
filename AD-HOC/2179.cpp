#include <stdlib.h>
#include <stdio.h>
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int N;
int X, Y;
int mat[15][15];
int values[250];
int down, left, right, up;
int order[] = {RIGHT, DOWN, LEFT, UP};
int cmove;
int visited, count, pointer;

int move(int direction) {
	if (direction == RIGHT) {
		X += 1;
	} else if (direction == DOWN) {
		Y += 1;
	} else if (direction == LEFT) {
		X -= 1;
	} else if (direction == UP) {
		Y -= 1;
	}
}

void change_direction() {
	pointer = (pointer + 1) % 4;
	int direction = order[pointer];
	if (direction == LEFT) {
		cmove = left;
		left += 2;
	} else if (direction == RIGHT) {
		cmove = right;
		right += 2;
	} else if (direction == UP) {
		cmove = up;
		up += 2;
	} else if (direction == DOWN) {
		cmove= down;
		down += 2;
	}
}

int main() {
	scanf("%d %d %d ", &N, &X, &Y);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat[i][j] = N * j + i + 1;
		}
	}
	right = down = 1;
	left = up = 2;
	visited = count = cmove = 0;
	pointer = -1;
	while (visited < N*N) {
		if (X >= 0 && X < N && Y >= 0 && Y < N) {
			values[visited] = mat[X][Y];
			visited += 1;
		}
		if (cmove == 0) {
			change_direction();
		}
		int direction = order[pointer];
		move(direction);
		cmove--;
		count += 1;
	}
	for (int i = 0; i < visited; i++) {
		if (i == 0) {
			printf("%d", values[i]);
		} else {
			printf(" %d", values[i]);
		}
	}
	printf("\n%d\n", count);
	return 0;
}