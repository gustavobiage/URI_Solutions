#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
char arr[10000];
char a[5];
int pos, c;

void reset() {
	pos = 4;
	strcpy(arr, "FACE");
}

int main() {
	scanf("%d ", &N);
	reset();
	c = 0;
	for (int i = 0; i < N; i++) {
		scanf("%c %c %c %c ", &a[0], &a[1], &a[2], &a[3]);
		int correct = 1;
		for (int i = 0; i < 4; i++) {
			if (a[i] != arr[pos-i-1]) {
				correct = 0;
				break;
			}
		}
		if (correct) {
			c++;
			pos -= 4;
			if (!pos) {
				reset();
			}
		} else {
			for (int i = 0; i < 4; i++) {
				arr[pos++] = a[i];
			}
		}
	}
	printf("%d\n", c);
	return 0;
}