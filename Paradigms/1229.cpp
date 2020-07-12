#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct s {
	vector<struct s *> vec;
};

int N;
struct s ls1[10001], ls2[10001];
struct s *sortLs1[10001], *sortLs2[10001];
int a, b;

bool conections(struct s* s1, struct s* s2) {
	return s1->vec.size() < s2->vec.size();
}

bool nodes(struct s * s1, struct s * s2) {
	if (s1->vec.size() != s2->vec.size()) {
		return s1->vec.size() < s2->vec.size();
	}
	for (int i = 0; i < s1->vec.size(); i++) {
		if (s1->vec[i]->vec.size() != s2->vec[i]->vec.size()) {
			return s1->vec[i]->vec.size() < s2->vec[i]->vec.size();
		}
	}
	return 0;
}

int main() {
	while (scanf("%d ", &N) != EOF) {
		for (int i = 0; i <= N; i++) {
			ls1[i].vec.clear();
			ls2[i].vec.clear(); 
			sortLs1[i] = &ls1[i];
			sortLs2[i] = &ls2[i];
		}
		for (int i = 0; i < N-1; i++) {
			scanf("%d %d ", &a, &b);
			ls1[a].vec.push_back(&ls1[b]);
			ls1[b].vec.push_back(&ls1[a]);
		}
		for (int i = 0; i < N-1; i++) {
			scanf("%d %d ", &a, &b);
			ls2[a].vec.push_back(&ls2[b]);
			ls2[b].vec.push_back(&ls2[a]);
		}
		for (int i = 1; i <= N; i++) {
			sort(ls1[i].vec.begin(), ls1[i].vec.end(), conections);
			sort(ls2[i].vec.begin(), ls2[i].vec.end(), conections);
		}
		sort(&sortLs1[1], &sortLs1[1] + N, nodes);
		sort(&sortLs2[1], &sortLs2[1] + N, nodes);
		int ans = 1;
		for (int i = 1; i <= N; i++) {
			if (sortLs1[i]->vec.size() != sortLs2[i]->vec.size()) {
				ans = 0;
				break;
			}
			int l = sortLs1[i]->vec.size();
			for (int j = 0; j < l; j++) {
				if (sortLs1[i]->vec[j]->vec.size() != sortLs2[i]->vec[j]->vec.size()) {
					ans = 0;
					goto END;
				}
			}
		}

		END:;
		if (ans) {
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}