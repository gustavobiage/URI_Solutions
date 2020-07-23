#include <stdlib.h>
#include <stdio.h>

struct counter {
	int b;
	int in;
};

int N;
long long int cx, cy;
long long int r1, r2;

struct counter c[2];

long long int distance(int x, int y) {
	return (x-cx)*(x-cx)+(y-cy)*(y-cy);
}

void eval(struct counter & c, long long int d) {
	if (d < r1*r1) {
		c.in++;
	} else if (d <= r2*r2) {
		c.b++;
	}
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		int x, y;
		scanf("%Ld %Ld %Ld %Ld ", &cx, &cy, &r1, &r2);
		c[0].in = c[1].in = c[0].b = c[1].b = 0;
		for (int i = 0; i < N*2; i++) {
			scanf("%d %d ", &x, &y);
			eval(c[i%2], distance(x, y));
		}
		if (c[0].in != c[1].in) {
			if (c[0].in > c[1].in) {
				printf("C > P\n");
			} else {
				printf("P > C\n");
			}
		} else if (c[0].b != c[1].b) {
			if (c[0].b > c[1].b) {
				printf("C > P\n");
			} else {
				printf("P > C\n");
			}
		} else {
			printf("C = P\n");
		}
	}
	return 0;
}