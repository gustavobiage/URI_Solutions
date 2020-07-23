#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int sx, sy;
char arr[501][501];

void search() {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == N-1) {
			continue;
		}
		if (arr[x+1][y] == '#') {
			if (arr[x][y-1] != 'o') {
				arr[x][y-1] = 'o';
				q.push(make_pair(x, y-1));
			}
			if (arr[x][y+1] != 'o') {
				arr[x][y+1] = 'o';
				q.push(make_pair(x, y+1));
			}
		} else {
			if (arr[x+1][y] != 'o') {
				arr[x+1][y] = 'o';
				q.push(make_pair(x+1, y));
			}
		}
	}
}

int main() {
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c ", &arr[i][j]);
			if (arr[i][j] == 'o') {
				sx = i;
				sy = j;
			}
		}
	}
	search();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}