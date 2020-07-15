#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

int N;
int arr[202][202];
set<int> s;
int x, y;

int main() {
	scanf("%d ", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}
	for (int i = 0; i < N*2; i++) {
		scanf("%d %d ", &x, &y);
		s.insert(arr[x][y]);
	}
	printf("%d\n", (int) s.size());
	return 0;
}