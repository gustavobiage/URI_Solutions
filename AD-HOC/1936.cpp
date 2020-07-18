#include <stdlib.h>
#include <stdio.h>

int N;
int cnt;
int n, c;
int main() {
	scanf("%d ", &N);
	while (N) {
		n = 1;
		c = 1;
		while (n*(c+1) <= N) {
			n = n * (c+1);
			c++;
		}
		N -= n;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}