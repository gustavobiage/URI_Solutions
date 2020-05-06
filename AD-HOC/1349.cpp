#include <stdlib.h>
#include <stdio.h>

#define INF 22222222

int N;
int arr[402][402];
int orig[402][402];
int v, c, m;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int main() {

	while (1) {

		scanf("%d ", &N);
		if (!N) {
			break;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d ", &arr[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d ", &orig[i][j]);
			}
		}


		int sx[] = {0, 0, N-1, N-1};
		int sy[] = {0, N-1, 0, N-1};

		int dx[] = {1, 1, -1, -1};
		int dy[] = {1, -1, 1, -1};

		m = INF;
		int index;
		for (int k = 0; k < 4; k++) {
			index = 0;
			c = 0;
			for (int i = sx[k]; i >= 0 && i < N; i = i + dx[k]) {
				for (int j = sy[k]; j >= 0 && j < N; j = j + dy[k]) {
					if (abs(arr[index / N][index % N] - orig[i][j]) > 100) {
						c++;
					}
					index++;
				}
			}
			m = min(c, m);
		}

		for (int k = 0; k < 4; k++) {
			index = 0;
			c = 0;
			for (int j = sy[k]; j >= 0 && j < N; j = j + dy[k]) {
				for (int i = sx[k]; i >= 0 && i < N; i = i + dx[k]) {
					if (abs(arr[index / N][index % N] - orig[i][j]) > 100) {
						c++;
					}
					index++;
				}
			}
			m = min(c, m);
		}

		printf("%0.2lf\n", 100 - 100*((double)m / (N*N)));
	}
	return 0;
}