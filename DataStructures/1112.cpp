#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct query {
	int x1, y1;
	int x2, y2;
};

int X, Y, P;
int Q;
int byte[1001][1001];
int x, y, z, w;
int n;
char op;

void update(int x, int y, int val) {
	x++;
	y++;
	for (; x <= X; x+=x&-x) {
		for (int b = y; b <= Y; b+=b&-b) {
			byte[x][b] += val;
		}
	}
}

int get(int x, int y) {
	int ans = 0;
	for (; x; x-=x&-x) {
		for (int b = y; b; b-=b&-b) {
			ans += byte[x][b];
		}
	}
	return ans;
}

int get_query(struct query & q) {
	return get(q.x2, q.y2) - get(q.x1-1, q.y2) - get(q.x2, q.y1-1) + get(q.x1-1, q.y1-1);
}

struct query make_query(int a, int b, int c, int d) {
	a++; b++; c++; d++;
	struct query q;
	q.x1 = fmin(a, c);
	q.x2 = fmax(a, c);
	q.y1 = fmin(b, d);
	q.y2 = fmax(b, d);
	return q;
}

int main() {
	while (1) {
		scanf("%d %d %d ", &X, &Y, &P);
		if (!X && !Y && !P) {
			break;
		}
		for (int i = 1; i <= X; i++) {
			for (int j = 1; j <= Y; j++) {
				byte[i][j] = 0;
			}
		}
		scanf("%d ", &Q);
		struct query q;
		while (Q--) {
			scanf("%c ", &op);
			if (op == 'A') {
				scanf("%d %d %d ", &n, &x, &y);
				update(x, y, n);
			} else if (op == 'P') {
				scanf("%d %d %d %d ", &x, &y, &z, &w);
				q = make_query(x, y, z, w);
				printf("%d\n", get_query(q)*P);
			}
		}
		printf("\n");
	}

	return 0;
}