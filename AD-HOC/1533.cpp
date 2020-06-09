#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;

int N, V;
int arr[1001];
map<int, int> index;

int cmp(const void * a, const void * b) {
	int v1 = *((int*)a);
	int v2 = *((int*)b);
	return v2 - v1;
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		index.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
			index[arr[i]] = i+1;
		}
		qsort(arr, N, sizeof(int), cmp);
		printf("%d\n", index[arr[1]]);
	}
	return 0;
}