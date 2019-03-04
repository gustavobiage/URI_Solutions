#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
//O Elfo das Trevas
//Problem id: 1766
//Estruturas e Bibliotecas
//Complexity: O(N) 
// As far as i know, every sort ends up being O(N) in the worst case cenario.

int t, T;;
int n, m;

struct rena{
	char nome[102];
	int peso;
	int idade;
	double  alt;
};

std::vector<struct rena> vec;

struct rena r;

//I had to spend some time debuging this problem
//because the comapre function used in the sort must return a bool
//,  and i was used to the compare function in the qsort, that returns an integer meaning the diference between the value
//So that is something you should note
bool compare (struct rena a, struct rena b) {
	
	//I left my old code commented so you dont make the same mistake I made.

	// if(b.peso != a.peso) {
		// return b.peso - a.peso; 
	// } else if(b.idade != a.idade) {
	// 	return b.idade - a.idade; 
	// } else if(b.alt != a.alt) {
	// 	return b.alt - a.alt; 
	// } else {
	// 	return ((int)(b.nome[0]) - (int)(a.nome[0])); 
	// }


	if(a.peso != b.peso) return b.peso < a.peso;
	// if(b.peso > a.peso) return -1;

	if(a.idade != b.idade) return a.idade < b.idade;
	// if(b.idade > a.idade) return -1;

	if(a. alt != b.alt) return a.alt < b.alt;
	// if(b.alt > a.alt) return -1;

	if((int)(a.nome[0]) != (int)(b.nome[0])) return ((int)(a.nome[0]) < (int)(b.nome[0]));
	// if((int)b.nome[0] > (int)a.nome[0]) return -1;

	return 0;

	// return 1;
	return b.peso < a.peso;
}

int main() {
	

	scanf("%d ", &t);
	T = t;

	while(t > 0) {
		vec.clear();

		scanf("%d %d ", &n, &m);

		//Now that we have our compare function all set we can use a "struct" to save our variables
		for(int i = 1; i <= n; i++) {
			scanf(" %s ", r.nome);
			scanf("%d ", &r.peso);
			scanf("%d ", &r.idade);
			scanf("%lf ", &r.alt);

			vec.push_back(r);
		}


		//And then sort it based in that function
		std::sort(vec.begin(), vec.end(), compare);
		//look in the documentation for better undestanding of sort with non-stadart compare function 
		printf("CENARIO {%d}\n", T-t + 1);

		//And now we just print the values
		for(int i = 0; i < m; i++) {
			printf("%d - %s\n", i+1, vec[i].nome);
		}

		t--;
	}

	return 0;
}