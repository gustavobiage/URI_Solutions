#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

int N, S;
int amnt;
int x, y;
int ml, mr, mu, md;
int direction;

int main() {
	while (scanf("%d %d ", &N, &S) != EOF) {
		mr = N-1;
		ml = 0;
		mu = 1;
		md = N-1;
		amnt = N*N - S;
		direction = LEFT;
		x = 0; y = N-1;
		int lx, ly;
		while (amnt > 0) {
			lx = x;
			ly = y;
			if (direction == RIGHT) {
				if (y + amnt < mr) {
					y = y+amnt;
				} else {
					y = mr;
				}
				mr--;
			} else if (direction == LEFT) {
				if (y-amnt > ml) {
					y = y-amnt;
				} else {
					y = ml;
				}
				ml++;
			} else if (direction == UP) {
				if (x - amnt > mu) {
					x = x-amnt;
				} else {
					x = mu;
				}
				mu++;
			} else if (direction == DOWN) {
				if (x+amnt < md) {
					x = x + amnt;
				} else {
					x = md;
				}
				md--;
			}
			amnt -= (abs(lx - x) + abs(ly - y));
			direction = (direction + 1) % 4;
		}
		printf("%d %d\n", x, y);
	}
}