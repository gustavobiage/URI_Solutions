#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int M, N;
int L , K;
int arr[100009];
int proportion;

int search(int length, int amount) {
	int pa = 0;
	int pb = K-1;
	int c = 0;
	while (amount > 0 && pb >= 0 && pa <= K-1 && pa <= pb) {
		// Use only one
		if (arr[pb] == length) {
			c++;
			pb--;
			amount--;
			continue;
		}

		int v = arr[pa] + arr[pb];
		// Use both
		if (v > length) {
			pb--;
		} else if (v < length) {
			pa++;
		} else {
			if (pa != pb) {
				c += 2;
				amount--;
			}
			pa++;
			pb--;
		}
	}

	if (amount > 0) {
		return -1;
	}
	return c;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int cmp(const void * a, const void * b) {
	int v1 = *((int *) a);
	int v2 = *((int *) b);
	return v1 - v2;
}

int main() {

	while (1) {

		scanf("%d %d ", &N, &M);
		if (!N && !M) {
			break;
		}

		scanf("%d ", &L);
		scanf("%d ", &K);

		for (int i = 0; i < K; i++) {
			scanf("%d ", &arr[i]);
		}

		qsort(arr, K, sizeof(int), cmp);

		int v1, v2;
		if ((N*100)%L==0) {
			proportion = N*100 / L;
			v1 = search(M, proportion);
        } else {
        	v1 = -1;
        }

        if ((M*100)%L==0) {
			proportion = M*100 / L;
			v2 = search(N, proportion);
        } else {
        	v2 = -1;
        }
		
		if (v1 == -1 && v2 == -1) {
			printf("impossivel\n");
		} else if (v1 == -1) {
			printf("%d\n", v2);
		} else if (v2 == -1) {
			printf("%d\n", v1);
		} else {
			printf("%d\n", min(v1, v2));
		}
	}
	return 0;
}