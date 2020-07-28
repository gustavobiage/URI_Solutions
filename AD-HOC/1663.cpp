#include <stdlib.h>
#include <stdio.h>

int N;
int arr[100009];
int ans;

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		ans = 1;
		for (int i = 1; i <= N; i++) {
			scanf("%d ", &arr[i]);
			if (arr[i] < i) {
				ans = ans && arr[arr[i]] == i;
			}
		}
		if (ans) {
			printf("ambiguous\n");
		} else {
			printf("not ambiguous\n");
		}
	}
	return 0;
}