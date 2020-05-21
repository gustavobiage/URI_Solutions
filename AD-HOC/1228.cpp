#include <stdlib.h>
#include <stdio.h>

int N;
int orig[25];
int final[25];
int seen[25];

void swap(int * a, int * b) {
	int k = *a;
	*a = *b;
	*b = k;
}

int main() {

	while (scanf("%d ", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d ", &orig[i]);
			seen[i+1] = 0;
		}
		
		for (int i = 0; i < N; i++) {
			scanf("%d ", &final[i]);
		}

		int c = 0;
		int d;
		int j;
		for (int i = 0; i < N; i++) {
			d = final[i];
			for (j = 0; orig[j] != d; j++);
			if (i < j) {
				for (int k = j; orig[k] != final[k]; k--) {
					swap(&orig[k-1], &orig[k]);
					c++;
				}
			}
		}
	
		printf("%d\n", c);
	}

	return 0;
}