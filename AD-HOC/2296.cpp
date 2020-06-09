#include <stdlib.h>
#include <stdio.h>

#define INF 100000

int N, M;
int min, ans;
int forward, backward;
int last, v;
int index;
int main() {
	scanf("%d ", &N);
	ans = INF;
	for (int i = 0; i < N; i++) {
		scanf("%d ", &M);
		forward = backward = 0;
		scanf("%d ", &last);
		for (int j = 0; j < M-1; j++) {
			scanf("%d ", &v);
			if (v > last) {
				forward += v - last;
			} else {
				backward += last - v;
			}
			last = v;
		}
		if (forward > backward) {
			min = backward;
		} else {
			min = forward;
		}

		if (ans > min) {
			ans = min;
			index = i+1;
		}
	}

	printf("%d\n", index);
	return 0;
}