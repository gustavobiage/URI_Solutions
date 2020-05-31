#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>

//Submitted with C++(g++ 4.8.5)

int N;
std::vector<int> empty;
std::map<int, std::vector<int>> m;
std::set<int> c;
int v, x, y;

void add(int a, int b) {
	if (m.find(a) == m.end()) {
		m[a] = empty;
	}
	m[a].push_back(b);
}

void search(int s) {
	c.insert(s);
	std::vector<int> * pointer;
	pointer = &m[s];
	for (int i = 0; i < pointer->size(); i++) {
		v =  (*pointer)[i];
		if (c.find(v) == c.end()) {
			search((*pointer)[i]);
		}
	}
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		m.clear();
		for (int i = 0; i < N; i++) {
			scanf("(%d,%d) ", &x, &y);
			add(x, y);
			add(y, x);
		}
		c.clear();
		search(1);
		printf("%d\n", (int)c.size());
	}
	return 0;
}