#include <stdlib.h>
#include <stdio.h>

int N, T;
int h1, h2, m1, m2;

int distance(int ha, int ma, int hb, int mb) {
	int dist = 0;
	if (ha > hb) {
		dist += 60 - mb;
		dist += ma;
		dist += (ha - hb - 1) * 60;
	} else if (hb > ha) {
		dist += 60 - ma;
		dist += mb;
		dist += (hb - ha - 1) * 60;
	} else {
		dist += abs(ma - mb);
	}

	if (dist <= 5) {
		return 0;
	}

	if (ha > hb || ha == hb && ma > mb) {
		return -dist;
	} else {
		return dist;
	}
}

int main() {
	scanf("%d ", &T);
	while (T) {
		scanf("%d ", &N);
		int sum = 0;
		for (int i = 0; i < N; i++) {
			scanf(" %d:%d %d:%d | ", &h1, &m1, &h2, &m2);
			sum += distance(h1, m1, 8, 0);
			sum += distance(12, 0, h2, m2);
			scanf(" %d:%d %d:%d ", &h1, &m1, &h2, &m2);
			sum += distance(h1, m1, 14, 0);
			sum += distance(18, 0, h2, m2);
		}
		if (sum >= 0) {
			printf("+ %.2d:%.2d\n", sum/60, sum%60);
		} else {
			sum = -sum;
			printf("- %.2d:%.2d\n", sum/60, sum%60);
		}
		T--;
	}
	return 0;
}