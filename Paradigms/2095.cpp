#include <stdlib.h>
#include <stdio.h>

int S;
int enemy[100001];
int ally[100001];
int cnt;

int cmp(const void * a, const void * b) {
	int v1 = *((int*)a);
	int v2 = *((int*)b);
	return v1-v2;
}

int main() {
	scanf("%d ", &S);
	for (int i = 0; i < S; i++) {
		scanf("%d ", &enemy[i]);
	}
	for (int i = 0; i < S; i++) {
		scanf("%d ", &ally[i]);
	}
	qsort(enemy, S, sizeof(int), cmp);
	qsort(ally, S, sizeof(int), cmp);
	int p1, p2;
	p1 = p2 = 0;
	cnt = 0;
	while (p1 < S && p2 < S) {
		if (enemy[p1] < ally[p2]) {
			p1++;
			p2++;
			cnt++;
		} else {
			p2++;
		}
	}
	printf("%d\n", cnt);
}