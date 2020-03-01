#include <stdlib.h> 
#include <stdio.h>
//Cruzando Lagos
//Problem id: 2928
//AD-HOC
//Complexity: O(N) where N is the amount of lines in your map

int n;
char line[30];
int count;
int jumps;
int can;

int main () {

	//this is a begginers problem

	//we scan the mount of lines
	scanf("%d ", &n);

	//set counter, jumps to 0
	count = 0;
	jumps = 0;
	//for now we say that it is possible
	can = 1;

	for(int i = 0; i < n; i++) {
		//we will scan one line at a time and deal with that line
		scanf(" %s ", line);
		if(line[0] == '.') {
			//here we count the amount of lines that you would have to jump
			count++;
		} else if(line[0] == '-') {
			//here if we find land then we see if it was followed by water
			//if it was, counter > 0, then we add 1 jump
			if(count > 0) {
				jumps++;
			}
			//and say that from now it is not followed by watter
			count = 0;
		}

		//if for any reason we get 3 lines of water, then it is impossible to make the jump
		if(count > 2) {
			//we say that it is impossible
			can = 0;
		}

	}

	//if it is ended by a line of water we need to count 1 extra jump
	if(count > 0) {
		jumps++;
	}

	//if it is possible we print the amount of jumps
	//else we print "N"
	if(can == 1) {
		printf("%d\n", jumps);
	} else {
		printf("N\n");
	}

	return 0;
}