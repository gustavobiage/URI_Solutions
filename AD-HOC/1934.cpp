#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <string.h>

using namespace std;

#define VARIABLE 0
#define CONSTANT 1

#define FAIL 0
#define CONTINUE 1

struct equation {
	map<string, int> var_counter;
	double left_value;
	double right_value;
};

int L, C;

map<string, int> res;
map<string, set<int> > m;

struct equation list[204];
char var[102][102][1000];
set<int> empty;
set<int> * pointer;

int aux[102];

int value[204];
int counter[204];

set<int> s;

void solve() {
	int v;
	double sol, rv, lv;
	map<string, int>::iterator i;
	string str;
	int qtd;
	int u;
	for (auto it = s.begin(); it != s.end(); ++it) {
		v = *it;
		i = list[v].var_counter.begin();
		if (list[v].var_counter.size() == 1) {
			str = i->first;
			qtd = i->second;
			rv = list[v].right_value;
			lv = list[v].left_value;
			sol = (double) (rv - lv) / qtd; 
			pointer = &m[str];
			res[str] = sol;
			for (auto j = pointer->begin(); j != pointer->end(); ++j) {
				u = *j;
				if (u == v) {
					continue;
				}
				list[u].left_value += list[u].var_counter[str] * sol;
				list[u].var_counter.erase(str);
			}
			s.erase(it);
			list[v].left_value = sol*qtd;
			list[v].var_counter.erase(i);
		}
	}
}

int main() {

	scanf("%d %d ", &L, &C);

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %s ", var[i][j]);
			if (m.find(var[i][j]) == m.end()) {
				m[var[i][j]] = empty; 
			}
			pointer = &m[var[i][j]];
			pointer->insert(i);
			pointer->insert(L + j);
		}
		scanf("%d ", &aux[i]);
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			list[i].var_counter[var[i][j]]++;
		}
		list[i].right_value = aux[i];
		list[i].left_value = 0;
	}
	
	for (int i = 0; i < C; i++) {
		scanf("%d ", &aux[i]);
	}

	for (int j = 0; j < C; j++) {
		for (int i = 0; i < L; i++) {
			list[L+j].var_counter[var[i][j]]++;
		}
		list[L+j].left_value = 0;
		list[L+j].right_value = aux[j];
	}

	for (int i = 0; i < L + C; i++) {
		s.insert(i);
	}

	int c = 0;
	while (c < L + C) {
		c++;
		solve();
	}

	for (auto it = res.begin(); it != res.end(); ++it) {
		printf("%s %d\n", it->first.c_str(), it->second);
	}

	return 0;
}