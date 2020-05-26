#include <stdlib.h>
#include <stdio.h>

int P, C, N;
int arr[2000][2000];

int search() {
	int c;
	int res = 0;
	for (int i = 0; i < P; i++) {
		c = 0;
		for (int j = 0; j < N; j++) {
			if (arr[j][i]) {
				c++;
			} else {
				if (c >= C) {
					res++;
				} 
				c = 0;
			}
		}
		if (c >= C) {
			res++;
		}
	}
	return res;
}

int main() {

	while (1) {

		scanf("%d %d %d ", &P, &N, &C);
		if (!P && !N && !C) {
			break;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < P; j++) {
				scanf("%d ", &arr[i][j]);
			}
		}

		printf("%d\n", search());
	}
	return 0;
}