#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Criptografia
//Problem id: 1024
//Strings
//Complexity: O(N*M) where N is the amount of words and M is the lenght of the word


char line[1003];
int n;

/*
	"Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas devem ser deslocadas 
	3 posições para a direita, segundo a tabela ASCII:"
*/

void run_one() {

	for(int i = 0; line[i] != '\0'; i++) {
		//If its a low cap letter or a high cap latter
		//Then we add 3 to its ascII table value
		//Note that we are using mod 256 so we dont break the max value that a char can represent as an integer
		if((int)line[i] >= 65 && (int)line[i] <= 90 || (int)line[i] >= 97 && (int)line[i] <= 122) {
			line[i] = (char)( (int)line[i] + 3)%256;
		}
	}
}
/*
	"Na segunda passada, a linha deverá ser invertida."
*/

//What we are doing is reversing in another array and them using the strcpy function to copy the string back to our original array
//The copy part happens with: strpcy(line, line_reverse);
void run_two() {
	char line_reverse[1003];
	int i;
	for(i = 0; line[i] != '\0'; i++) {
		line_reverse[i] = line[strlen(line)-1-i];
	}
	//Note that because we reversed it manually we haven't added a '\0' at the end
	//And most <string.h> functions need that final, end of string, char
	line_reverse[i] = '\0';
	strcpy(line, line_reverse);
}

/*
	"Na terceira e última passada, todo e qualquer caractere a partir da metade em diante (truncada) devem ser
	deslocados uma posição para a esquerda na tabela ASCII."
*/

void run_tree() {
	//We calculate the middle based on the lenght
	int mid = strlen(line)/2;
	//and because our array start at index 0 then we need to decrease the variables`s value by one
	mid--;

	for(int i = 0; line[i] != '\0'; i++) {
		//If line[i] belongs to the second half
		//Then decrease its integer value by 1
		//We also use mod 256 so we don't break the min value a char can have as an integer
		//Because mod in programming does not work as it does in litterature books for negative values
		//, instead of decreasing one we are adding 255 and applying mod
		if(i > mid) {
			line[i] = (char)(((int)line[i] + 255)%256);
		}
	}
}


int main () {

	scanf("%d ", &n);

	while(n > 0) {

		scanf(" %[^\n]",line);
		//To get the solution to the problem all we need is to scan the line and make the runs
		run_one();
		run_two();
		run_tree();

		//and the result is save on the initial line variable
		//So, just print it
		printf("%s\n", line);
		n--;
	}
	return 0;
}