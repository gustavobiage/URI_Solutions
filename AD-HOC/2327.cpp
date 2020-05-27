#include <stdlib.h>
#include <stdio.h>

int N;
int arr[15][15];

int main() {

	scanf("%d ", &N);
	int compare;
	for (int i = 0; i < N; i++) {
		compare = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d ", &arr[i][j]);
			compare += arr[i][j];
		}
	}

	int res = 1;
	//ROWS
	for (int i = 0; i < N; i++) {
		int s = 0;
		for (int j = 0; j < N; j++) {
			s += arr[i][j];
		}
		if (s != compare) {
			res = 0;
		}
	}

	//COLUNMS
	for (int j = 0; j < N; j++) {
		int s = 0;
		for (int i = 0; i < N; i++) {
			s += arr[i][j];
		}
		if (s != compare) {
			res = 0;
		}
	}

	//DIAGONAL RIGHT
	int s = 0;
	for (int i = 0; i < N; i++) {
		s += arr[i][i];
	}
	if (s != compare) {
		res = 0;
	}

	//DIAGONAL LEFT
	s = 0;
	for (int i = 0; i < N; i++) {
		s += arr[N-1-i][i];
	}
	if (s != compare) {
		res = 0;
	}
	
	if (res) {
		printf("%d\n", compare);
	} else {
		printf("-1\n");
	}


	return 0;
}