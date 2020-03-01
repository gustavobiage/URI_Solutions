#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//Feel free to test the time
// #include <time.h>

//Quadros Alienígenas
//Problem id: 2921
//Paradigmas
//Complexity: O(N^3) where N is the length and the width of your matrix

int n;

int matrix[1003][1003];
int array[1003];

long long int max_so_far, max_ending_here;
long long int max;
long long int INF = 10000000001;

int main() {
	
	// int begin = clock();
	
	while(scanf("%d ", &n) != EOF) {
		
		//we set the max to be negative infinit
		max = INF*(-1);

		//then we scan the value of our table
		for(int l = 1; l <= n; l++) {
			for(int r = 1; r <= n; r++) {
				scanf("%d ", &matrix[l][r]);
			}
		}

		//now we apply the two dimentional vertion of kanade algorithm
		//research for further understading
		for(int l = 1; l <= n; l++) {
			
			for(int i = 1; i <= n; i++) {
				array[i] = 0;
			}

			for(int r = 0; l + r <= n; r++) {
				for(int i = 1; i <= n; i++) {
					array[i] += matrix[i][l+r];
				}
				
				max_ending_here = INF*(-1);
				max_so_far = INF*(-1);

				for(int i = 1; i <= n; i++) {
					max_ending_here = fmax(array[i], max_ending_here + array[i]);
					max_so_far = fmax(max_so_far, max_ending_here);
				}

				if(max_so_far > max) {
					max = max_so_far;
				}
			}
		}

		//and we print the max value obtained
		printf("%Ld\n", max);

	}
	
	return 0;
}