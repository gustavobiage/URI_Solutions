#include <stdlib.h>
#include <stdio.h>

#define INF 222222222

int N, F, C[100002];
int counter, v;

int res;
int mid, sum;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int binary_search(int begin, int end) {
	if (end < begin) {
		return 0;
	}

	mid = begin + (end - begin) / 2;
	sum = 0;
	for (int i = 0; i < N; i++) {
		sum +=  mid / C[i];
	}

	if (sum < F) {
		return binary_search(mid+1, end);
	} else if (sum >= F) {
		res = min(mid, res);
		return binary_search(begin, mid-1);
	}
}

int main() {

	scanf("%d %d ", &N, &F);
	
	counter = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d ", &C[i]);
	}

	res = INF;
	binary_search(1, INF);

	printf("%d\n", res);


	return 0;
}