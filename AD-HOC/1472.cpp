#include <stdlib.h>
#include <stdio.h>

int arr[500000];
int N;
double frac;

int binary_search(int begin, int end, int from) {
	if (begin > end) {
		return -1;
	}

	int mid = begin + (end - begin)/2;

	int v = arr[mid-1] - arr[from-1];
	
	if (v > frac) {
		return binary_search(begin, mid-1, from);
	} else if (v < frac) {
		return binary_search(mid + 1, end, from);
	} else {
		return mid;
	}
}

int main() {
	int c;
	int lenght;
	while (scanf("%d ", &N) != EOF) {
		lenght = 0;
		arr[0] = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d ", &lenght);
			arr[i] = arr[i-1] + lenght;
		}

		frac = (double)arr[N]/3;
		c = 0;

		for (int i = 1; i <= N; i++) {
			int j = binary_search(i+1, N, i);
			if (j != -1) {
				int k = binary_search(j+1, N, j);
				// if (arr[k-1] - arr[j-1] == arr[j-1] - arr[i-1] &&
				// 	arr[k-1] - arr[j-1] == arr[i-1] + arr[N] - arr[k-1]) {
				// 	c++;
				// }
				if (k != -1) {
					c++;
				}
			}
		}

		printf("%d\n", c);
	}
	return 0;
}