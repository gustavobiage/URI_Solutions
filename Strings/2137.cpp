#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1001];
int N;

int main() {
	while (scanf("%d ", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}
		sort(arr, arr + N);
		for (int i = 0; i < N; i++) {
			printf("%.4d\n", arr[i]);
		}
	}
	return 0;
}