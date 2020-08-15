#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

// The point is to avoid computing pointless operations, in the example case:
// 
// 3 3 5
// L 2
// L 3 <-- This operation is useless
// C 1
// L 3 <---------------because we also do this operations 
// C 3

struct oper {
	int t;
	char o;
	int w;
};

char lineOper[1001];
char colOper[1001];
char opers[500001];
int ws[500001];
int ts[500001];

int n, m;
int k, w;
char op;

int arr[1001][1001];
int cnt[5];
int turn;

int v[] = {1, 2, 3, 4};
stack<struct oper> s_;
struct oper sop;

int main() {
	scanf("%d %d %d ", &n, &m, &k);
	memset(lineOper, 0, n+1);
	memset(colOper, 0, m+1);
	turn = 0;
	for (int i = 0; i < k; i++) {
		scanf("%c %d ", &opers[i], &ws[i]);
		ts[i] = turn;
		turn = (turn + 1) % 4;
	}
	for (int i = k-1; i >= 0; i--) {
		op = opers[i];
		turn = ts[i];
		w = ws[i];
		if (op == 'L' && !lineOper[w]) {
			sop.t = turn;
			sop.o = 'L';
			sop.w = w;
			lineOper[w] = 1;
			s_.push(sop);
		} else if (op == 'C' && !colOper[w]) {
			sop.t = turn;
			sop.o = 'C';
			sop.w = w;
			colOper[w] = 1;
			s_.push(sop);
		}
	}

	while (!s_.empty()) {
		sop = s_.top();
		s_.pop();
		w = sop.w;
		op = sop.o;
		turn = sop.t;
		if (op == 'L') {
			for (int j = 1; j <= m; j++) {
				cnt[arr[w][j]]--;
				cnt[v[turn]]++;
				arr[w][j] = v[turn];
			}
		} else {
			for (int j = 1; j <= n; j++) {
				cnt[arr[j][w]]--;
				cnt[v[turn]]++;
				arr[j][w] = v[turn];
			}
		}
	}
	printf("R%d H%d C%d P%d\n", cnt[v[0]], cnt[v[1]], cnt[v[2]], cnt[v[3]]);
	return 0;
}