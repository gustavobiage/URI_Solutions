#include <stdlib.h>
#include <stdio.h>

int T, N;
long long unsigned int DP[35];
int pointer = 0;

void update(int until) {
	for (int i = pointer + 1; i <= until; i++) {
		DP[i] = DP[i-1] * 2;
	}
	pointer = until;
}

int main() {
	
	DP[0] = 1;

	scanf("%d ", &T);
	while (T) {
		scanf("%d ", &N);
		if (N > pointer) {
			update(N);
		}

		printf("%Lu\n", DP[N]-1);

		T--;
	}

	return 0;
}