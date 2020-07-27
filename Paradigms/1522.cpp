#include <stdio.h>
#include <stdio.h>
#include <string.h>

int N;
int arr[3][101];
char visited[101][101][101];

int search(int a, int b, int c) {
	if (visited[a][b][c]) {
		return 0;
	}
	if (a == N && b == N && c == N) {
		return 1;
	}
	
	if (a != N && arr[0][a] % 3 == 0) {
		if (search(a+1, b, c)) 
			return 1;
	}
	if (b != N && arr[1][b] % 3 == 0) {
		if (search(a, b+1, c)) 
			return 1;
	}
	if (c != N && arr[2][c] % 3 == 0) {
		if (search(a, b, c+1)) 
			return 1;
	}
	if (a != N && b != N && (arr[0][a]+arr[1][b]) % 3 == 0) {
		if (search(a+1, b+1, c)) 
			return 1;
	}
	if (a != N && c != N && (arr[0][a]+arr[2][c]) % 3 == 0) {
		if (search(a+1, b, c+1)) 
			return 1;
	}
	if (b != N && c != N && (arr[1][b]+arr[2][c]) % 3 == 0) {
		if (search(a, b+1, c+1)) 
			return 1;
	}
	if (a != N && b != N && c != N && (arr[0][a]+arr[1][b]+arr[2][c]) % 3 == 0) {
		if (search(a+1, b+1, c+1)) 
			return 1;
	}
	visited[a][b][c] = 1;
	return 0;
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		memset(visited, 0, 101*101*101);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d ", &arr[0][i], &arr[1][i], &arr[2][i]);
		}
		if (search(0, 0, 0)) {
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}