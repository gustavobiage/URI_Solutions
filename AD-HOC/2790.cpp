#include <stdlib.h>
#include <stdio.h>

using namespace std;

int N;
int counter[100001][10];
int sum, min, a;

int main() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &a);
		for (int j = 1; j <= 6; j++) {
			if (j == a) {
				continue;
			}
			if (j + a == 7) {
				counter[i][j] += 2;
			} else {
				counter[i][j]++;
			}
		}
	}
	min = 600001;
	for (int i = 1; i <= 6; i++) {
		sum = 0;
		for (int j = 0; j < N; j++) {
			sum += counter[j][i];
		}
		if (min > sum) {
			min = sum;
		}
	}
	printf("%d\n", min);
}