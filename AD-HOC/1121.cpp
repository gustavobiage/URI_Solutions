#include <stdlib.h>
#include <stdio.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define RIGHT 10
#define LEFT 20

int N, M, S;
char map[200][200];
char instr[8000000];
int direction;

void updateDirection(int type) {
	if (type == RIGHT) {
		direction = direction + 1;
		direction = direction % 4;
	} else {
		direction = 4 + direction - 1;
		direction = direction % 4;
	}
}

int updatePosition(int* x, int* y, int direction) {
	if (direction == NORTH) {
		*y = *y - 1;
	} else if (direction == SOUTH) {
		*y = *y + 1;
	} else if (direction == WEST) {
		*x = *x - 1;
	} else if (direction == EAST) {
		*x = *x + 1;
	}
}

void prt_direction() {
	if (direction == NORTH) {
		printf("north\n");
	} else if (direction == EAST) {
		printf("east\n");
	} else if (direction == SOUTH) {
		printf("south\n");
	} else if (direction == WEST) {
		printf("west\n");
	} else {
		printf("%d\n", direction);
	}
}

int main() {

	int x, y;
	int old_x, old_y;
	int c;
	while (1) {

		scanf("%d %d %d ", &N, &M, &S);
		if (N == 0 && M == 0 && S == 0) {
			break;
		}

		c = 0;
		x = y = 0;

		for (int i = 0; i < N; i++) {
			scanf(" %s ", map[i]);
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'O') {
					direction = WEST;
					x = j;
					y = i;
				} else if (map[i][j] == 'N') {
					direction = NORTH;
					x = j;
					y = i;
				} else if (map[i][j] == 'S') {
					direction = SOUTH;
					x = j;
					y = i;
				} else if (map[i][j] == 'L') {
					direction = EAST;
					x = j;
					y = i;
				}
			}
		}

		scanf(" %s ", instr);

		for (int i = 0; i < S; i++) {
			if (instr[i] == 'D') {
				updateDirection(RIGHT);
			} else if (instr[i] == 'E') {
				updateDirection(LEFT);
			} else if (instr[i] == 'F') {
				old_x = x;
				old_y = y;
				updatePosition(&x, &y, direction);
				
				if (x < 0 || x >= M) {
					x = old_x;
				}

				if (y < 0 || y >= N) {
					y = old_y;
				}

				if (map[y][x] == '#') {
					x = old_x;
					y = old_y;
				} else if (map[y][x] == '*') {
					c++;
					map[y][x] = '.';
				}
			}
		}

		printf("%d\n", c);
	}


	return 0;
}