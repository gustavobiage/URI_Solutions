#include <stdlib.h>
#include <stdio.h>

#define DONE 0
#define NEXT 1

int P, S, N;
int T[3];
int D1, D2;

struct player {
	int pos;
	int trapped;
};

struct player Pl[10];
int turn;
int index;

int move() {
	if (Pl[turn].trapped == 1) {
		Pl[turn].trapped = 0;
		return NEXT;
	}

	index++;
	if (index > N) {
		return 0;
	}

	scanf("%d %d ", &D1, &D2);
	int d = D1 + D2;
	
	Pl[turn].pos += d;
	
	if (Pl[turn].pos == T[0] ||
		Pl[turn].pos == T[1] ||
		Pl[turn].pos == T[2]) {
		Pl[turn].trapped = 1;
	}

	if (Pl[turn].pos > S) {
		return DONE;
	}
	return NEXT;
}

int main() {
	while (1) {
		scanf("%d %d ", &P, &S);
		if (P == 0 && S == 0) {
			break;
		}
		
		for (int i = 0; i < P; i++) {
			Pl[i].pos = 0;
			Pl[i].trapped = 0;
		}

		index = 0;
		turn = 0;

		scanf("%d %d %d ", &T[0], &T[1], &T[2]);
		scanf("%d ", &N);
		
		while (move()) {
			turn = (turn + 1) % P;
		}

		while (index < N) {
			scanf("%d %d ", &D1, &D2);
			index++;
		}

		printf("%d\n", turn + 1);
	}
	return 0;
}