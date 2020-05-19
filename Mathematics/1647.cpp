#include <stdlib.h>
#include <stdio.h>

#define LLU long long unsigned

LLU sum;
LLU total;
int N;
int arr[100];

int main() {

	while (1) {

		scanf("%d ", &N);
		if (!N) {
			break;
		}
		
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}
		
		total = 0;
		sum = 0;
		for (int i = N-1; i >= 0; i--) {
			sum = sum + (sum + arr[i]);
			total += (sum + arr[i]);
		}
		printf("%Lu\n", total/2);
	}
	return 0;
}