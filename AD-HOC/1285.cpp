#include <stdlib.h>
#include <stdio.h>

int N, M;

int main() {
	int count;
	int v, digito;
	int last[4], index;
	int should_count;
	while (scanf("%d %d ", &N, &M) != EOF) {

		count = 0;
		for (int i = N; i <= M; i++) {
			v = i;
			index = 0;
			should_count = 1;
			while (v != 0) {
				digito = v % 10;
				v = v / 10;
				last[index] = digito;
				for (int j = 0; j < index; j++) {
					if (last[index] == last[j]) {
						should_count = 0;
					}
				}
				index++;
			}
			if (should_count) {
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}