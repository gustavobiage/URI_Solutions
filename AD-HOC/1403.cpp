#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int N, M;
map<int, int> m;
vector<int> vec;
int v;
int max_, aux;

int main() {

	while (1) {
		scanf("%d %d ", &N, &M);
		
		if (N == 0 && M == 0) {
			break;
		}

		m.clear();
		vec.clear();
		max_ = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d ", &v);
				m[v]++;
				if (max_ < m[v]) {
					max_ = m[v];
				}
			}
		}

		aux = 0;
		for (auto it = m.begin(); it != m.end(); ++it) {
			if (it->second > aux && it->second != max_) {
				vec.clear();
				vec.push_back(it->first);
				aux = it->second;
			} else if (it->second == aux && it->second != max_) {
				vec.push_back(it->first);
			}
		}

		for (int i = 0; i < vec.size(); i++) {		
			printf("%d ", vec[i]);
		}
		printf("\n");
	}

	return 0;
}