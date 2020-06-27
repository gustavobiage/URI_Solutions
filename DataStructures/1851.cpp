#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>

#define LLU long long unsigned int 

using namespace std;

struct dragon {
	LLU t;
	LLU f;
	LLU index;
};

struct cmp {
	bool operator()(const struct dragon& a, const struct dragon& b) {
		double v1 = (double) a.t / a.f;
		double v2 = (double) b.t / b.f;
		return v1 > v2;
	}
};

priority_queue<struct dragon, vector<struct dragon>, struct cmp> pq;
struct dragon D[100001];

LLU sum;
struct dragon p;
LLU f, t, i;
int T;

int main() {
	sum = 0;
	int pointer = 0;
	i = 0;
	while (scanf("%Lu %Lu ", &t, &f) != EOF) {
		D[pointer].f = f;
		D[pointer].t = t;
		D[pointer].index = i++;
		pointer++;
	}
	int index = 0;
	t = T = 0;
	while (index < pointer) {
		pq.push(D[index]);
		index++;
		
		if (!t) {
			p = pq.top();
			pq.pop();
			f = p.f;
			t = p.t;
			i = p.index;
			sum += f*(T-i);
		}
		
		t--;
		T++;
	}

	T += t;

	while (!pq.empty()) {
		p = pq.top();
		pq.pop();
		f = p.f;
		t = p.t;
		i = p.index;
		sum += f*(T-i);
		T += t;
	}

	printf("%Ld\n", sum);
	return 0;
}