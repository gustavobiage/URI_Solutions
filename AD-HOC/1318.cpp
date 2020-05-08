#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

int N, M;
int arr[10009];
set<int> res;
int v;

int main() {

	while (1) {
		scanf("%d %d ", &N, &M);

		if (!N && !M) {
			break;
		}
		res.clear();

		for (int i = 1; i <= N; i++) {
			arr[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			scanf("%d ", &v);
			arr[v]++;
			if (arr[v] > 1) {
				res.insert(v);
			}
		}

		printf("%d\n", (int)res.size());
	}
	return 0;
}