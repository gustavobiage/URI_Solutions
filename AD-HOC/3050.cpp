#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> vec;
int N, v;
long long dist, maxDistance;

int main() {
	scanf("%d ", &N);
	maxDistance = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d ", &v);
		for (int j = 0; j < vec.size(); j++) {
			dist = (long long int) vec[j] + v + (i-j);
			if (maxDistance < dist) {
				maxDistance = dist;
			}
		}
		vec.push_back(v);
	}
	printf("%Ld\n", maxDistance);
	return 0;
}