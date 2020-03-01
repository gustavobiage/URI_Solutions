#include <stdlib.h>
#include <stdio.h>
#include <vector>
//Cidade no Centro
//Problem id: 2676
//Grafos
//Complexity: O(N^3) where N is the number of cities

int n, r;
int a, b, d;
int w[103][103][103];
int min, sum;
int INF = 20000000;
std::vector<int> res;

//this is the warshalls algorithm
//do some research for further understanding
void warshall() {

	int k, u, v;

	for(k = 1; k <= n; k++) {
		for(u = 1; u <= n; u++) {
			for(v = 1; v <= n; v++) {
				
				if(w[k-1][u][v] < w[k-1][u][k] + w[k-1][k][v]) {
					w[k][u][v] = w[k-1][u][v];
				} else {
					w[k][u][v] = w[k-1][u][k] + w[k-1][k][v];
				}
				
			}
		}
	}


}

int main() {

	scanf("%d %d ", &n, &r);


	while(n != 0 || r != 0) {

		//first we set every distance from i to j to inf
		//excpet the distances from i to i wich is 0
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i != j) {
					w[0][i][j] = INF;
				} else {
					w[0][i][j] = 0;
				}
			}
		}

		//scan distances
		for(int i = 1; i <= r; i++) {
			scanf("%d %d %d ", &a, &b, &d);
			//because there can be a distance from i to i that is not 0
			//we keep the minimum
			if(w[0][a][b] > d) {
				w[0][a][b] = d;
				w[0][b][a] = d;
			}
		}

		//this problem is realy simple we will use the warshall algorithm to find the distance from every Vertice to every other Vertice
		warshall();
		min = INF;

		//now we just sum the distances to every other vertice
		for(int i = 1; i <= n; i++) {
			sum = 0;
			for(int j = 1; j <= n; j++) {
				sum += w[n][i][j];
			}
			//if the sum is smaller then the min until now
			//we update the min and store the Vertice i
			if(min > sum) {
				res.clear();
				res.push_back(i);
				min = sum;
			} else if(min == sum) {
				//if it is the same distance then the min we push into the vector
				res.push_back(i);
			}
		}

		//now we just print every index from the vector
		//note that every index should be followed by a blank space, even the last one
		for(int i = 0; i < res.size(); i++) {
			printf("%d ", res[i]);
		}
		//and in the end we break the line
		printf("\n");

		scanf("%d %d ", &n, &r);
	}
	return 0;
}