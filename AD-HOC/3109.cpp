#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

map<int, int> m;

int N, Q, E;
int a, b;
int arr[1001];
int ia, ib, c;
int pointer;

int main() {
	scanf("%d ", &N);
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
		m[i] = i;
	}
	scanf("%d ", &Q);
	for (int i = 0; i< Q; i++) {
		scanf("%d ", &E);
		if (E == 1) {
			scanf("%d %d ", &a, &b);
			ia = m[a];
			ib = m[b];
			m[b] = ia;
			m[a] = ib;
			arr[ia] = b;
			arr[ib] = a;
		} else {
			scanf("%d ", &a);
			c = 0;
			pointer = a;
			while (arr[pointer] != a) {
				c++;
				pointer = arr[pointer];
			}
			printf("%d\n", c);
		}
	}

	return 0;
}