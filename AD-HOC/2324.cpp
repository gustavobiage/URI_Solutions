#include <stdlib.h>
#include <stdio.h>

#define ZERO 0
#define ONE 1

int N, P;
int arr[1001];
int v, cmp;
int main() {

	scanf("%d %d ", &P, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &v);
		arr[v]++;
	}
	int cmp = arr[1];
	int status = ZERO;
	int res = 1;
	for (int i = 2; i <= P; i++) {
		if (status) {
			//ONE
			if (arr[i] != cmp-1) {
				res = 0;
				break;
			}
		} else {
			if (arr[i] == cmp - 1) {
				status = ONE;
			} else if (arr[i] != cmp) {
				res = 0;
				break;
			}
		}
	}
	
	if (res) {
		printf("S\n");
	} else {
		printf("N\n");
	}

	return 0;
}