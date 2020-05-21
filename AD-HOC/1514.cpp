#include <stdlib.h>
#include <stdio.h>


int N, M, v;
int arr[200];
int resp[5];

int main() {
	while (1) {
		scanf("%d %d ", &N, &M);

		if (!N && !M) {
			break;
		}
		for (int i = 0; i < M; i++) {
			arr[i] = 0;
		}
		resp[1] = 1;
		resp[2] = 1;
		resp[3] = 1;
		resp[4] = 1;
		
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < M; j++) {
				scanf("%d ", &v);
				arr[j] += v;
				cnt += v;
			}
			if (cnt == M) {
				resp[1] = 0;
			} else if (cnt == 0) {
				resp[4] = 0;
			}
		}

		for (int i = 0; i < M; i++) {
			if (arr[i] == 0) {
				resp[2] = 0;
			} else if (arr[i] == N) {
				resp[3] = 0;
			}
		}

		printf("%d\n", resp[1] + resp[2] + resp[3] + resp[4]);
	}
	return 0 ;
}