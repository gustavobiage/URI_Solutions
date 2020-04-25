#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <stack>

using namespace std;

int N, M;
int L, K;
int arr[100001];

int proportion;
stack<int> used;
map<int, int> count;

int search(int length, int amount) {
	int c = 0;
	int index = 0;
	int value, find;

	if (count.find(length) != count.end()) {
		while (amount > 0 && count[length] > 0) {
			count[length]--;
			amount--;
			c++;
			used.push(length);
		}
	}

	while (amount) {
		if (index == K)
			break;

		value = arr[index];
		if (count[value] > 0) {
			find = length - value;
			if (value != find && count.find(find) != count.end() && count[find] > 0 ||
			 value == find && count.find(find) != count.end() && count[find] > 1) {
				amount--;
				count[value]--;
				count[find]--;
				c += 2;
				used.push(value);
				used.push(find);
			}
		}
		index++;
	}

	while (!used.empty()) {
		value = used.top();
		if (amount == 0) {
			printf("*%d\n", value);
		}
		used.pop();
		count[value]++;
	}

	if (amount > 0) {
		return -1;
	}
	
	return c;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int main() {

	while (1) {

		scanf("%d %d ", &N, &M);
		
		count.clear();

		if (N == 0 && M == 0) {
			break;
		}
		scanf("%d ", &L);
		scanf("%d ", &K);

		for (int i = 0; i < K; i++) {
			scanf("%d ", &arr[i]);
			count[arr[i]]++;
		}
		
		proportion = ceil(N / ((double)L/100));
		printf("%lf -> %d\n", N / ((double)L/100), proportion);

		int v1 = search(M, proportion);
		proportion = ceil(M / ((double)L / 100));
		printf("%lf -> %d\n", M / ((double)L/100), proportion);

		int v2 = search(N, proportion);
		
		if (v1 == -1 && v2 == -1) {
			printf("impossivel\n");
		} else if (v1 == -1) {
			printf("%d\n", v2);
		} else if (v2 == -1) {
			printf("%d\n", v1);
		} else {
			printf("%d\n", min(v1, v2));
		}
	}

	return 0;
}