#include <stdlib.h>
#include <stdio.h>

int N, V;
int pos;
int main() {

	while (1) {
		scanf("%d %d ", &N, &V);
		if (!N && !V) {
			break;
		}
		int res = 0;
		while (V > 0) {
			int v = V;
			pos = 0;
			while (pos < N && v > 0) {
				if ((N-pos) % v == 0 && ((N-pos) / v <= v)) {
					res = 1;
					goto END;
				} else {
					pos += v*v;
					v--;
				}
			}
			V--;
		}

		END:
		if (res) {
			printf("possivel\n");
		} else {
			printf("impossivel\n");
		}
	}
	return 0;
}