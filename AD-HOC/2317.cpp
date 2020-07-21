#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

char arr[251][251];
int R, C;
int visited[251][251];
int p, o, l;
int to, tl;

void search(int sx, int sy) {
	o = l = 0;
	p = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visited[sx][sy] = 1;
	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		if (arr[x][y] == 'k') {
			o++;
		} else if (arr[x][y] == 'v') {
			l++;
		}
		q.pop();
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				if (dx != 0 && dy != 0) {
					continue;
				}
				if (x+dx > 0 && x+dx <= R && y+dy > 0 && y+dy <= C) {
					if (!visited[x+dx][y+dy] && arr[x+dx][y+dy] != '#') {
						q.push(make_pair(x+dx, y+dy));
						visited[x+dx][y+dy] = 1;
					}
				} else {
					p = 0;
				}
			}
		}
	}
}

int main() {
	scanf("%d %d ", &R, &C);
	for (int i = 1; i <= R; i++) {
		scanf(" %s ", &arr[i][1]);
	}
	to = tl = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!visited[i][j] && arr[i][j] != '#') {
				search(i, j);
				if (p) {
					if (o > l) {
						to += o;
					} else {
						tl += l;
					}
				} else {
					to += o;
					tl += l;
				}
			}
		}
	}
	printf("%d %d\n", to, tl);
	return 0;
}