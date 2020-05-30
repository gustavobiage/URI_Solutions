#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

int a;
set<int> s;

int power(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++) {
		res = res * a;
	}
	return res;
}

int findNext(int n) {
	n = n * n;
	int mul = 1;
	int count = 0;
	int digit, val;
	val = n;
	while (n) {
		count++;
		digit = n % 10;
		n = n / 10;
	}

	val = val % power(10, 6);
	val = (val - val % power(10, 2)) / 100;
	
	if (s.find(val) != s.end()) {
		return 0;
	}
	
	s.insert(val);
	a = val;
	return 1;
}

int main() {
	while (1) {
		scanf("%d ", &a);
		if (!a) {
			break;
		}
		s.clear();
		s.insert(a);
		while (findNext(a));
		printf("%d\n", (int) s.size());
	}
	return 0;
}