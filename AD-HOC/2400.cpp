#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
int bit[100001];
int v, c;

int get(int n) {
	int ans = 0;
	while (n) {
		ans += bit[n];
		n-=n&-n;
	}
	return ans;
}

void update(int n) {
	while (n <= N) {
		bit[n]++;
		n+=n&-n;
	}
}

int main() {
	scanf("%d ", &N);
	memset(bit, 0, sizeof(int)*(N+1));
	for (int i = 0; i < N; i++) {
		scanf("%d ", &v);
		c += get(N) - get(v);
		update(v);
	}

	printf("%d\n", c);
	return 0;
}

//Reference:
// https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/