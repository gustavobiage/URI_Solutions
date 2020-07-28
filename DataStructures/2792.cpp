#include <stdio.h>
#include <stdio.h>

int N;
int byte[500009];
int v, amnt;
int stack[500009];
int pointer;

void update(int x) {
	for (; x <= N; x+=x&-x) {
		byte[x]++;
	}
}

int get(int x) {
	int ans = 0;
	for (; x; x-=x&-x) {
		ans += byte[x];
	}
	return ans;
}

int main() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &v);
		amnt = get(v);
		stack[pointer++] = v-amnt;
		update(v);
	}
	for (int i = 0; i < N; i++) {
		if (!i) {
			printf("%d", stack[i]);
		} else {
			printf(" %d", stack[i]);
		}
	}
	printf("\n");
	return 0;
}