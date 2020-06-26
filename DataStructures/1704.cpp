#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <utility>
#include <string.h>

#define OCUPIED 1
#define FREE 0

using namespace std;

struct p {
	int status;
	struct p * next;
};

priority_queue<pair<int, int>> pq;
int N, H;
int v, t;
pair<int, int> p;
long long int total, V;
struct p arr[1001];

void clear_queue(priority_queue<pair<int, int> > * pq) {
	priority_queue<pair<int, int> > empty;
	empty.swap(*pq);
}

struct p * getFree(struct p * p) {
	if (p == NULL || p->status == FREE) {
		return p;
	}
	struct p * aux = getFree(p->next);
	p->next = aux; 
	return aux;
}

int main() {

	while (scanf("%d %d ", &N, &H) != EOF) {
		clear_queue(&pq);
		arr[0].status = FREE;
		arr[0].next = NULL;
		for (int i = 1; i <= H; i++) {
			arr[i].status = FREE;
			arr[i].next = &arr[i-1];
		}
		total = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &v, &t);
			total += v;
			pq.push(make_pair(v, t));
		}
		
		int h = 0;
		V = 0;
		struct p * pointer;
		for (int i = 0; i < N && h <= H; i++) {
			p = pq.top();
			pq.pop();
			t = p.second;
			v = p.first;
			pointer = getFree(&arr[t-1]);
			if (pointer != NULL) {
				pointer->status = OCUPIED;
				V += v;
				h++;
			}
		}
		printf("%Ld\n", total-V);
	}
	return 0;
}