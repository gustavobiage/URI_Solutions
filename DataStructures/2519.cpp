#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct query {
	int x1, y1;
	int x2, y2;
};

int byte[1001][1001];
int arr[1001][1001];
int N, M, Q;
int v, a, b, x, y;
struct query q;

int get(int x, int y) {
	int ans = 0;
	for (; x; x-=x&-x) {
		for (int b = y; b; b-=b&-b) {
			ans += byte[x][b];
		}
	}
	return ans;
}

int getQuery(struct query &q) {
	return get(q.x2, q.y2) - get(q.x1-1, q.y2) - get(q.x2, q.y1-1) + get(q.x1-1, q.y1-1);
}

void update(int x, int y, int val) {
	for (; x <= N; x+=x&-x) {
		for (int b = y; b <= M; b+=b&-b) {
			byte[x][b] += val;
		}
	}
}

int main() {
	
	while (scanf("%d %d ", &N, &M) != EOF) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= M; j++) {
				byte[i][j] = 0;
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%d ", &v);
				if (v) {
					update(i, j, v);
					arr[i][j] = 1;
				}
			}
		}

		scanf("%d ", &Q);
		for (int i = 0; i < Q; i++) {
			scanf("%d %d %d %d %d ", &v, &x, &y, &a, &b);
			if (v) {
				q.x1 = fmin(x, a);
				q.x2 = fmax(x, a);
				q.y1 = fmin(y, b);
				q.y2 = fmax(y, b);
				printf("%d\n", getQuery(q));
			} else {
				update(x, y, -1);
				update(a, b, 1);
			}
		}
	}

	return 0;
}