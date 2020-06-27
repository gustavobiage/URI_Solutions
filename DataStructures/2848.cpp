#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

priority_queue<int> pq;
map<int, int> byte[1001];
int arr[1001];
int sorted;
int pointer;
int N, Q;
int v;
int L, R, K, G, D;

void clear_queue(priority_queue<int> * p) {
	priority_queue<int> empty;
	empty.swap(*p);
}

void update(int index, int val) {
	while (index <= N) {
		byte[index][val]++;
		index+=index&-index;
	}
}

int get(int index, int val) {
	int cnt = 0;
	while (index) {
		cnt += byte[index][val];
		index-=index&-index;
	}
	return cnt;
}

int getK(int L, int R, int K) {
	clear_queue(&pq);
	L--;
	R--;
	for (int i = L; i <= R; i++) {
		pq.push(-arr[i]);
	}
	int r;
	for (int i = 0; i < K; i++) {
		r = -pq.top();
		pq.pop();
	}
	return r;
}

int main() {
	scanf("%d %d ", &N, &Q);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &v);
		arr[i] = v;
		update(i+1, v);
	}

	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d %d %d ", &L, &R, &K, &G, &D);
		sorted = getK(L, R, K);

		v = get(R, sorted) - get(L-1, sorted);
		if (abs(G - v) == abs(D - v)) {
			printf("%d %d E\n", sorted, v);
		} else if (abs(G - v) < abs(D - v)) {
			printf("%d %d G\n", sorted, v);
		} else if (abs(G - v) > abs(D - v)) {
			printf("%d %d D\n", sorted, v);
		}
	}

	return 0;
}