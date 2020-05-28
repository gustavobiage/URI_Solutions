#include <stdlib.h>
#include <stdio.h>

struct t {
	int A, D, H;
};
int N, A, D, H;
struct t arr[100];

int search(int begin, int A, int D, int H, int c) {
	if (!A && !D && !H && c > 1) {
		return 1;
	}

	for (int i = begin; i < N; i++) {
		if (arr[i].A <= A && arr[i].D <= D && arr[i].H <= H) {
			if (search(i+1, A - arr[i].A, D - arr[i].D, H - arr[i].H, c+1)) {
				return 1;
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d %d %d %d ", &N, &A, &D, &H);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d ", &arr[i].A, &arr[i].D, &arr[i].H);
	}
	if (search(0, A, D, H, 0)) {
		printf("Y\n");
	} else {
		printf("N\n");
	}
	return 0;
}