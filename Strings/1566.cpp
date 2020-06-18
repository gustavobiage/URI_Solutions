#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <vector>

unsigned char bucket[10][3000000];
int size[10];
unsigned char arr[3000000];
std::vector<std::pair<int, int> > * vec;
std::vector<std::pair<int, int> > * vec2;
std::vector<std::pair<int, int> > * aux;
int T, N, v;

void sort(int begin, int end, int div) {
	int dig;
	for (int i = 0; i < 10; i++) {
		size[i] = 0;
	}

	for (int i = begin; i <= end; i++) {
		dig = (arr[i]/div)%10;
		bucket[dig][size[dig]++] = arr[i];
	}
	int pointer = begin;
	int begin_pointer;
	for (int i = 0; i < 10; i++) {
		begin_pointer = pointer;
		for (int j = 0; j < size[i]; j++) {
			arr[pointer++] = bucket[i][j];
		}
		if (begin_pointer != pointer)
		vec2->push_back(std::make_pair(begin_pointer, pointer-1));
	}
}

int main() {
	vec = new std::vector<std::pair<int, int> >;
	vec2 = new std::vector<std::pair<int, int> >;

	scanf("%d ", &T);
	while (T) {
		scanf("%d ", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			arr[i] = (unsigned char) v;
		}
		vec->clear();
		vec->push_back(std::make_pair(0, N-1));
		for (int div = 100; div > 0; div = div / 10) {
			vec2->clear();
			for (int i = 0; i < vec->size(); i++) {
				sort((*vec)[i].first, (*vec)[i].second, div);
			}
			aux = vec;
			vec = vec2;
			vec2 = aux;
		}
		int f = 1;
		for (int i = 0; i < N; i++) {
			if (f) {
				printf("%u", (unsigned) arr[i]);
				f = 0;
			} else {
				printf(" %u", (unsigned) arr[i]);
			}
		}
		printf("\n");
		T--;
	}
}

// Reference
//	https://www.geeksforgeeks.org/radix-sort/