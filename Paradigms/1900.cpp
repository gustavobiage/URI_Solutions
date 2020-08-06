#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <math.h>

using namespace std;

int N;
int arr[100001];
map<long long int, long long int> prev_sum;

int cnt, ans, last;

long long int findSubarraySum(int sum) {
	prev_sum.clear();
	long long int ans = 0;
	long long int cnt = 0;
	for (int i = 0; i < N; i++) {
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
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
	}
	printf("%Ld\n", findSubarraySum(0));
	return 0;
}

// Reference: https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/