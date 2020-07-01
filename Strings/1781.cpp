#include <stdlib.h>
#include <stdio.h>

int T, Q;
int cnt;
char S[3000009];
int op, x;
char vqueue[3000009];
char cqueue[3000009];
int vpointer, cpointer;
int vsize, csize;
const char * vogals = "aeiou";

int isVogal(char c) {
	for (int i = 0; vogals[i] != '\0'; i++) {
		if (c == vogals[i]) {
			return 1;
		}
	}
	return 0;
}

void clear() {
	vpointer = cpointer = 0;
	vsize = csize = 0;
}

void shiftCons(int n) {
	if (csize) {
		cpointer = cpointer - n;
		cpointer = (cpointer + csize*(n/csize + 1)) % csize;
	}
}

void shiftVog(int n) {
	if (vsize) {
		vpointer = vpointer - n;
		vpointer = (vpointer + vsize*(n/vsize + 1)) % vsize;
	}
}

int main() {
	cnt = 0;
	scanf("%d ", &T);
	while (T--) {
		cnt++;
		clear();
		scanf("%s ", S);
		for (int i = 0; S[i] != '\0'; i++) {
			if (isVogal(S[i])) {
				vqueue[vsize++] = S[i];
			} else {
				cqueue[csize++] = S[i];
			}
		}
		printf("Caso #%d:\n", cnt);
		scanf("%d ", &Q);
		for (int j = 0; j < Q; j++) {
			scanf("%d ", &op);
			if (op == 0) {
				scanf("%d ", &x);
				shiftVog(x);
			} else if (op == 1) {
				scanf("%d ", &x);
				shiftCons(x);
			} else {
				int v = vpointer;
				int c = cpointer;
				for (int i = 0; S[i] != '\0'; i++) {
					if (isVogal(S[i])) {
						printf("%c", vqueue[v]);
						v = (v+1) % vsize;
					} else {
						printf("%c", cqueue[c]);
						c = (c+1) % csize;
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}