#include <stdlib.h>
#include <stdio.h>

int m, last, size, m_size;
int T, N;
int arr[10000];

int main() {
	scanf("%d ", &T);

	for (int t = 1; t <= T; t++) {

		scanf("%d ", &N);
		m = -1;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
			if (arr[i] > m) {
				m = arr[i];
			}
		}

		m_size = 1;
		size = 0;

		for (int i = 0; i < N; i++) {
			if (arr[i] == m) {
				size++;
			} else {
				size = 0;
			}

			if (size > m_size) {
				m_size = size;
			}
		}

		printf("Caso #%d: %d\n", t, m_size);
	}

}