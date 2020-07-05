#include <stdlib.h>
#include <stdio.h>

#define MOD 1000000007

int T, N, M;
int arr[55][100005];
int pointer, total;

int main() {
	scanf("%d %d %d ", &T, &M, &N);
	pointer = 0;
	for (int i = M; i <= N; i++) {
		arr[pointer][i] = 1;
	}
	T--;
	while (T) {
		for (int i = M; i <= N; i++) {
			arr[pointer+1][i-1] += arr[pointer][i];
			arr[pointer+1][i-1] = arr[pointer+1][i-1] % MOD;
			arr[pointer+1][i+1] += arr[pointer][i];
			arr[pointer+1][i+1] = arr[pointer+1][i+1] % MOD;
		}
		T--;
		pointer++;
	}
	for (int i = M; i <= N; i++) {
		total = (total + arr[pointer][i]) % MOD;
	}
	printf("%d\n", total);

	return 0;
}