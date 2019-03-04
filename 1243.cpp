#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
//O Quão Fácil é...
//Problem id: 1243
//String
//Complexity: O(N) where N is the size of the title

char title[1000];
char delim[] = " ";
int n, sum, not_a_word;
std::vector<int> vec;
int count;

int main() {
	
	//We used fgets instead of scanf because in uDebug there are some examples that the input could be a blank line("\n")
	//and scanf has trouble dealing with that

	// while(scanf(" %[^\n]\n", title) != EOF) {
	while(fgets(title, 100, stdin) != NULL) {
		

		vec.clear();
		//because strtok() will add '\0' inside the char array the fuction strlen() wont work anymore, so we need to save the lenght now
		n = strlen(title);

		//We decided to use the strtok function from <string.h> as a "split"
		char* pointer = strtok(title, delim);
		//strtok returns null when it cant find the the parameters
		//note that delim is equal " ".
		while(pointer != NULL) {
			pointer = strtok(NULL, delim);
		}

		//now we can run throught the words and see wich ones are valid
		for(int i = 0; i <= n; i++) {
			sum = 0;
			not_a_word = 0;

			for(; title[i] != '\0' && title[i] != ' '; i++) {
				if(int(title[i]) >= 65 && (int)title[i] <= 90 || (int) title[i] >= 97 && (int)title[i] <= 122) {
					sum++;
				} else {
					//because we used fgets the last char before '\0' is a '\n'(line break)
					//so to see if the final dot is valid we need to check if title[i+1] == '\n'
					if(title[i] == '.' && title[i+1] == '\0' || title[i] == '.' && title[i+1] == '\n') {
						break;
					} else if(title[i] != '\n') {
						//this means the word is not valid and should not be taken in consideration
						not_a_word = 1;
					}
				}
				
			}
			
			//if the word is valid we add the sum to the vector
			//checking for sum != 0 will stop from double spaces being counted as words("  ")
			if(!not_a_word && sum != 0) {
				vec.push_back(sum);
			}
		}

		//count the total of letters in each valid word
		sum = 0;
		for(int i = 0; i < vec.size(); i++) {
			sum += vec[i];
		}

		if(vec.size() != 0) {
			//it was not clear in the problem but we need to compare the floor of the average, so we use an int variable instead of a double
			int x = (double)sum/((double)vec.size());

			if(x <= 3) {
				printf("250\n");
			} else if(x <= 5) {
				printf("500\n");
			} else {
				printf("1000\n");
			}
		} else {
			//this will just stop us from dividing by 0
			printf("250\n");
		}
		
	}
	return 0;
}