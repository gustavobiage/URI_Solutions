#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int byte[100001];
int v;
long long int c;
int N;

long long int get(int n) {
	long long int sum = 0;
	while (n) {
		sum += byte[n];
		n-=n&-n;
	}
	return sum;
}

void update(int n, int val) {
	while (n <= N) {
		byte[n] += val;
		n+=n&-n;
	}
}

int main() {
	while (scanf("%d ", &N) != EOF) {
		memset(byte, 0, sizeof(int)*(N+1));
		c = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			c += get(v-1);	
			update(v, 1);
		}
		printf("%Ld\n", c);
	}
	return 0;
}