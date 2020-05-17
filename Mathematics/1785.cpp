#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int> pq;

int T, N;

int getMaior(int n) {
	int digit;
	int r = 0;
	int c = 0;
	while (n) {
		digit = n % 10;
		n = n / 10;
		pq.push(digit);
		c++;
	}

	for (int i = c; i < 4; i++) {
		pq.push(0);
	}

	int p = 1000;
	while (!pq.empty()) {
		r += pq.top() * p;
		pq.pop();
		p = p / 10;
	}
	return r;
}

int getMenor(int n) {
	int digit;
	int r = 0;
	int c = 0;
	while (n) {
		digit = n % 10;
		n = n / 10;
		pq.push(-digit);
		c++;
	}

	for (int i = c; i < 4; i++) {
		pq.push(0);
	}

	int p = 1000;
	while (!pq.empty()) {
		r += -pq.top() * p;
		pq.pop();
		p = p / 10;
	}
	return r;
}

int krapekar(int X) {
	int cnt = 0;
	int maior, menor;
	while (X != 6174) {
		if (X == 0) {
			return -1;
		}
		maior = getMaior(X);
		menor = getMenor(X);
		X = maior - menor;
		cnt = cnt + 1;
	}
	return cnt;
}

int main() {

	scanf("%d ", &T);
	int c;
	for (int t = 1; t <= T; t++) {
		scanf("%d ", &N);
		printf("Caso #%d: %d\n", t, krapekar(N));
	}
	return 0;
}