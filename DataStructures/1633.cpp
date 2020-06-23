#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> arr[100001];
int N, pointer;
long long unsigned int c, t;
priority_queue<pair<int, int>> q;
pair<int, int> p;

void clear_queue(priority_queue<pair<int, int>> * p) {
	priority_queue<pair<int, int>> empty;
	empty.swap(*p);
}

int main() {
	while (scanf("%d ", &N) != EOF) {
		clear_queue(&q);
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &arr[i].first, &arr[i].second);
		}
		sort(arr, arr + N);
		t = c = 0;
		pointer = 0;
		while (1) {
			while (pointer < N && arr[pointer].first <= t) {
				q.push(make_pair(-arr[pointer].second, arr[pointer].first));
				pointer++;
			}	
			
			if (q.empty() && pointer == N) {
				break;
			} else if (!q.empty()) {
				p = q.top();
				q.pop();
				c += t - p.second;
				t += -p.first;
			} else {
				t = arr[pointer].first;
			}
		}
		printf("%Lu\n", c);
	}

	return 0;
}