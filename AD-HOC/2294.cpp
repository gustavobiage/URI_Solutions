#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int arr[15][15];
int dist[15][15];

queue<pair<int, int> > out;

void search(int sx, int sy) {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dist[i][j] = -1;
		}
	}

	int x, y;
	int D;
	queue<pair<int, int>> q;
	queue<int> d;

	pair<int, int> p;

	dist[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	d.push(0);

	while (!q.empty()) {
		p = q.front();
		q.pop();

		x = p.first;
		y = p.second;
		// printf("(x, y) = (%d, %d)\n", x, y);
		D = d.front();
		d.pop();
		dist[x][y] = D;

		if (x-1 >= 0 && dist[x-1][y] == -1 &&
		 (arr[x-1][y] == 1 || arr[x-1][y] == 0)) {
			q.push(make_pair(x-1, y));
			d.push(D+1);
		}

		if (y-1 >= 0 && dist[x][y-1] == -1 &&
		 (arr[x][y-1] == 1 || arr[x][y-1] == 0)) {
			q.push(make_pair(x, y-1));
			d.push(D+1);
		}

		if (x+1 < N && dist[x+1][y] == -1 &&
			(arr[x+1][y] == 1 || arr[x+1][y] == 0)) {
			q.push(make_pair(x+1, y));
			d.push(D+1);
		}

		if (y+1 < M && dist[x][y+1] == -1 &&
			(arr[x][y+1] == 1 || arr[x][y+1] == 0)) {
			q.push(make_pair(x, y+1));
			d.push(D+1);
		}
	}
}

int main() {
	int sx, sy;

	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d ", &arr[i][j]);
			if (arr[i][j] == 3) {
				sx = i;
				sy = j;
			} else if (arr[i][j] == 0) {
				out.push(make_pair(i, j));
			}
		}
	}

	search(sx, sy);

	int min = 500000;
	while (!out.empty()) {
		sx = out.front().first;
		sy = out.front().second;
		out.pop();
		if (dist[sx][sy] != -1 && dist[sx][sy] < min) {
			min = dist[sx][sy];
		}
	}

	printf("%d\n", min);
	return 0;
}