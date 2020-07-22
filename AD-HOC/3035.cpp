#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <utility>
#include <set>

int N;
std::map<std::string, std::vector<std::pair<std::string, int>>> adj;
std::map<std::string, int> price;
std::set<std::string> min;
int c;
char n1[100000], n2[100000];
std::string str1, str2;

void connect(std::string & a, std::string  & b, int c) {
	std::vector<std::pair<std::string, int>> empty;
	if (adj.find(b) == adj.end()) {
		adj[b] = empty;
	}
	adj[b].push_back(std::make_pair(a, c));
}

void update(std::string & name, int amnt, int p) {
	price[name] += p*amnt;
	std::vector<std::pair<std::string, int>> aux;
	aux = adj[name];
	for (int i = 0; i < aux.size(); i++) {
		update(aux[i].first, aux[i].second, p*amnt);
	}
}

int main() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %d ", n1, &c);
		price[n1] = c;
		min.insert(n1);
	}
	while (scanf("%s %s %d ", n1, n2, &c) != EOF) {
		str1 = n1;
		str2 = n2;
		connect(str1, str2, c);
	}
	std::vector<std::pair<std::string, int>> aux;
	for (auto it = min.begin(); it != min.end(); ++it) {
		aux = adj[*it];
		int p = price[*it];
		for (int i = 0; i < aux.size(); i++) {
			update(aux[i].first, aux[i].second, p);
		}
	}
	for (auto it = price.begin(); it != price.end(); ++it) {
		if (min.find(it->first) == min.end()) {
			printf("%s %d\n", it->first.c_str(), it->second);
		}
	}
	return 0;
}