#include <stdlib.h>
#include <stdio.h>
#include  <set>
#include <utility>
#include <math.h>

#define INF 2222222

using namespace std;

int arr[1001];
int B = INF;
int E = -1;
int N, I, F;
set<pair<int, int> > s;

int binary_search1(int begin, int end, int value) {
	if (begin > end) {
		return -1;
	}

	int mid = begin + (end - begin)/2;
	int v = arr[mid];

	if (v >= value) {
		B = fmin(B, mid);
		return binary_search1(begin, mid-1, value);
	} else if (v < value) {
		return binary_search1(mid + 1, end, value);
	}
	return -1;
}

int cmp(const void * a, const  void * b) {
	int i = *((int *) a);
	int j = *((int *) b);
	return  i - j;
}

int binary_search2(int begin, int end, int value) {
	if (begin > end) {
		return -1;
	}

	int mid = begin + (end - begin)/2;
	int v = arr[mid];

	if (v > value) {
		return binary_search2(begin, mid-1, value);
	} else if (v <= value) {
		E = fmax(begin, mid);
		return binary_search2(mid + 1, end, value);
	}
	return mid;
}

int main() {

	scanf("%d %d %d ", &N, &I, &F);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
	}

	qsort(arr, N, sizeof(int), cmp);

	for (int i = 0; i < N; i++) {
		B = INF;
		E = -1;
		binary_search1(0, N-1, I-arr[i]);
		binary_search2(0, N-1, F-arr[i]);
		for (int j = B; j <= E; j++) {
			if (i == j) {
				continue;
			}
			s.insert(make_pair(fmin(arr[i], arr[j]), fmax(arr[i], arr[j])));
		}
	}

	printf("%d\n", (int) s.size());

	return 0;
}