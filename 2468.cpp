#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <set>
#include <vector>
#include <map>
//Mapa
//Problem id: 2468
//AD-HOC
//Complexity: O(N) where N is the number of vertices in your graph

int n;
int a, b, c;
std::vector<std::pair<int, int>> vec;
std::pair<int, int> p;
long long int total;
std::map<int, int*> map;

std::vector<int> adj[100005];
int pos[100002];
int cor[100001];
int paint;

void search_visit(int u);


//THIS IS BASIC DFS SEARCH
//do your own research for deeper understanding

void search() {

	paint = 1;
	map[paint] = (int*) malloc(sizeof(int));
	*map[paint] = 0;

	for(int i = 1; i <= n; i++) {

		if(cor[i] != 0) continue;

		search_visit(i);
		paint++;
		map[paint] = (int*) malloc(sizeof(int));
		*map[paint] = 0;
	}

}

void search_visit(int u) {

	(*(map[paint])) += 1;
	cor[u] = paint;

	for(int i = 0; i < pos[u]; i++) {
		if(cor[adj[u][i]] != 0) continue;
		search_visit(adj[u][i]);
	}

}


int main() {

	scanf("%d ", &n);
	total = 0;

	//all the problem is asking you is the value of E, NOT what are the pairs that define E
	//also Note that because the value of "E" denoted in the problem can be huge
	//it becines impossible to save the values of each pair



	for(int i = 1; i <= n-1; i++) {
		scanf("%d %d %d ", &a, &b, &c);
	
		//To solve this problem we will only save the relations that are white (c = 0)
		//and you will undestand why
		if(!c) {
			adj[a].push_back(b);
			pos[a]++;

			adj[b].push_back(a);
			pos[b]++;
		} else {
			p = std::make_pair(a, b);
			vec.push_back(p);
		}
	}

	//Because the problem tells us that there is always a way to get from point B to point A, we dont really care aboult the blue relations
	//We will use DFS search in our WHITE ONLY graph to denote "families", these are group of vertices that are only conected by WHITE relations
	//and if you draw on a paper: if, I mean when, we find a BLUE realtion between two families then you will realize that every element in one family will have a pair with every ellement in the other family (that is equal to size_of_family_A * size_of_family_B amount of pairs)
	//but now we have to merge these two families.
	//And then apply the same principle until we have only one family left, that represents the whole graph
	search();
	int i;

	//i could be wrong, i tried implementing the merge function in a lot of different ways and the only way that got me the right answer every time was by always merging the same family with a diferent one
	//So dont merge, for example:
	//	family 1 merges with family 2
	//	family 3 merges with family 4
	//	family 1 merges with family 3
	//This happens to fail sometimes

	//Do instead:
	//	family 1 merges with family 2
	//	family 1 merges with family 3
	//	family 1 merges with family 4
	//

	map[0] = (int*) malloc(sizeof(int));
	//merge F1 with F2
	*map[0] = *map[1] + *map[2];

	for(int i = 1; i < paint; i++) {
		if(i > 2) {
			//add the F1 merge Fi to total
			total += *map[0] * *map[i];
			
			//merge F1 with Fi
			*map[0] += *map[i];
		} else if (i == 1) {
			total += *map[1] * *map[2];
			//add the F1 merge F2 pairs to total.
		}
	}

	//And if you add the amount of pairs you find before each merge you get the total where total = E
	printf("%Ld\n", total);

	return 0;
}