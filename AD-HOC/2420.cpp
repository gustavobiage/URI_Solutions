#include <stdlib.h>
#include <stdio.h>

int n;
int arr[100001], total;
int sum, ans;

int main() {
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &arr[i]);
		total += arr[i];
	}
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == total - sum) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans+1);
	return 0;
}