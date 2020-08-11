#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int arr[500][500];
int max_;
int m, n;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

void search(int x, int y, int c) {
	max_ = max(max_, c);
	//diagonal direita superio
	if (y < m-2 && x < n-2) {
		if (arr[x+1][y+1] == 2 && arr[x+2][y+2] == 0) {
			arr[x+1][y+1] = 0;
			search(x+2, y+2, c+1);
			arr[x+1][y+1] = 2;
		}
	}
	//diagonal esquerda superio
	if (y > 1 && x < n-2) {
		if (arr[x+1][y-1] == 2 && arr[x+2][y-2] == 0) {
			arr[x+1][y-1] = 0;
			search(x+2, y-2, c+1);
			arr[x+1][y-1] = 2;
		}
	}
	//diagonal direita inferior
	if (x > 1 && y < m-2) {
		if (arr[x-1][y+1] == 2 && arr[x-2][y+2] == 0) {
			arr[x-1][y+1] = 0;
			search(x-2, y+2, c+1);
			arr[x-1][y+1] = 2;
		}
	}
	//diagonal esquerda inferior
	if (x > 1 && y > 1) {
		if (arr[x-1][y-1] == 2 && arr[x-2][y-2] == 0) {
			arr[x-1][y-1] = 0;
			search(x-2, y-2, c+1);
			arr[x-1][y-1] = 2;
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d ", &n, &m);
		if (!n && !m) {
			break;
		}
		memset(arr, 0, sizeof(int)*500*500);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (m+1)/2 - (i%2)*(m%2); j++) {
				scanf("%d ", &arr[i][j*2+i%2]);
			}
		}
		max_= 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					arr[i][j] = 0;
					search(i, j, 0);
					arr[i][j] = 1;
				}
			}
		}
		printf("%d\n", max_);
	}
	return 0;
}