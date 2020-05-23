#include <stdlib.h>
#include <stdio.h>

int index;
int m, rod, v;
int J, R;
int sum[5000];

int main() {

	scanf("%d %d ", &J, &R);
	for (int i = 0; i < J; i++) {
		sum[i] = 0;
	}
	rod = 0;
	m = 0;
	for (int i = 0; i < R*J; i++) {
		scanf("%d ", &v);
		sum[rod] += v;
		if (sum[rod] > m || sum[rod] == m && rod > index) {
			index = rod;
			m = sum[rod];
		}
		rod = (rod + 1) % J;
	}

	printf("%d\n", index + 1);

	return 0;
}