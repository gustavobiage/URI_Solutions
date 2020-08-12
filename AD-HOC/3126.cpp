#include <stdlib.h>
#include <stdio.h>

int c, cnt;
int v;

int main() {
	scanf("%d ", &c);
	cnt = 0;
	for (int i = 0; i < c; i++) {
		scanf("%d ", &v);
		cnt += v;
	}
	printf("%d\n", cnt);
	return 0;
}