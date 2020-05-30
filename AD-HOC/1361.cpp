#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BLUE 0
#define RED 1

int T, N;
int state, v;
int blueArr[500001];
int redArr[500001];
int blueIndex;
int redIndex;

int cmp(const void * a, const void * b) {
	int v1 = *((int *) a);
	int v2 = *((int *) b);
	return v2 - v1;
}

int search(int state) {
	int c = 0;
	int last = 1000000;
	int bPointer = 0;
	int rPointer = 0;
	while (1) {
		if (state == BLUE) {
			while (blueArr[bPointer] >= last && bPointer < blueIndex) {
				bPointer++;
			}
			
			if (bPointer == blueIndex) {
				break;
			}
			c++;
			last = blueArr[bPointer];
		} else if (state == RED) {
			while (redArr[rPointer] >= last && rPointer < redIndex) {
				rPointer++;
			}
			
			if (rPointer == redIndex) {
				break;
			}
			c++;
			last = redArr[rPointer];
		}

		state = (state + 1) % 2;
	}
	return c;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {

	scanf("%d ", &T);
	while (T) {
		scanf("%d ", &N);
		blueIndex = 0;
		redIndex = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			if (v > 0) {
				blueArr[blueIndex++] = v;
			} else {
				redArr[redIndex++] = -v;
			}
		}

		qsort(blueArr, blueIndex, sizeof(int), cmp);
		qsort(redArr, redIndex, sizeof(int), cmp);

		int v1 = search(RED);
		int v2 = search(BLUE);

		printf("%d\n", max(v1, v2));
		T--;
	}

}