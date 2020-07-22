#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;

int C, N;
map<int, int> present;
map<int, int> install;
int a, b;

int main() {
	scanf("%d %d ", &C, &N);
	for (int i = 0; i < C; i++) {
		scanf("%d %d ", &a, &b);
		present[a] = b;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &a, &b);
		if (present.find(a) == present.end() || present[a] < b) {
			install[a] = b;
			present[a] = b;
		}
	}
	for (auto it = install.begin(); it != install.end(); ++it) {
		printf("%d %d\n", it->first, it->second);
	}
	return 0;
}