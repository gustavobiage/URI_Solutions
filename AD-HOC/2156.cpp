#include <stdlib.h>
#include <stdio.h>

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

int L, C, I;

char map[102][102];
char oper[10001];
int c;
int X, Y;
int direction;

void move(int direction) {
	int x, y;
	x = X;
	y = Y;
	if (direction == RIGHT) {
		y = Y + 1;
	} else if (direction == LEFT) {
		y = Y - 1;
	} else if (direction == UP) {
		x = X - 1;
	} else if (direction == DOWN) {
		x = X + 1;
	}

	if (x < 0 || x >= L || y < 0 || y >= C || map[x][y] == '#') {
		return;
	}

	if (map[x][y] == '*') {
		c++;
		map[x][y] = ' ';
	}

	X = x;
	Y = y;
}

int getDirection(char c) {
	if (c == 'U') {
		return UP;
	} else if (c == 'D') {
		return DOWN;
	} else if (c == 'L') {
		return LEFT;
	} else if (c == 'R') {
		return RIGHT;
	}
	return -1;
}

int main() {

	while (1) {
		scanf("%d %d %d ", &L, &C, &I);
		if (!C && !L && !I) {
			break;
		}
		c = 0;
		for (int i = 0; i < L; i++) {
			fgets(map[i], 102, stdin);
			for (int j = 0; j < C; j++) {
				if (map[i][j] == '<') {
					X = i;
					Y = j;
				}
			}
		}
		scanf(" %s ", oper);
		for (int i = 0; i < I; i++) {
			if (oper[i] == 'W') {
				move(direction);
			} else {
				direction = getDirection(oper[i]);
			}
		}
		printf("%d\n", c);
	}
	return 0;
}