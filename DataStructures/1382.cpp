#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <utility>
#include <algorithm>

using namespace std;

int T, N;
int v, pointer, finding;
int c, arr[10001];
pair<int ,int> cons[10001];
int visited[10001];

void solve() {
	for (int i = 0 ; i < N; i++) {
		cons[i].first = arr[i];
		cons[i].second = i;
	}
	sort(cons, cons + N);
	memset(visited, 0, sizeof(int)*10001);

	c = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i] && cons[i].second != i) {
			int amnt = 0;
			int j = i;
			while (!visited[j]) {
				visited[j] = 1;
				j = cons[j].second;
				amnt++;
			}
			c += amnt-1;
		}
	}
}

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}
		solve();
		printf("%d\n", c);
	}
	return 0;
}

//Reference:
//	https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/