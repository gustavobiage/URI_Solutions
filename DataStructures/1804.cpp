#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int byte[100001];
int arr[100001];
int N, v;
char op;
int i;

void update(int n, int val) {
	while (n <= N) {
		byte[n] += val;
		n+=n&-n;
	}
}

int get(int n) {
	int ans = 0;
	while (n) {
		ans += byte[n];
		n-=n&-n;
	}
	return ans;
}

int main() {
	scanf("%d ", &N);
	memset(byte, 0, sizeof(int)*100001);

	for (int i = 1; i <= N; i++) {
		scanf("%d ", &arr[i]);
		update(i, arr[i]);
	}
	while (scanf("%c %d ", &op, &i) != EOF) {
		if (op == 'a') {
			update(i, -arr[i]);
		} else if (op == '?') {
			printf("%d\n", get(i-1));
		}
	}

	return 0;
}