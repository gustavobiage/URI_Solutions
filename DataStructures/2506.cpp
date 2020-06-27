#include <stdlib.h>
#include <stdio.h>

int N;
int H[30], M[30], C[30];
int last, pointer;
int c;

int getNext(int h, int m, int last) {
	if (h*60 + m <= last) {
		return last + 30;
	} else if (m > 30) {
		return (h+1)*60;
	} else if (m < 30 && m > 0) {
		return h*60 + 30;
	}
	return h*60 + m;
}

int main() {
	while (scanf("%d ", &N) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d ", &H[i], &M[i], &C[i]);
		}
		last = 0;
		pointer = 0;
		c = 0;
		while (pointer < N) {
			last = getNext(H[pointer], M[pointer], last);
			if (last > H[pointer]*60 + M[pointer] + C[pointer]) {
				c++;
			}
			pointer++;
		}
		printf("%d\n", c);
	}
	return 0;
}