#include <stdlib.h>
#include <stdio.h>
#include <set>

#define MOD 1000000007

using namespace std;
int N, L;
int send[1001][2001];
int K[1001];
long long int DP[1001];
long long int counter;
set<int> s;

int search(int n) {
	if (n > L) {
		s.insert(n);
		return 1;
	}

	if (DP[n] != -1) {
		return DP[n];
	}

	long long int c = 0;
	for (int i = 0; i < K[n]; i++) {
		c += search(send[n][i]);
		c = c % MOD;
	}

	DP[n] = c;
	return c;
}

int main() {

	scanf("%d %d ", &N, &L);
	for (int i = 1; i <= L; i++) {
		scanf("%d ", &K[i]);
		for (int j = 0; j < K[i]; j++) {
			scanf("%d ", &send[i][j]);
		}
		DP[i] = -1;
	}
	counter = 0;
	counter = search(1);
	printf("%Ld %d\n", counter, (int)s.size());
	return 0;
}