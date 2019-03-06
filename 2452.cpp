#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <set>
#include <math.h>

//Semente
//Problem id: 2452
//AD-HOC
//Complexity: O(N*M) where N is the amount of drops you have and N is the size of the "fita"

int fita[100004];
int F, R;
int x;
int a, b;

std::set<std::pair<int, int>> set;
std::pair<int, int> pair;

std::set<std::pair<int, int>>::iterator it;
std::set<std::pair<int, int>>::iterator compare;

//This merge function merges 2 drops that should became one
void merge() {

	for(it = set.begin(); it != set.end(); ++it) {
		for(compare = set.upper_bound(*it); compare != set.end() && compare->first <= it->second+1; ++compare) {
			if(compare->first <= it->second + 1) {
				pair = std::make_pair(it->first, compare->second);
				set.erase(*it);
				set.erase(*compare);
				set.insert(pair);
				it = set.lower_bound(pair);
			}
		}
	
	}
}
int main() {

	scanf("%d %d ", &F, &R);

	for(int i = 0; i < R; i++) {
		scanf("%d ", &x);
		//We save in a set the beggining and end of the drop
		//because in the beggining it has lenght 0 then our initial pair is (x, x)
		pair = std::make_pair(x, x);
		set.insert(pair);
	}

	int time;
	merge();
	time = 0;

	//Because we save each drop in a set, and we want it to take over all the positions,
	//So we should stop merging and growing when we have only one big drop that has the lenght of the "tape"
	//meaning it goes from 1 to "F"

	//	(int)set.size() != 1 means we have multiple drops
	//	set.begin()->first != 1 means that the beggining of the drop is not the beggining of the tape
	//	set.begin()->second != F means that the end of the drop is not the end of the tape
	while((int)set.size() != 1 || set.begin()->first != 1 || set.begin()->second != F) {
		
		time++;

		//This is growing:
		//	we take each begginning and decrease by one and take each end and increase by one
		for(it = set.begin(); it != set.end(); ++it) {
			//Because we dont want the beggin of the drop to go deeper then 1 we use max
			pair.first = fmax(it->first-1, 1);
			//And because we dont want the end to increase over "F" we take the min
			pair.second = fmin(it->second+1, F);

			//I had trouble edditing the pair in the set, so I just erased and added it again
			//I could be done better.
			set.erase(*it);
			set.insert(pair);
			it = set.lower_bound(pair);
		}

		//And after each grown we have to see if some drops need to be merged
		merge();
	}

	//After each iteration we increased the time, and now we just print it
	printf("%d\n", time);
	return 0;
}