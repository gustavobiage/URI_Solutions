#include <stdlib.h>
#include <stdio.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int N;
char commands[1001];
int direction;

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		direction = NORTH;
		scanf(" %s ", commands);
		for (int i = 0; i < N; i++) {
			if (commands[i] == 'D') {
				direction = (direction + 1) % 4;
			} else {
				direction = (direction - 1 + 4) % 4;
			}
		}
		switch (direction) {
			case NORTH:
			printf("N\n");
			break;
			case EAST:
			printf("L\n");
			break;
			case SOUTH:
			printf("S\n");
			break;
			case WEST:
			printf("O\n"); 
		}
	}
	return 0;
}