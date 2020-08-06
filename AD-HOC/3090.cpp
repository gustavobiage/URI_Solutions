#include <stdlib.h>
#include <stdio.h>

#define LLD long long int

LLD N, M, S;
LLD x, y, h;
LLD cnt[2];
int c;

int main() {
	scanf("%Ld %Ld %Ld ", &N, &M, &S);
	for (int i = 0; i < S; i++) {
		scanf("%Ld %Ld %Ld ", &x, &y, &h);
		c = M*x > y*N;
		cnt[c] += h;
	}
	printf("%Ld %Ld\n", cnt[0], cnt[1]);
	return 0;
}