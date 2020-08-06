#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char arr[1001][1001];
int pi[1001];
int r, f;

map<int, int> cnt;
vector<int> vec;

int leaf(int n) {
	if (pi[n] == n) {
		return n;
	}
	int aux = leaf(pi[n]);
	pi[n] = aux;
	return aux;
}

void merge(int a, int b) {
	int la = leaf(a);
	int lb = leaf(b);
	if (la == lb) {
		return;
	}
	if (la > lb) {
		pi[la] = lb;
	} else {
		pi[lb] = la;
	}
}

int main() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s ", arr[i]);
		pi[i] = i;
	}
	r = 1;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (arr[i][j] == 'S' || arr[j][i] == 'S') {
				merge(i, j);
			}
		}
	}
	int li, lj;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			li = leaf(i);
			lj = leaf(j);
			if (arr[i][j] == 'S' && li != lj || arr[i][j] == 'D' && li == lj) {
				r = 0;
				goto END;
			}	
		}
	}
	END:;
	if (r) {
		cnt.clear();
		vec.clear();
		for (int i = 0; i < N; i++) {
			cnt[leaf(i)]++;
		}
		for (auto it = cnt.begin(); it != cnt.end(); ++it) {
			vec.push_back(it->second);
		}
		sort(vec.begin(), vec.end());
		printf("%d\n", (int) vec.size());
		f = 1;
		for (int i = vec.size()-1; i >= 0; i--) {
			if (f) {
				printf("%d", vec[i]);
				f = 0;
			} else {
				printf(" %d", vec[i]);
			}
		}
		printf("\n");
	} else {
		printf("-1\n");
	}
	return 0;
}