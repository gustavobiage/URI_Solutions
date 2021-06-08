#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LLF long double
#define STEP 0.000000001
#define EPSILON 0.000001

int arr[100009];
int N, A;
int max_;

int equal(LLF a, LLF b) {
	return abs(a - b) < EPSILON;
}

LLF binary_search(LLF begin, LLF end) {
	
	if (begin > end) {
		return end + (begin - end) / 2;
	}

	LLF mid = begin + (end - begin) / 2;
	LLF sum = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i]  > mid) {
			sum += arr[i] - mid;
		}
	}

	if (equal(sum, A)) {
		return mid;
	} else if (sum > A) {
		return binary_search(mid + STEP, end);
	} else {
		return binary_search(begin, mid - STEP);
	}
}

int main() {
	while (1) {
		scanf("%d %d ", &N, &A);
		if (!N && !A) {
			break;
		}
		max_ = 0;
		long int sum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
			max_= fmax(max_, arr[i]);
			sum += arr[i];
		}
		LLF ans = binary_search(0, max_);
		if (sum == A){
			printf(":D\n");
		} else if (sum < A) {
			printf("-.-\n");
		} else {
			printf("%0.4Lf\n", ans);
		}
	}
	return 0;
}