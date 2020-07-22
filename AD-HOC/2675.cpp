#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

int N;
stack<int> stack_;
long long int sum;
int v;

void clear_stack() {
	stack<int> empty;
	stack_.swap(empty);
}

int main() {
	while (scanf("%d ", &N) != EOF) {
		clear_stack();
		sum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			while (!stack_.empty() && stack_.top() > v) {
				sum += stack_.top();
				stack_.pop();
			}
			stack_.push(v);
		}
		printf("%Ld\n", sum);
	}
	
	return 0;
}