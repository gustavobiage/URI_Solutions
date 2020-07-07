#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <math.h>

using namespace std;

int N;
int arr[100001];
long long int cnt;
int input = 0;
int output = 0;
int fi, fo;

int getNextOutput(int index) {
	while (index < N && arr[index] >= 0) {
		index++;
	}
	return index;
}

int getNextInput(int index) {
	while (index < N && arr[index] <= 0) {
		index++;
	}
	return index;
}

int abs_(int a) {
	if (a > 0) {
		return a;
	}
	return -a;
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		cnt = 0;
		fi = fo = 1;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
			if (arr[i] > 0 && fi) {
				input = i;
				fi = 0;
			} else if (arr[i] < 0 && fo) {
				output = i;
				fo = 0;
			}
		}
		while (input < N && output < N) {
			if (arr[input] == 0) {
				input = getNextInput(input);
				continue;
			} else if (arr[output] == 0) {
				output = getNextOutput(output);
				continue;
			}
			int c = fmin(arr[input], -arr[output]);
			arr[input] -= c;
			arr[output] += c;
			cnt += abs_(input - output) * (long long int) c;
		}
		printf("%Ld\n", cnt);
	}
	return 0;
}