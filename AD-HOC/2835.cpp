#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

int n;
int arr[100001];
int last, ans;

int main() {
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &arr[i]);
	}
	std::sort(arr, arr + n);
	last = 0;
	ans = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] - last > 8) {
			ans = 0;
			break;
		}
		last = arr[i];
	}
	if (ans) {
		printf("S\n");
	} else {
		printf("N\n");
	}
	return 0;
}