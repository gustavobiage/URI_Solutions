#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int N;
int arr[5002], dist[5002];
int counting, first, first_value;

int getValue(int i) {

}

int main() {

	while (1) {

		scanf("%d ", &N);

		if (N == 0) {
			break;
		}


		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}

		first_value = 0;
		counting = 0;
		first = 1;
		for (int i = 0; i < N; i++) {
			if (first && arr[i]) {
				first_value = i;
				first = 0;
			}

			if (arr[i]) {
				dist[i] = counting;
				counting = 0;
			} else {
				counting++;
			}
		}

		dist[first_value] += counting;

		if (first) {
			counting = (counting+1) / 2;
		} else {
			counting = 0;
			for (int i = 0; i < N; i++) {
				if (arr[i]) {
					counting += dist[i] / 2;
				} else {

				}
			}
		}
		
		printf("%d\n", counting);
	}

	return 0;
}