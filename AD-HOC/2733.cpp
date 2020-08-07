#include <stdlib.h>
#include <stdio.h>

int pointer;
int arr[5];

int N, c, v;

int contains(int v) {
	for (int i = 0; i < pointer; i++) {
		if (arr[i] == v) {
			return 1;
		}
	}
	return 0;
}

int push(int v) {
	if (pointer < 4) {
		pointer++;
	}

	int l = v;
	for (int i = 0; i < pointer; i++) {
		int aux = arr[i];
		arr[i] = l;
		l = aux;
	}

}

int main() {
	while (scanf("%d ", &N) != EOF) {
		pointer = c = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			if (!contains(v)) {
				c++;
				push(v);
			}
		}
		printf("%d\n", c);
	}

	return 0;
}