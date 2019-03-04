#include <stdlib.h>
#include <stdio.h>
//Pouca Frequência 
//Problem id: 1277
//String
//Complexity: O(N*M) where N is the amount of students and M is the lenght of the "registros de frequência"
// Altough we dont know the size of M

int t;
int n;
char nome[52][102];
char pres[102];

int len, count;
int a, p;

int first;

int main() {

	scanf("%d ", &t);

	while(t > 0) {

		scanf("%d ", &n);
		for(int i = 1; i <= n; i++) {
			scanf(" %s ", nome[i]);
		}

		first = 1;
		//We will solve this in a pretty standart way, like AD-HOC, just go with the logic
		for(int i = 1; i <= n; i++) {
			scanf(" %s ", pres);
			//The only thing you should note is that we are computing the answer "online"
			//, it means that besides the name we dont save the asnwer, but we print it
			len = 0;
			count = 0;

			for(int j = 0; pres[j] != '\0'; j++) {
				//Because "M" means that we should not take in consideration, we skip it
				if(pres[j] == 'M') continue;

				//if its not "M" then we should update the lenght of the semester, meaning that there was 1 more class
				len++;
				//and if the student was present, we add 1 presence
				if(pres[j] == 'P') count++;
			}

			//now, if the presence devided by the amount of classes is lower then 0.75
			//then, we print the name
			if((double)count/(double)len < 0.75) {
				//because we are doing it "online" we need to keep track of the first print to get the spaces right.
				if(first) {
					printf("%s", nome[i]);
				} else {
					printf(" %s", nome[i]);
				}

				first = 0;
			}
		}
		//and we dont forget to break the line after each test case
		printf("\n");
		t--;
	}
	return 0;
}