#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct query {
	int x1, y1;
	int x2, y2;
};

int N, M, Q, S;
long long int amnt_zero[201][201];
long long int DP[201][201];
struct query q;
int v, res;

void update(int x, int y) {
	amnt_zero[x][y] = 1;
}

void build() {
	for (int i = 1; i <= N; i++) {
		int s = 0;
		for (int j = 1; j <= M; j++) {
			s += amnt_zero[i][j];
			DP[i][j] = DP[i-1][j] + s;
		}
	}
}

long long int get(int x, int y) {
	return DP[x][y];
}

long long int make_query(int a, int b, int c, int d) {
	q.x1 = fmin(a, c);
	q.x2 = fmax(a, c);
	q.y1 = fmin(b, d);
	q.y2 = fmax(b, d);
	return get(q.x2, q.y2) - get(q.x2, q.y1-1) - get(q.x1-1, q.y2) + get(q.x1-1, q.y1-1);
}

int main() {
	scanf("%d %d ", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d ", &v);
			if (!v) {
				update(i, j);
			}
		}
	}
	build();
	scanf("%d ", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d ", &S);
		res = 0;
		for (int i = 1; i <= N-S+1; i++) {
			for (int j = 1; j <= M-S+1; j++) {
				v = make_query(i, j, i+S-1, j+S-1);
				if (!v) {
					res = 1;
					goto END;
				}
			}
		}
		END:;
		if (res) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}