#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <queue>
using namespace std;

int N, M;
char map[100][100];
queue<pair<int, int> > init;

void search(pair<int, int> s) {
	queue<pair<int, int>> q;

	q.push(s);
	pair<int, int> p;

	int deltaX[] = {-1, 0, 0, 1};
	int deltaY[] = {0, -1, 1, 0};
	int first = 1;
	int x, y;
	while (!q.empty()) {
		p = q.front();
		q.pop();

		if (!first && map[p.first][p.second] == 'T') {
			continue;
		} else {
			map[p.first][p.second] = 'T';
		}
		first = 0;

		for (int i = 0; i < 4; i++) {
			x = p.first + deltaX[i];
			y = p.second + deltaY[i];
			if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 'X') {
				continue;
			}
			q.push(make_pair(x, y));
		}
	}
}

int main() {

	while (1) {

		scanf("%d %d ", &N, &M);

		if (!N && !M) {
			break;
		}

		for (int i = 0; i < N; i++) {
			scanf(" %s ", map[i]);
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'T') {
					init.push(make_pair(i, j));
				}
			}
		}
		pair<int, int> p;
		while (!init.empty()) {
			p = init.front();
			init.pop();
			search(p);
		}

		for (int i = 0; i < N; i++) {
			printf("%s\n", map[i]);
		}
		printf("\n");
	}
	return 0;
}