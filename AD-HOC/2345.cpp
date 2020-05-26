#include <stdlib.h>
#include <stdio.h>

int arr[4];
int total;

int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

int main() {
	total = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d ", &arr[i]);
		total += arr[i];
	}
	
	int m = 2222222;

	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 4; j++) {
			int v = abs(total - 2*(arr[i] + arr[j]));
			if (v < m) {
				m = v;
			}
		}
	}

	printf("%d\n", m);
	return 0;
}