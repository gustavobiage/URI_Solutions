#include <stdlib.h>
#include <stdio.h>
#include <set>

#define INF 222222

using namespace std;

int A, B;
int arrA[100002];
int arrB[100002];

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int find(int * ar, int le, int * arr, int len) {
	int p1 = 0;
	int p2 = 0;

	int c = 0;
	
	set<int> set1;
	set<int> set2;

	while (p1 < le && p2 < len) {
		if (ar[p1] < arr[p2]) {
			p1++;
		} else if (ar[p1] == arr[p2]) {
			set1.insert(ar[p1]);
			p1++;
			c++;
		} else if (ar[p1] > arr[p2]) {
			p2++;
		}
	}

	for (int i = 0; i < le; i++) {
		if (set1.find(ar[i]) == set1.end()) {
			set2.insert(ar[i]);
		}
	}

	return (int)set2.size();
}

int main() {

	while (1) {
		scanf("%d %d ", &A, &B);
		if (A == 0 && B == 0) {
			break;
		}

		for (int i = 0; i < A; i++) {
			scanf("%d ", &arrA[i]);
		}

		for (int i = 0; i < B; i++) {
			scanf("%d ", &arrB[i]);
		}

		int n = INF;

		n = min(n, find(arrB, B, arrA, A));
		n = min(n, find(arrA, A, arrB, B));
		printf("%d\n", n);
	}

	return 0;
}