#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

int N, M;
int arr[65];
int DP[65];
set<int> possibleMax;
int amnt;
char c[5];
int maxv, cnt;

int getValue(char * c) {
	switch (c[0]) {
		case 'A': return 1;
		case 'J': return 11;
		case 'Q': return 12;
		case 'K': return 13;
	}
	if (!strcmp(c, "10")) {
		return 10;
	}
	return c[0] - '0';
}

int getMaxSum() {
	int max = 0;
	for (int i = 0; i < M; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void search() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			possibleMax.insert(DP[j] - DP[i-1]);
		}
	}
}

int main() {
	scanf("%d %d ", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%s ", c);
		arr[i] = getValue(c);
	}
	DP[0] = 0;
	for (int i = 1; i <= N; i++) {
		DP[i] = DP[i-1] + arr[i];
	}
	search();
	for (auto it = possibleMax.begin(); it != possibleMax.end(); ++it) {
		maxv = *it;
		cnt = 0;
		int s = 0;
		int amnt = 0;
		int p = 1;
		for (int i = 1; i <= N; i++) {
			if (s + arr[i] <= maxv) {
				s += arr[i];
				amnt++;
			} else {
				p++;
				s = arr[i];
				amnt = 1;
			}
			if (amnt > cnt) {
				cnt = amnt;
			}
		}
		if (p == M) {
			printf("%d %d\n", cnt, maxv);
			break;
		}
	}
	return 0;
}