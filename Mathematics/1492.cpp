#include <stdlib.h>
#include <stdio.h>
  
long long unsigned countSetBits(long long unsigned n) { 
    n++; 
  
    long long unsigned powerOf2 = 2; 
    long long unsigned cnt = n / 2; 
  	long long unsigned totalPairs;

    while (powerOf2 <= n) {
        totalPairs = n / powerOf2;
        cnt += (totalPairs / 2) * powerOf2;
        cnt += (totalPairs & 1) ? (n % powerOf2) : 0;
        powerOf2 <<= 1; 
    } 
  
    return cnt; 
} 

long long unsigned begin, end;
long long unsigned A, B;
int main() {
	
	while (scanf("%Lu %Lu ", &A, &B) != EOF) {
		begin = countSetBits(A-1);
		end = countSetBits(B);
		printf("%Lu\n", end - begin);
	}

	return 0;
}

// Reference
// https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n-set-2/?ref=rp