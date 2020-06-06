#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int N;
int x, y, z;

struct block {
	int x;
	int y;
	int z;
};

vector<struct block> b1, b2;

int main() {
	struct block block;

	scanf("%d ", &N);
	while (N) {
		b1.clear();
		b2.clear();
		
		scanf("%d %d %d ", &x, &y, &z);
		block.x = x; block.y = y; block.z = z;
		b1.push_back(block);
		block.x = y; block.y = x; block.z = z;
		b1.push_back(block);
		block.x = z; block.y = y; block.z = x;
		b1.push_back(block);
		block.x = x; block.y = z; block.z = y;
		b1.push_back(block);
		block.x = z; block.y = x; block.z = y;
		b1.push_back(block);
		block.x = y; block.y = z; block.z = x;
		b1.push_back(block);

		scanf("%d %d %d ", &x, &y, &z);
		block.x = x; block.y = y; block.z = z;
		b2.push_back(block);
		block.x = y; block.y = x; block.z = z;
		b2.push_back(block);
		block.x = z; block.y = y; block.z = x;
		b2.push_back(block);
		block.x = x; block.y = z; block.z = y;
		b2.push_back(block);
		block.x = z; block.y = x; block.z = y;
		b2.push_back(block);
		block.x = y; block.y = z; block.z = x;
		b2.push_back(block);
		int r1, r2;
		r1 = r2 = 0;
		for (int i = 0; i < b1.size(); i++) {
			for (int j = 0; j < b2.size(); j++) {
				if (b1[i].x > b2[j].x && b1[i].y > b2[j].y) {
					r1 = 1;
				}

				if (b1[i].x < b2[j].x && b1[i].y < b2[j].y) {
					r2 = 1;
				}
			}
		}

		if (r1 && r2) {
			printf("3\n");
		} else if (r1) {
			printf("2\n");
		} else if (r2) {
			printf("1\n");
		} else {
			printf("0\n");
		}

		N--;
	}
	return 0;
}