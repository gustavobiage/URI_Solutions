#include <stdlib.h>
#include <stdio.h>

int arr[10][10];
int arr2[10][10];
int N;

int search(int length, int r[10][10], int ds, int s) {
	for (int i = 0; i < length; i++) {
		int f = 1;
		for (int j = s; j >= 0 && j < 4; j += ds) {
			if (r[i][j] != 0) {
				f = 0;
			}

			if (r[i][j] == 0 && !f 
				||
				(j+ds) >= 0 && (j+ds) < 4 && r[i][j] == r[i][j+ds] && r[i][j] != 0) {
				return 1;
			}
		}
	}

	return 0;
}

int prt(const char * c, int * f) {
	if (*f) {
		*f = 0;
		printf("%s", c);
	} else {
		printf(" %s", c);
	}
}

int main() {
	scanf("%d ", &N);
	int f;
	int has2048;
	while (N) {
		f = 1;
		has2048 = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d ", &arr[i][j]);
				arr2[j][i] = arr[i][j];
				if (arr[i][j] == 2048) {
					has2048 = 1;
				}
			}
		}

		if (!has2048) {
			if (search(4, arr2, 1, 0)) {
				prt("DOWN", &f);
			}
			
			if (search(4, arr, -1, 3)) {
				prt("LEFT", &f);
			}
			
			if (search(4, arr, 1, 0)) {
				prt("RIGHT", &f);
			}
			
			if (search(4, arr2, -1, 3)) {
				prt("UP", &f);
			}
		}

		if (f) {
			printf("NONE");
		}

		printf("\n");
		N--;
	}

	return 0;
}