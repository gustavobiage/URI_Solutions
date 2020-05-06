#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

int A, B, C;
int D, E;
set<int> s;

int cmp(int a, int b) {
	if (a >= b){
		return 0;
	}
	return 1;
}


int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int min(int a, int b, int c) {
	if (min(a, b) < c) {
		return min(a, b);
	}
	return c;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int max(int a, int b, int c) {
	if (max(a, b) > c) {
		return max(a, b);
	}
	return c;
}

int getNext(int c) {
	while (s.find(c) != s.end()) {
		c++;
	}
	if (c > 52) {
		return -1;
	}
	return c;
}

int getFirst() {
	return getNext(1);
}

int main() {
	while (1) {
		scanf("%d %d %d %d %d ", &A, &B, &C, &D, &E);
		if (!A && ! B && ! C && ! D && ! E) {
			break;
		}
		s.clear();
		s.insert(A);
		s.insert(B);
		s.insert(C);
		s.insert(D);
		s.insert(E);

		int c1 = 0;
		int c2 = 0;
		c1 += cmp(A, D);
		c1 += cmp(B, D);
		c1 += cmp(C, D);

		c2 += cmp(A, E);
		c2 += cmp(B, E);
		c2 += cmp(C, E);

		if (c1 == 1 && c2 == 3 ||
			c2 == 1 && c1 == 3) {
			goto T3;
		} else if (c1 == 2 && c2 == 2) {
			goto T2;
		} else if (c1 == 2 && c2 == 3 ||
				c1 == 3 && c2 == 2) {
			goto T2;
		} else if (c1 == 3 && c2 == 3) {
			goto T1;
		} else if (c1 == 0 && c2 == 3 ||
				c1 == 3 && c2 == 0) {
			goto T3;
		} else {
			goto T0;
		}

		if (0) {
			T3:
			printf("%d\n", getNext(max(A, B, C) + 1));
		}

		if (0) {
			T2:
			printf("%d\n", getNext(A + B + C - min(A, B, C) - max(A, B, C) + 1));
		}

		if (0) {
			T1:
			printf("%d\n", getFirst());
		}

		if (0) {
			T0:
			printf("-1\n");
		}
			
	}
	return 0;
}