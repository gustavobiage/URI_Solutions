#include <stdlib.h>
#include <stdio.h>

int DP[1000001];
long long int n;
int b, c;

int test(int index) {
	if (index >= 8) {
		return DP[index-4] == DP[0] && DP[index-3] == DP[1] && DP[index-2] == DP[2] && DP[index-1] == DP[3];
	}
	return 0;
}

int main() {
	c = 0;
	while (1) {
		scanf("%Ld %d ", &n, &b);
		if (!n && !b) {
			break;
		}
		c++;
		DP[0] = 1 % b;
		DP[1] = 1 % b;
		int i;
		for (i = 2; n != 1 && !test(i); i++) {
			DP[i] = (DP[i-1] + DP[i-2] + 1) % b;
		}
		printf("Case %d: %Ld %d %d\n", c, n, b, DP[n%(i-4)]);
	}
	return 0;
}