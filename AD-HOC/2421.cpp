#include <stdlib.h>
#include <stdio.h>
#include <utility>

using namespace std;

int WIDTH, HEIGHT;
pair<int, int> B[2], A[2];
int x, y;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {

	scanf("%d %d ", &HEIGHT, &WIDTH);
	scanf("%d %d ", &x, &y);
	A[0] = make_pair(x, y);
	A[1] = make_pair(y, x);
	scanf("%d %d ", &x, &y);
	B[0] = make_pair(x, y);
	B[1] = make_pair(y, x);
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (max(A[i].first, B[j].first) <= WIDTH 
				&& A[i].second + B[j].second <= HEIGHT) {
				printf("S\n");
				return 0;
			}
		}
	}
	int aux = WIDTH;
	WIDTH = HEIGHT;
	HEIGHT = aux;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (max(A[i].first, B[j].first) <= WIDTH 
				&& A[i].second + B[j].second <= HEIGHT) {
				printf("S\n");
				return 0;
			}
		}
	}

	printf("N\n");

	return 0;
}