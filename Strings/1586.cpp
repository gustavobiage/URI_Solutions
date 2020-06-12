#include <stdlib.h>
#include <stdio.h>

int arr[100001];
char name[100001][20];
int N, index;

int binary_search(int begin, int end) {
	if (begin > end) {
		return -1;
	}
	int mid = begin + (end - begin) / 2;
	long long int v1 = 0;
	long long int v2 = 0;
	for (int i = mid; i >= 0; i--) {
		v1 += arr[i]*(mid-i+1);
	}
	for (int j = mid+1; j < N; j++) {
		v2 += arr[j]*(j-mid);
	}
	if (v1 > v2) {
		return binary_search(begin, mid-1);
	} else if (v2 > v1) {
		return binary_search(mid+1, end);
	} else {
		return mid;
	}
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		for (int i = 0; i < N; i++) {
			scanf("%s ", name[i]);
			arr[i] = 0;
			for (int j = 0; name[i][j] != '\0'; j++) {
				arr[i] += (int) name[i][j];
			}
		}
		index = binary_search(0, N-1);
		if (index != -1) {
			printf("%s\n", name[index]);
		} else {
			printf("Impossibilidade de empate.\n");
		}
	}
	return 0;
}