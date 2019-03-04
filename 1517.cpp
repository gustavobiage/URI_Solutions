#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
//Maçãs
//Problem id: 1517
//Paradigmas
//Complexity: O(N*N) where N is the amount of apple we have

int n, m, k;
int t[1001];
int x[1001];
int y[1001];

int dp[23][23][1003];
int count[1001];
int max_total;

std::vector<int> vec;

int find_max() {
	//the maximum amount of apple you can get finishing in a i-th apple
	//, is the maximum between the maximum amount of apples you can get from its predecessor + 1
	int max = -1;

	//count[i] contains the maximum amount of apples we can get finishing in the i-th apple
	//Note that we can only calculating the count[i] if we have already calculated every apple before i
	for(int i = 0; i < vec.size(); i++) {
		if(count[vec[i]] + 1 > max) {
			max = count[vec[i]] + 1;
		}
	}

	if(max != -1) return max;

	return 0;
}

int main() {

	scanf("%d %d %d ", &n, &m, &k);

	while(n != 0 || m != 0 || k != 0) {

		for(int i = 1; i <= k; i++) {
			scanf("%d %d %d ", &x[i], &y[i], &t[i]);
		}

		scanf("%d %d ", &x[0], &y[0]);

		
		
			for(int i = 1; i <= k; i++) {
				
			//Because we start a new search, we clear the vector of predecessors
			vec.clear();
			//if we can get the i-th apple from the starting position, then the stating position is also a possible predecessor
			//that is also the only way to try to calculate count[1] (count of one)
			if(fmax(abs(x[i] - x[0]), abs(y[i] - y[0])) <= t[i]) {
				vec.push_back(0);
			}

			//Now we go throught avery apple that came before i
			for(int j = i-1; j > 0; j--) {
				//and if we can reach the i-th apple from this j-th apple
				//then the j-th apple is a possible predecessor
				if(fmax(abs(x[i] - x[j]), abs(y[i] - y[j])) <= t[i]-t[j]) {
					//Therefore we insert it on the vector
					if(count[j] != 0) vec.push_back(j);
				}
			}
			//Now we just find the max
			count[i] = find_max();

		}
		

		
		//We have calculaterd the "count" of every apple, but that is only the value of the maximum amount of apple we can get finishing in that particular apple
		//But we dont know which appe is the last one
		max_total = -1;
		//So we go thought every one of then and pick the one that returns the mounst amount of appes
		for(int i = 0; i <= k; i++) {
			if(count[i] > max_total) max_total = count[i];
		}

		//And whatever apple was the last one, the maximum amount of apples we can get in this cenario is saved in max_total
		//So lets just print it	
		printf("%d\n", max_total);
		scanf("%d %d %d ", &n, &m, &k);	
	}


	return 0;
}