#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int C, T;
int arr[100001];
int X, Y;

int cmp(const void * a, const void * b) {
	int v1 = *((int *) a);
	int v2 = *((int *) b);
	return v1 - v2;
}

long long int dist(long long int a, long long int b) {
	return a*a + b*b;
}

int binary_search_far_left(int begin, int end, long long int value, int * var) {
	if (begin > end) {
		return 0;
	}

	int mid = begin + (end - begin) / 2;
	long long int v = (long long int) arr[mid] * arr[mid];
	
	if (v < value) {
		if (mid > *var) {
			*var = mid;
		}
		return binary_search_far_left(mid+1, end, value, var);
	} else if (v > value) {
		return binary_search_far_left(begin, mid-1, value, var);
	} else if (v == value) {
		*var = mid;
		return 1;
	}
	return 0;
}

int main() {

	scanf("%d %d ", &C, &T);
	for (int i = 0; i < C; i++) {
		scanf("%d ", &arr[i]);
	}

	qsort(arr, C, sizeof(int), cmp);
	int index = -1;
	long long int c = 0;
	for (int i = 0; i < T; i++) {
		scanf("%d %d ", &X, &Y);
		index = -1;
		if (binary_search_far_left(0, C-1, dist(X, Y), &index)) {
			index--;
		}
		c += C - (index + 1);
	}

	printf("%Lu\n", c);
	return 0;
}