#include <stdlib.h>
#include <stdio.h>

int T;
int QT, S;
int v;
int index, min;

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d ", &QT, &S);
		min = 1000000;
		index = -1;
		for (int i = 1; i <= QT; i++) {
			scanf("%d ", &v);
			v = abs(S-v);
			if (v < min) {
				index = i;
				min = v;
			}
		}
		printf("%d\n", index);
	}
	return 0;
}