#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <map>

#define POSITIVE 1
#define NEGATIVE 2

using namespace std;

int N, F;
int arr[50];
int positive[50];
int negative[50];
int res;
map<pair<int, int>, int> computed;

int search(int index, int f) {
	pair<int, int> p = make_pair(index, f);
	if (computed.find(p) != computed.end()) {
		return computed[p];
	}

	if (!f && index == N) {
		res = 1;
		return 1;
	} else if (index == N) {
		return 0;
	}

	int v1, v2;
	v1 = search(index+1, f-arr[index]);
	if (v1) {
		positive[index] = 1;
	}

	v2 = search(index+1, f+arr[index]);
	if (v2) {
		negative[index] = 1;
	}
	computed[p] = v1 || v2;
	return v1 || v2;
}

int main() {

	while (1) {
		scanf("%d %d ", &N, &F);
		if (!N && !F) {
			break;
		}
		computed.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
			positive[i] = negative[i] = 0;
		}
		res = 0;
		search(0, F);
		if (res) {
			for (int i = 0; i < N; i++) {
				if (positive[i] && negative[i]) {
					printf("?");
				} else if (positive[i]) {
					printf("+");
				} else if (negative[i]) {
					printf("-");
				}
			}
			printf("\n");
		} else {
			printf("*\n");
		}
	}
	return 0;
}