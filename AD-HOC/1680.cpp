#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <utility>

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

using namespace std;

char oper[250];
int X, Y;
int direction;

pair<int, int> getDelta(int* direction, char command) {
	if (*direction == RIGHT) {
		if (command == 'V') {
			*direction = UP;
			return make_pair(0, 10);
		} else {
			*direction = DOWN;
			return make_pair(0, -10);
		}
	} else if (*direction == LEFT) {
		if (command == 'V') {
			*direction = DOWN;
			return make_pair(0, -10);
		} else {
			*direction = UP;
			return make_pair(0, 10);
		}
	} else if (*direction == UP) {
		if (command == 'V') {
			*direction = LEFT;
			return make_pair(-10, 0);
		} else {
			*direction = RIGHT;
			return make_pair(10, 0);
		}
	} else if (*direction == DOWN) {
		if (command == 'V') {
			*direction = RIGHT;
			return make_pair(10, 0);
		} else {
			*direction = LEFT;
			return make_pair(-10, 0);
		}
	}
}

int main() {
	pair<int, int> p;
	while (scanf(" %s ", oper) != EOF) {
		printf("300 420 moveto\n");
		printf("310 420 lineto\n");
		X = 310;
		Y = 420;
		direction = RIGHT;

		for (int i = 0; i < strlen(oper); i++) {
			p = getDelta(&direction, oper[i]);
			X += p.first;
			Y += p.second;
			printf("%d %d lineto\n", X, Y);
		}

		printf("stroke\n");
		printf("showpage\n");
	}

	return 0;
}