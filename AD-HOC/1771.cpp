#include <stdlib.h>
#include <stdio.h>

int OK, REC;

int count[6];
int arr[25];

int getRegion(int n) {
	if (n == -1) {
		return 5;
	}

	return (n-1) / 15;
}

int isColOK(int n) {
	int index = n;
	int c[6];
	for (int i = 0; i < 6; i++) {
		c[i] = 0;
	}

	while (index < 25) {
		c[getRegion(arr[index])]++;
		index += 5;
	}

	for (int i = 0; i < 5; i++) {
		if (c[i] == 5 || c[i] == 4 && c[5] == 1) {
			return 1;
		}
	}
	return 0;
}

int isLinOK(int n) {
	int index = n*5;
	int c[6];
	for (int i = 0; i < 6; i++) {
		c[i] = 0;
	}
	
	while (index < (n+1)*5) {
		c[getRegion(arr[index])]++;
		index++;
	}

	for (int i = 0; i < 5; i++) {
		if (!(c[i] == 1 || c[i] == 0 && c[5] == 1)) {
			return 0;
		}
	}
	return 1;
}

int isDiagonalOK(int n) {
	int index;
	int delta;
	if (n) {
		index = 0;
		delta = 6;
	} else {
		index = 4;
		delta = 4;
	}

	int c[6];
	for (int i = 0; i < 6; i++) {
		c[i] = 0;
	}
	
	while (index < 24) {
		c[getRegion(arr[index])]++;
		index += delta;
	}

	for (int i = 0; i < 5; i++) {
		if (c[i] == 1 || c[i] == 0 && c[5] == 1) {

		} else {
			return 0;
		}
	}
	return 1;
}

int main() {
	while (scanf("%d ", &arr[0]) != EOF) {
		for (int i = 0; i <= 5; i++) {
			count[i] = 0;
		}
		
		OK = REC = 1;

		count[getRegion(arr[0])]++;
		for (int i = 1; i < 25; i++) {
			if (i == 12) {
				arr[i] = -1;
				count[5]++;
				continue;
			}
			scanf("%d ", &arr[i]);
			count[getRegion(arr[i])]++;
		}

		for (int i = 0; i < 5; i++) {
			if (!isColOK(i)) {
				OK = 0;
			}
			if (!isLinOK(i)) {
				OK = 0;
			}
		}
		
		if (!isDiagonalOK(0)) {
			OK = 0;
		}

		if (!isDiagonalOK(1)) {
			OK = 0;
		}

		if (OK) {
			printf("OK\n");
		} else {
			for (int i = 0; i < 5; i++) {
				if (count[i] != 5 && (i != 2 || count[i] != 4 || count[5] != 1)) {
					REC = 0;
				}
			}

			if (REC) {
				printf("RECICLAVEL\n");
			} else {
				printf("DESCARTAVEL\n");
			}
		}
	}
	return 0;
}