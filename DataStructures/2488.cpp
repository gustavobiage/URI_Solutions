#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <utility>
#include <math.h>

using namespace std;

int lastX, lastY;
int X, Y;
int arr[10001];
map<pair<int, int>, int> m;
int N, P;
int pointer;

int dist(int a, int b, int x, int y) {
	return (a-x)*(a-x)+(b-y)*(b-y);
}

int main() {
	scanf("%d %d ", &N, &P);
	pointer = 0;
	for (int i = 0; i < N; i++) {
		 scanf("%d %d ", &X, &Y);
		 m[make_pair(X, Y)] = i;
		 if (i != 0) {
		 	arr[pointer++] = dist(X, Y, lastX, lastY);
		 }
		 lastX = X;
		 lastY = Y;
	}
	int begin, end;
	for (int i = 0; i < P; i++) {
		scanf("%d %d ", &X, &Y);
		begin = m[make_pair(X, Y)];
		scanf("%d %d ", &X, &Y);
		end = m[make_pair(X, Y)];
		if (begin > end) {
			int aux = begin;
			begin = end;
			end = aux;
		}
		int max = 0;
		for (int j = begin; j < end; j++) {
			if (max < arr[j]) {
				max = arr[j];
			}
		}
		printf("%0.2lf\n", sqrt(max));
	}
}