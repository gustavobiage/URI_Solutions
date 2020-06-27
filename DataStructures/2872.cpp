#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int P;
priority_queue<int> pq;
char package[1000];

void clear_queue(priority_queue<int> * p) {
	priority_queue<int> empty;
	empty.swap(*p);
}

int main() {
	while (scanf("%*d ") != EOF) {
		clear_queue(&pq);
		while (1) {
			scanf("%s ", package);
			if (strcmp(package, "0") == 0) {
				break;
			}
			scanf("%d ", &P);
			pq.push(-P);
		}
		while (!pq.empty()) {
			printf("Package %.3d\n", -pq.top());
			pq.pop();
		}
		printf("\n");
	}
	return 0;
}