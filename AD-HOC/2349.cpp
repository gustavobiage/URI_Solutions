#include <stdlib.h>
#include <stdio.h>

int N, C, S;
int position, cnt;
int op;

int main() {
	scanf("%d %d %d ", &N, &C, &S);
	position = 1;
	cnt = position == S;
	for (int i = 0; i < C; i++) {
		scanf("%d ", &op);
		if (op > 0) {
			position = position % N + 1;
		} else {
			position = (position-2+N) % N + 1; 
		}
		if (position == S) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}