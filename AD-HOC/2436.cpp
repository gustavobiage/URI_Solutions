#include <stdlib.h>
#include <stdio.h>
#include <utility>

using namespace std;

int M, N;
int X, Y;
int arr[1001][1001];

pair<int, int> search(int x, int y) {
	int d[] = {1, 0, -1};
	arr[x][y] = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((d[i] != 0 && d[j] != 0) ||
			 x+d[i] < 0 || x+d[i] >= M ||
			 y+d[j] < 0 || y+d[j] >= N) {
				continue;
			}
			if (arr[x+d[i]][y+d[j]] == 1) {
				return search(x+d[i], y+d[j]);
			}
		}
	}
	return make_pair(x, y);	
}

int main() {

	scanf("%d %d ", &M, &N);
	scanf("%d %d ", &X, &Y);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}

	pair<int, int> res = search(X-1, Y-1);
	printf("%d %d\n", res.first + 1, res.second + 1);
	return 0;
}