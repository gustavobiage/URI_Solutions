#include <stdlib.h>
#include <stdio.h>

int P;
int arr[200009];
int ans[200009];
int c, pos;

int main() {
	scanf("%d ", &P);
	int begin = 0;
	int end = P/2;
	int i = 0;
	while (i < P) {
		if (i%2 == 0) {
			arr[end] = i;
			end++;
		} else {
			arr[begin] = i;
			begin++;
		}
		i++;
	}
	c = 1;
	pos = 1;
	while (pos != 0 && c <= P) {
		pos = arr[pos];
		c++;
	}

	printf("%d\n", c);
}