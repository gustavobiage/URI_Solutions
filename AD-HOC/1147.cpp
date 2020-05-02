#include <stdlib.h>
#include <stdio.h>
#include <utility>

using namespace std;

pair<int, int> getAttackPosition1(pair<int, int> * p) {
	return make_pair(p->first - 1, p->second + 1);
}

pair<int, int> getAttackPosition2(pair<int, int> * p) {
	return make_pair(p->first - 1, p->second - 1);
}

pair<int, int> arr[9];
int b; char c;
int index;
pair<int, int> h;
int res;

int test() {
	pair<int, int> p[8];
	pair<int, int> a, b;
	int counter = 0;

	p[0] = make_pair(h.first + 1, h.second + 2);
	p[1] = make_pair(h.first - 1, h.second + 2);
	p[2] = make_pair(h.first + 1, h.second - 2);
	p[3] = make_pair(h.first - 1, h.second - 2);
	p[4] = make_pair(h.first + 2, h.second + 1);
	p[5] = make_pair(h.first + 2, h.second - 1);
	p[6] = make_pair(h.first - 2, h.second + 1);
	p[7] = make_pair(h.first - 2, h.second - 1);

	int should_count = 0;
	for (int i = 0; i < 8; i++) {
		should_count = 1;
		for (int j = 0; j < 8; j++) {
			a = getAttackPosition1(&arr[j]);
			b = getAttackPosition2(&arr[j]);
			if (a == p[i] || b == p[i]) {
				should_count = 0;
				goto COUNT;
			}
		}
		COUNT:
		if (should_count &&
			p[i].first >= 0 && p[i].first < 8 &&
			p[i].second >= 0 && p[i].second < 8) {
			counter++;
		}
	}

	return counter;
}

int main() {
	int cc = 0;
	while (1) {
		scanf("%d", &b);
		if (b == 0) {
			break;
		}
		cc++;
		scanf("%c ", &c);
		h = make_pair(b - 1, c - 'a');
		index = 0;
		while (index < 8) {
			scanf("%d%c ", &b, &c);
			arr[index++] = make_pair(b - 1, c - 'a');
		}

		res = test();
		printf("Caso de Teste #%d: %d movimento(s).\n", cc, res);
	}

	return 0;
}