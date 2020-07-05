#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100000

int IP, M;
int PC, NA;
int byte[N + 1];
int c, v;

void update(int x) {
	for (; x <= N; x+=x&-x) {
		byte[x]++;
	}
}

int get(int x) {
	int ans = 0;
	if (x < 0) {
		x = 0;
	}
	if (x > N) {
		x = N;
	}
	for (; x; x-=x&-x) {
		ans += byte[x];
	}
	return ans;
}

int main() {
	while (scanf("%d %d ", &IP, &M) != EOF) {
		memset(byte, 0, sizeof(int)*(N+1));
		c = 0;
		for (int i = 0; i < M; i++) {
			scanf("%d %d ", &PC, &NA);
			v = get(PC+IP) - get(PC-IP-1);
			if (v <= NA) {
				c++;
				update(PC);
			}
		}
		printf("%d\n", c);
	}
	return 0;
}