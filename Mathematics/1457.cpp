#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int T;
int N, K;
char excl[30];

long long unsigned int fac(int n, int k) {
	long long unsigned int res = 1;
	for (int i = n; i >= 1; i -= k) {
		res = res * i;
	}
	return res;
}

int main() {

	scanf("%d ", &T);
	while (T) {
		scanf("%d%s ", &N, excl);
		K = strlen(excl);

		printf("%Lu\n", fac(N, K));
		T--;
	}
	return 0;
}