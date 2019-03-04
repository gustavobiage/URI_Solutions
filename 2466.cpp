#include <stdlib.h>
#include <stdio.h>
//Sinunca
//Problem id: 2466
//AD-HOC
//Complexity: O(n^2) where N is the size of the first row.

int n;
int array[66][66];

int main() {

	scanf("%d ", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d ", &array[1][i]);
	}

	//Because the index is a integer, our rows will be shifted to the left
	for(int i = 1; i < n; i++) {
		//We are calculating the row of i + 1
		for(int j = 1; j <= n - i; j++) {
			//the function f(i, j) = array[i][j] * array[i][j+1], will always return the right answer
			//note that the value of the j-th ball of the (i+1)-th row takes in consideration the j-th ball and the (j+1)-th ball of the i-th row
			array[i+1][j] = array[i][j] * array[i][j+1];
		}
		
	}

	//now we just take the consideration the last ball added, wich was the array[n][1]
	if(array[n][1] == 1) {
		printf("preta\n");
	} else {
		printf("branca\n");
	}

	return 0;
}