#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;

int n, k;
int arr[500001];
map<int, int> prev_sum;

long long int findSubarraySum(int sum) {
	prev_sum.clear();
	long long int ans = 0;
	long long int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += arr[i];
		if (cnt == sum) {
			ans++;
		}
		if (prev_sum.find(cnt - sum) != prev_sum.end()) {
			ans += prev_sum[cnt - sum];
		}
		prev_sum[cnt]++;
	}
	return ans;
}

int main() {
	scanf("%d %d ", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &arr[i]);
	}
	printf("%Ld\n", findSubarraySum(k));
	return 0;
}