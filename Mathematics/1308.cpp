#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LLU long long unsigned

int T;
LLU N, res;
LLU amount;

void binary_search(LLU begin, LLU end, LLU value, LLU * var) {
	if (begin > end) {
		return;
	}

	LLU mid = begin + (end - begin) / 2;
	LLU v = (mid * (mid-1)) / 2;
	
	if (v > value) {
		binary_search(begin, mid-1, value, var);
	} else if (v < value) {
		if (mid > *var) {
			*var = mid;
		}
		binary_search(mid+1, end, value, var);
	} else if (v == value) {
		*var = mid;
	}
}

int main() {
	scanf("%d ", &T);
	while (T) {
		scanf("%Lu ", &N);
		res = 1;
		// END = Any number higher then the maximum answer
		binary_search(0, 1414213562, N, &res);
		printf("%Lu\n", res-1);
		T--;
	}

	return 0;
}