#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int count[501];
int A[501], B[501], C[501], D[501];
int X, Y, Z;
int M, N;
int m, v;
char reg[501];
string str;
map<string, int> map_;

int main() {

	scanf("%d %d ", &M, &N);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d ", &A[i], &B[i], &C[i], &D[i]);
		count[i] = 0;
	}
	m = 0;
	reg[m] = '\0';
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d ", &X, &Y, &Z);
		for (int j = 0; j < M; j++) {
			v = A[j]*X + B[j]*Y + C[j]*Z;
			if (v < D[j]) {
				reg[j] = '1';
			} else if (v > D[j]) {
				reg[j] = '2';
			} else {
				reg[j] = '0';
			}
		}
		str = reg;
		map_[str]++;
	}

	for (auto it = map_.begin(); it != map_.end(); ++it) {
		if (it->second > m) {
			m = it->second;
		}
	}
	printf("%d\n", m);
	return 0;
}