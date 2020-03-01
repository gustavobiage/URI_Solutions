#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string.h>

//Sentença Dançante 
//Problem id: 1234
//Strings
//Complexity: O(N) where N is the lenght of the sentence

char line[60];
int first;
int cap;

std::map<char, char> map;

int main() {

	//Here we initialize both alfabets so we can map low caps to high caps
	char alf_one[35] = "abcdefghijklmnopqrstuvxwyz";
	char alf_two[35] = "ABCDEFGHIJKLMNOPQRSTUVXWYZ";

	//And we map then with a for loop
	for(int i = 0; alf_one[i] != '\0'; i++) {
		map[alf_one[i]] = alf_two[i];
		map[alf_two[i]] = alf_one[i];
	}

	//We are using fgets instead of scanf because the sentece can start with spaces(" ")
	//and scanf have trouble dealling with that

	//With fgets instead of EOF, because it return NULL when theres is not anymore lines to read
	//we compare it with a NULL

	// while(scanf(" %[^\n]",line) != EOF) {
	while(fgets(line, 59, stdin) != NULL) {

		first = 1;

		for(int i = 0; i < strlen(line); i++) {
			//We skip spaces and chars that are not letters
			if(line[i] == ' ') continue;
			if(!((int)line[i] >= 97 && (int)line[i] <= 122 || (int)line[i] >= 65 && (int)line[i] <= 90)) continue;
			
			//Again, because it can start with spaces we are not sure that line[0] is the first letter
			//So we use a variable to denote the first char
			if(first) {
				if((int)line[i] >= 65 && (int)line[i] <= 90) {
					cap = 0;
				} else if((int)line[i] >= 97 && (int)line[i] <= 122) {
					//if its low cap then we make it high cap
					line[i] = map[line[i]];
					cap = 0;
				}
				first = 0;
			} else {
				//We use cap%2 to keep switching from low to high cap
				if(cap%2) {
					if((int)line[i] >= 97 && (int)line[i] <= 122) {
						//PASS
					} else {
						//This means that it should have been high cap
						line[i] = map[line[i]];
					}
				} else {
					if((int)line[i] >= 65 && (int)line[i] <= 90) {
						//PASS
					} else {
						//This means that it should have been low cap
						line[i] = map[line[i]];
					}
				}
			}

			//Because we only switch from low cap to high cap, or vice-versa, when we line[i] is an "acceptable" char
			//We only increment cap if it is an "acceptable" char
			if((int)line[i] >= 97 && (int)line[i] <= 122 || (int)line[i] >= 65 && (int)line[i] <= 90)
			cap++;

		}
		//re-print the line with the changes
		printf("%s", line);

	}


	return 0;
}