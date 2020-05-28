#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int N, C, M;
vector<int> vec;
int m, c;

int main() {
	c = 0;
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		c++;
		m = -1;
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &C, &M);
			if (M > m) {
				m = M;
				vec.clear();
				vec.push_back(C);
			} else if (M == m) {
				vec.push_back(C);
			}
		}
		printf("Turma %d\n", c);
		for (int i = 0; i < vec.size(); i++) {
			printf("%d ", vec[i]);
		}
		printf("\n\n");
	}
	return 0;
}