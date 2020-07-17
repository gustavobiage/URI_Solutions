#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int T;
char numbers[200009];
int n;
int cnt[19];
int m, v;

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%s ", numbers);
		n = strlen(numbers);
		m = 11;
		for (int i = 0; i < 10; i++) {
			cnt[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			v = numbers[i] - '0';
			cnt[v]++;
			if (v && v < m) {
				m = v;
			}
		}
		if (m < 10) {
			printf("%d", m);
			cnt[m]--;
			for (int i = 0; i < 10; i++) {
				while (cnt[i]--) {
					printf("%d", i);
				}
			}
			printf("\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}