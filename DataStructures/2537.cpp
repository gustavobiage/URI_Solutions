#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct query {
	int x1, y1;
	int x2, y2;
};

int byte[1001*1001];
int N, M;
int v, a, b, x, y;
struct query q;

int get(int x, int y) {
	int ans = 0;
	for (; x; x-=x&-x) {
		for (int b = y; b; b-=b&-b) {
			ans += byte[x*N + b];
		}
	}
	return ans;
}

int getQuery(struct query &q) {
	return get(q.x2, q.y2) - get(q.x1-1, q.y2) - get(q.x2, q.y1-1) + get(q.x1-1, q.y1-1);
}

void update(int x, int y, int val) {
	for (; x <= N; x+=x&-x) {
		for (int b = y; b <= N; b+=b&-b) {
			byte[x*N + b] += val;
		}
	}
}

int main() {
	
	while (scanf("%d %d ", &N, &M) != EOF) {
		memset(byte, 0, (N+1)*(N+1)*sizeof(int));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d ", &v);
				if (v) {
					update(i+1, j+1, 1);
				}
			}
		}

		for (int i = 0; i < M; i++) {
			scanf("%d %d ", &a, &b);
			update(a, b, 1);
			scanf("%d %d %d %d ", &x, &y, &a, &b);
			q.x1 = fmin(x, a);
			q.x2 = fmax(x, a);
			q.y1 = fmin(y, b);
			q.y2 = fmax(y, b);
			printf("%d\n", getQuery(q));
		}
	}

	return 0;
}