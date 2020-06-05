#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <set>
#include <queue>

//Submitted with C++ (g++ 4.8.5, -std=c++11 -O2 -lm)

int N, M;
std::map<int, std::set<int> > requirer;
std::map<int, std::set<int> > required_by;
std::set<int> empty;
std::priority_queue<int> pq;
std::queue<int> prt;
int a, b;

int main() {
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		requirer[i] = empty;
		required_by[i] = empty;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d ", &a, &b);
		requirer[b].insert(a);
		required_by[a].insert(b);
	}

	for (auto it = requirer.begin(); it != requirer.end(); ++it) {
		if (it->second.empty()) {
			pq.push(-it->first);
		}
	}
	int counter = 0;
	int u, v;
	std::set<int> * pointer, *pointer2;
	while (!pq.empty()) {
		u = -pq.top();
		pq.pop();
		counter++;
		prt.push(u);
		pointer = &required_by[u];
		for (auto it = pointer->begin(); it != pointer->end(); ++it) {
			v = *it;
			pointer2 = &requirer[v];
			pointer2->erase(u);
			if (pointer2->size() == 0) {
				pq.push(-v);
			}
		}
	}

	if (counter == N) {
		while (!prt.empty()) {
			printf("%d\n", prt.front());
			prt.pop();
		}
	} else {
		printf("*\n");
	}
	return 0;
}