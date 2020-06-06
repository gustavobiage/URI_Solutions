#include <stdlib.h>
#include <stdio.h>

char res[100];
char arr[101][101];
int count[26];
int K, N;
int sum;

int main() {

	scanf("%d ", &K);
	scanf(" %s ", res);
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %s ", arr[i]);
	}
	sum = 0;
	for (int i = 0; i < K; i++) {
		int max = 0;
		for (int j = 0; j < 26; j++) {
			count[j] = 0;
		}
		for (int j = 0; j < N; j++) {
			count[arr[j][i] - 'A']++;
		}
		for (int j = 0; j < 26; j++) {
			if (count[j] > max && j != res[i] - 'A') {
				max = count[j];
			}
		}
		sum += max;
	}
	printf("%d\n", sum);
	return 0;
}